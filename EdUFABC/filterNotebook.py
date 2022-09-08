'''
=====================================================================
Copyright (C) 2021 Francisco de Assis Zampirolli
from Federal University of ABC. All rights reserved.

filterNotebook is free: you can redistribute it and/or modify
it under the terms of the GNU General Public License
(gnu.org/licenses/gpl.txt) as published by the Free Software
Foundation, either version 3 of the License, or (at your option)
any later version.

filterNotebook is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
=====================================================================
'''

import codecs
import json
import os.path
import subprocess
import sys
import re
from itertools import combinations
from pathlib import Path

import glob

le = len(sys.argv)

Types = sorted(['py', 'js', 'java', 'c', 'cpp', 'r'])
Types = sorted(['c'])
Formats = ['html', 'slides', 'latex']  # 'markdown'

with open('./latex_begin.txt', 'r') as f:
    str_latex_begin = f.read()
str_latex_maketitle = """
\\clearpage\\maketitle
\\thispagestyle{empty}
\\tableofcontents
"""

permsTypes = []
for i in range(1, len(Types) + 1):
    genComb = combinations(Types, i)
    for subset in genComb:
        permsTypes.append(list(subset))

os.system('find . -name "Icon*" -type f -delete')


def genLatex(file_out):
    file_tex = file_out[:-6] + '.tex'
    file_aux = file_tex.split('/')[-1][:-4]
    path0 = './' + '/'.join([i for i in file_tex.split('/')[:-1]])
    with open(file_tex, 'r') as f_aux:
        str_f = f_aux.read()
    str_f = str_f.replace('\\title{', '%\\title{')
    str_f = str_f.replace('\\documentclass[11pt]{article}', str_latex_begin)
    str_f = str_f.replace('\\maketitle', str_latex_maketitle)
    str_f = str_f.replace('___X___', path0.split('.')[-1].upper())
    with open(file_tex, 'w') as writer:
        writer.writelines(str_f)

    cmd = ['pdflatex', '--shell-escape',
           '-interaction', 'nonstopmode', file_tex]
    proc = subprocess.Popen(cmd)
    proc.communicate()
    proc = subprocess.Popen(cmd)
    proc.communicate()
    os.system("mv " + file_aux + ".pdf " + path0)
    os.system("rm " + file_aux + ".*")


def genTypes(file, Type, format):
    y = json.loads(codecs.open(file, 'r').read())
    for k, x in enumerate(y['cells']):
        if x['cell_type'] in ['code', 'markdown']:
            aux = y['cells'][k]['source']
            if aux:
                reg = re.compile('\#\[' + '(\w+)' + '\]',
                                 re.IGNORECASE | re.DOTALL | re.MULTILINE)
                if set(Type).intersection(set(reg.findall(aux[0]))):
                    y['cells'][k]['source'] = aux[1:]  # remove first line
                elif len(reg.findall(aux[0])) > 0:
                    # remove code with another Type
                    y['cells'][k]['source'] = []

    for k, x in enumerate(y['cells']):
        if 'metadata' in x:
            y['cells'][k]['metadata'] = {}
        if 'outputs' in x:
            y['cells'][k]['outputs'] = []

    flag = True
    while flag:  # delete empty cells
        flag = False
        for k, x in enumerate(y['cells']):
            if not y['cells'][k]['source']:
                del y['cells'][k]
                flag = True

    try:
        os.mkdir('gen')
    except:
        pass
    tps = '+'.join([i for i in sorted(Type)])
    lenTps = '' if len(tps.split('+')) == 0 else str(len(tps.split('+')))
    lenTps += '.'
    try:
        os.mkdir('gen/' + lenTps + tps)
    except:
        pass
    file_out = 'gen/' + lenTps + tps + '/' + \
        file.split('/')[1][:-6] + "." + tps + ".ipynb"
    with open(file_out, encoding='utf-8', mode='w') as f:
        json.dump(y, f, indent=4)
    print('save: ' + file_out)

    if format == 'all':
        for ff in Formats:
            ss = "jupyter nbconvert " + file_out + " --to " + ff
            if ff == 'slides':
                ss += ' --reveal-prefix reveal.js'
            os.system(ss)
            if ff == 'latex':
                genLatex(file_out)

    elif format in Formats:
        ss = "jupyter nbconvert " + file_out + " --to " + format
        if format == 'slides':
            ss += ' --reveal-prefix reveal.js'
        os.system(ss)
        if format == 'latex':
            genLatex(file_out)

    elif not format == '':
        print('Format not yet defined: ' + format)


def genFiles(file, Type, format):
    if 'all' in Type:
        for t in permsTypes:
            genTypes(file, t, format)
    elif Type in Types:
        genTypes(file, [Type], format)
    elif '+' in Type:
        for t in Type.split('+'):
            if t not in Types:
                print('Type not yet defined: ' + t)
                return 0
        genTypes(file, Type.split('+'), format)
    else:
        print('Type not yet defined: ' + sys.argv[2])


if le < 3:
    print('''ERROR:
          syntax: python filterNotebook.py file type format
          file: example 'all/cap1.part2.lab.ipynb' or 'all'
          type: save:  'py', 'java', 'js', 'cpp', 'c', 'r' 
                or 'all' - one type for file type
                also: 'type1+type2+...' more one type for file. 
                eg. 'py+js' in alphabetic order
          format: empty, 'html', 'slides', 'latex', 'markdown' or 'all'
          ''')
else:
    if le == 3:
        format = ''
    else:
        format = sys.argv[3]
    if sys.argv[1] == 'all':
        for f in sorted(glob.glob("all/*.ipynb")):
            genFiles(f, sys.argv[2], format)
    elif os.path.isfile(sys.argv[1]):
        genFiles(sys.argv[1], sys.argv[2], format)
    else:
        print('File not yet defined: ' + sys.argv[2])

# Create books in gen/*/ALL.ipynb and gen/*/ALL.html
if le >= 3:
    if sys.argv[le - 1] == 'all':
        for path0 in sorted(glob.glob("gen/*")):
            tps = '+'.join([i for i in sorted(sys.argv[2].split('+'))])
            if sys.argv[2] != 'all':
                if not Path(path0).is_dir() or path0.split('.')[-1] != tps:
                    continue

            file_name = path0 + '/ALL.ipynb'

            try:
                print('rm ' + file_name)
                os.system('rm ' + file_name)
            except:
                pass
            ss = 'nbmerge ' + path0 + '/*.ipynb > ' + file_name
            os.system(ss)
            ss = "jupyter nbconvert " + file_name + ' --to html'
            os.system(ss)

            # to generate latex
            ss = "jupyter nbconvert " + file_name + ' --to latex'
            os.system(ss)

            genLatex(file_name)

# criar pastas para cada formato
for path0 in sorted(glob.glob("gen/*")):
    for path1 in sorted(glob.glob(path0+"/*")):
        f0, e0 = os.path.splitext(path1)
        for f in Formats + ['tex', 'pdf']:
            if '.'+f == e0:
                if '.slides.html' in path1:
                    f = 'slides'
                p = path1[:path1.rfind('/')]
                try:
                    os.mkdir(p+'/'+f)
                except:
                    pass
                os.system('mv '+path1 + ' ' + p+'/'+f)
                print('mv '+path1 + ' ' + p+'/'+f)

os.system('find . -name "Icon*" -type f -delete')
