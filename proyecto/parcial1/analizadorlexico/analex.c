/*******************************************************************************
* Archivo : analex.c
* Descrip : analizador lexico del proyecto compilador
* Autor   : Oscar Javier Hinojosa Luna A01223081
* Correo  : A01223081@itesm.mx
* Version : V1.0.0
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define DEBUG
#ifdef DEBUG
#define PRINTDEBUG(...) do{								        \
							fprintf(stderr, __VA_ARGS__ );			\
							}while(0)
#endif


int main (int argc, char **argv)
{
  const char syms[]   ={'\t','\n', ' ', '\r' };   /*table of symbols*/
  char * readFileName = argv[1];                  /*path of read file*/
  FILE * readFile     = fopen(readFileName,"r");  /*pointer to read file*/
  char character;

  character = 0;
  PRINTDEBUG("Open File in path: %s\n", readFileName);
  while((character = fgetc(readFile)) != EOF)
  {
    putchar( character );

  }
  PRINTDEBUG("Cerrando archivo: %s\n", readFileName);
  fclose(readFile);
  return 0;
}




/******************************************************************************
* definitions of test files
* test1.exe open and close file
* test2.exe read print and close fileName
*
*
*******************************************************************************/
