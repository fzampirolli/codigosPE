# filterNotebook

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

To watch the explanatory videos of Lecture Notes (in Python), 
from the THEORY and PRACTICE of Information Processing course, 
see the class page:

[pi-2022-2](https://sites.google.com/site/fzampirolli/pi-2022-2)

See the course material and introductory videos
of Computer Science Bases, for practice with Colab:

[bcc-2021-3](https://sites.google.com/site/fzampirolli/bcc-2021-3)

---

# Generator Notebooks with Filter by Language

From notebooks with 'code' or 'markdown' cells with markers in the 
first line defining a language to be filtered, with the syntax 

	#[type]#
	
new notebooks will be created by executing the following command:

```
python filterNotebook.py file type format
          
file: example 'all/cap1.part1.ipynb' or 'all'
type: save in 'py', 'js', 'java', 'c', 'cpp', 'r' or 'all'
      also: 'type1+type2+...' more one type per file, for comparisons. 
            eg. 'py+js' in alphabetic order
format: empty, 'html', 'markdown', 'slides' or 'all'
```     

New folders will be created with the filters made. For example:

`python filterNotebook.py all py`

The `py` folder will be created (if it does not exist), filtering all
cells starting with `#[py]#`, of all `ipynb` files inside the` all` 
folder.

Students can choose their preferred programming languages to send 
codes in a single Moodle+VPL activity, with automatic correction! 
Just change the extension of the uploaded file:

`'py', 'js', 'java', 'c', 'cpp' or 'r'`

If `format=all`, all files will be merged into one book: 
 * `gen/*/ALL.ipynb` 
 * `gen/*/ALL.html`
 * `gen/*/ALL.tex`
 * `gen/*/ALL.pdf`

**Attention:** change the notebooks contained only in the `all` folder. 
The remaining notebooks are generated automatically and frequently, 
according to the changes in the originals in `all`.

If the teacher adopts a specific language and wants to personalize the 
notebooks, make a copy of the generated notebooks.

If you have any suggestions for correction or improvement, please 
contact the authors.

