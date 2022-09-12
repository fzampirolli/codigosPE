/* Copyright (C) 2022 Francisco de Assis Zampirolli - All Rights Reserved
 * Author: Francisco de Assis Zampirolli
 * Purpose: Examples and some exercises from the Information Processing book
 * Language: C
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>5.
 */
#include <stdio.h>

int main() {
  char* filename = "teste.txt", ch;

  FILE* fp;
  fp = fopen(filename, "r"); // Cria arquivo para escrita
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", filename);
    return -1;
  }

  while ((ch = fgetc(fp)) != EOF) { // Lê arquivo
    printf("%c", ch); // caracter por caracter
  }

  fclose(fp); // fecha arquivo

  return 0;
}