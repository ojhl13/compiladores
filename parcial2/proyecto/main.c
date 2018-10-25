
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZEARRAY 100
#define SIZEWORD 20
#define SIZEINPUT 100
#define SIZE      50000



typedef struct {
  char operador[SIZEWORD];
  char openado1[SIZEWORD];
  char operando2[SIZEWORD];
}tripleta;

tripleta codeinter[100];

char operators[] = "+-*/%=";
char arrayofreadline [SIZEARRAY][SIZEWORD];
int indexArray=0;
int indexWord =0;
int temporales=0;
int parametros=0;
int labels=0;
int indextripletas
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
    //printf("%s\n",  "tengo un int");
    indexArraytemp+=2;
    temp = ((char*)&arrayofreadline[indexArraytemp][0]);
    if(*temp == '(')//definicion de funcion
    {
      temp = ((char*)&arrayofreadline[indexArraytemp-2][0]);
      printf("%s %s\n", "entry",temp );
      codeinter[indextripletas].operador="entry";
      codeinter[indextripletas]..openado1=temp;
      indextripletas++;
    }
    else if( *temp == '=')
    {
      indexArraytemp+=1;
      temp = ((char*)&arrayofreadline[indexArraytemp][0]);
        if( isdigit(*temp))
        {
          temp = ((char*)&arrayofreadline[indexArraytemp-2][0]);
          printf("%s = ",temp );
          codeinter[indextripletas]..openado1=temp;
          temp = ((char*)&arrayofreadline[indexArraytemp][0]);
          printf("%s\n", temp);
          codeinter[indextripletas].operador="=";
          codeinter[indextripletas]..openado2=temp;
          indextripletas++;
        }
    }

  }
  else if ( strcmp(temp,"void")==0)
  {
    //printf("%s\n",  "tengo un void");
    indexArraytemp+=2;
    temp = ((char*)&arrayofreadline[indexArraytemp][0]);
    if(*temp == '(')//definicion de funcion
    {
      temp = ((char*)&arrayofreadline[indexArraytemp-2][0]);
      printf("%s %s\n", "entry",temp );
      codeinter[indextripletas].operador="entry";
      codeinter[indextripletas]..openado1=temp;
      indextripletas++;

    }
  }
  else if( strcmp(temp,"if")==0 )
  {
    //printf("%s\n",  "tengo un if");
    indexArraytemp+=3;
    temp = ((char*)&arrayofreadline[indexArraytemp][0]);
    if(*temp == ')')//definicion de funcion
    {
      temp = ((char*)&arrayofreadline[indexArraytemp-1][0]);
      printf("if flase %s goto L%i\n", temp ,labels);
      labels++;
      codeinter[indextripletas].operador="if";
      codeinter[indextripletas]..openado1=temp;
      codeinter[indextripletas]..openado2=("L%i",labels);
      indextripletas++;
    }
    else{
      temp = ((char*)&arrayofreadline[indexArraytemp-1][0]);
      printf("t%i = %s", temporales,temp);
      temporales++;
      temp = ((char*)&arrayofreadline[indexArraytemp][0]);
      printf("%s", temp);
      temp = ((char*)&arrayofreadline[indexArraytemp+1][0]);
      printf("%s\n", temp);
      temp = ((char*)&arrayofreadline[indexArraytemp+1][0]);
      printf("if false t%i goto L%i\n",temporales,labels );
      labels++;
    }
  }
  else if (strcmp(temp,"else")==0) {
    //printf("%s\n",  "tengo un else");
    printf("LABEL L%i\n", (labels-1));
  }
  else if (strcmp(temp,"return")==0) {

    //printf("%s\n",  "tengo un return");
    indexArraytemp+=1;
    temp = ((char*)&arrayofreadline[indexArraytemp][0]);
    if(isdigit(*temp))
    {
      printf("return %s\n", temp);
    }
    else if( isalpha(*temp))
    {
      indexArraytemp+=1;
      temp = ((char*)&arrayofreadline[indexArraytemp][0]);
      for(int i = 0; i < 6; ++i){
          if(*temp= operators[i]){
            printf("t%i =",temporales );
            temp = ((char*)&arrayofreadline[indexArraytemp-1][0]);
            printf("%s",temp );
            temp = ((char*)&arrayofreadline[indexArraytemp][0]);
            printf("%s",temp );
            temp = ((char*)&arrayofreadline[indexArraytemp+1][0]);
            printf("%s\n",temp );
            printf("return t%i\n",temporales );
          }
        }

    }
  }
  else if (strcmp(temp,"while")==0) {
    //printf("%s\n",  "tengo un return");
  }
  else // variable con operacion o llamada a funcion
  {
    indexArraytemp++;
    temp = ((char*)&arrayofreadline[indexArraytemp][0]);
    if(*temp == '(')//lamado a funcion
    {
      FUNCION:
        if(isalpha(*temp)){
          printf("%s\n", "Begin_args");
          indexArraytemp++;
          temp = ((char*)&arrayofreadline[indexArraytemp][0]);
          for(int i = 0; i < 6; ++i){
              if(*temp == operators[i]){
                  printf("t%i =",temporales );
                  temp = ((char*)&arrayofreadline[indexArraytemp-1][0]);
                  printf("%s",temp );
                  temp = ((char*)&arrayofreadline[indexArraytemp][0]);
                  printf("%s",temp );
                  temp = ((char*)&arrayofreadline[indexArraytemp+1][0]);
                  printf("%s\n",temp );
                }
          }
          printf("params t%i\n",temporales );
          parametros++;
          temporales++;
          indexArraytemp++;
          temp = ((char*)&arrayofreadline[indexArraytemp][0]);
          if(*temp = ')' ){
            printf("t%i = call",temporales );
            temp = ((char*)&arrayofreadline[indexArraytemp-3][0]);
            printf("%s , %i",temp,parametros );
          }

        }
    }
    else if (*temp == '=')
    {
      indexArraytemp++;
      temp = ((char*)&arrayofreadline[indexArraytemp][0]);
      if (isalpha(*temp))
      {
        indexArraytemp++;
        temp = ((char*)&arrayofreadline[indexArraytemp][0]);
        if(*temp == '(')
        {
          goto FUNCION;
        }
      }
      if( strcmp(temp,"read"))
      {
        temp = ((char*)&arrayofreadline[indexArraytemp-2][0]);
        printf("read %s\n", temp);
      }
    }
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
