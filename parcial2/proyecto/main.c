
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZEARRAY 100
#define SIZEWORD 20
#define SIZEINPUT 100
#define SIZE      50000




char operators[] = "+-*/%=";
char arrayofreadline [SIZEARRAY][SIZEWORD];
int indexArray=0;
int indexWord =0;
int temporales=0;
int parametros=0;
int labels=0;

void Analize(int numberofwords)
{
  int indexArraytemp=0;
  char *temp;

  temp = ((char*)&arrayofreadline[indexArraytemp][0]);
  //printf("%s   ", temp );
  if(*temp =EOF)
  {
   temp=((char*)&arrayofreadline[indexArraytemp+1][0]);
  }
  //printf("%s\n", temp );
  if( strcmp(temp,"int")==0)
  {
  }
  else if ( strcmp(temp,"void")==0)
  {
  }
  else if (strcmp(temp,"else")==0) {
  }
  else if (strcmp(temp,"return")==0) {
  }
  else if (strcmp(temp,"while")==0) {
    //printf("%s\n",  "tengo un return");
  }
  else // variable con operacion o llamada a funcion
  {
  }
}


int main(int argc, char  **argv[]) {
  char Arraydoc[SIZE];
  char *Array= Arraydoc;

  char *fileName = "test.txt";
  char character;


  char flag = 0; //1 caracter pasado esapcio 0 caracter pasado otra cosa
	char start =0; // inicionado


	FILE * myFile = fopen(fileName,"r");
  printf("Path: %s\n",  fileName);




  while((character = fgetc(myFile)) != EOF)
	{
    /* code */
    if(isspace(character))//espacios detectados
    {
      if(flag == 0){
        flag=1;
      }
    }
    else
    {
      if( flag == 0)
      {
        *Array =(character);
        Array++;
        start =1;
      }
      else if ( flag == 1 && start == 0 )
      {
        flag=0;
        start ==1;
        *Array =(character);
        Array++;
      }
      else
      {
          flag=0;
        start=1;
        *Array =(' ');
        Array++;
        *Array =(character);
        Array++;
      }
    }
  }
  *Array=EOF;
//printarray(Arraydoc,SIZE);
  	printf("Cerrando archivo: %s\n", fileName);
  	fclose(myFile);
////printf("%s\n", Arraydoc );
Array = Arraydoc;
while(*Array != EOF)
{
      //buscar una linea
      if(*Array == ';' |( *Array == '{'| *Array == '}')) {
        Analize(indexArray);
        printf("%s\n", "fin de linea");
        indexWord  = 0;
        indexArray = 0;
      }
      else if( *Array == ' '){
          arrayofreadline[indexArray][indexWord]=EOF;
          putchar(' ');
          indexWord = 0;
        //  //printf("%s <- palabra %i \n",(char*)&arrayofreadline[indexArray][indexWord],indexArray );
          indexArray++;

      }

      else
      {
        arrayofreadline[indexArray][indexWord]=  *Array;
        putchar(arrayofreadline[indexArray][indexWord]);//putchar(*Array);
        indexWord++;
      }

  Array++;
  }
  printf("%s\n", "termine" );

  	return 0;
}
