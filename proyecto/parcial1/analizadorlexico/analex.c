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
#include <string.h>

#define DEBUG
#ifdef DEBUG
#define PRINTDEBUG(...) do{								        \
							fprintf(stderr, __VA_ARGS__ );			\
							}while(0)
#endif
#define SIZEBUFF 100
#define SIZEARRAY 10000

typedef struct tok{
  int line;
  int col;
  char *tag;
  char *value;
}token;

/*table of symbols*/
/*0->\t,1->\n,2->space,3-> \r*/
/*4->{,5->},6->(,7->)*/
/*8->,,9->;,10-> <,11-> >*/
/*12-> =,13-> !,14 -> |,15-> &*/
static char syms[]   ={'\t' , '\n' , ' ' , '\r',\
                              '{' , '}' , '(' , ')' ,\
                              ',' , ';' , '<' , '>' ,\
                              '=' , '!' , '|' , '&' \
                            };
static char *tags[] ={\
                        "ID","INT","REAL","PAR", \
                        "COR","COMA","OR","PC", \
                        "OA","OR","NEG","OP"\
                      };



char compare2syms( char data);

char search ( char data)
{
  /*100-number
   *101letter
   *255-error
   *or number of symbol in the table
  */
  char data2return = 255;

  if(isdigit(data))
  {
    //printf("digito\n" );
    data2return = 100;
  }
  else if(isupper(data) | islower(data))
  {
    //printf("letra\n" );
    data2return = 101;
  }
  else{
  data2return = compare2syms(data);
  //printf("simbolo numero :%i\n", data2return );
  }
  return data2return;
}

char compare2syms( char data)
{
  /*
   * 255 - flase
   *
   */
  int count;
  char *ptrsyms;
  char data2return;
  ptrsyms = syms;
  count=16;
  data2return=255;

  while ((count--) > 0)
  {
    if (data == *ptrsyms)
    {
      data2return = count-1;
      break;
    }
  }
  return data2return;
}



int main (int argc, char **argv)
{

  char *writeFileName;
  char *readFileName;                            /*path of read file*/
  FILE *readFile;                                /*pointer to read file*/
  char character;
  char buffer[SIZEBUFF];
  char *ptrbuffer;
  char *ptrbufferstart;
  int numline;
  int numcol;
  token arrayTokens[SIZEARRAY];
  int numoftokens;

  readFileName = argv[1];
  readFile     = fopen(readFileName,"r");
  ptrbuffer= buffer;
  ptrbufferstart= buffer;
  numcol=0;
  numline=0;
  character = 0;
  numoftokens=0;
  writeFileName="ListTokens.txt";
  #define SAVENEWTOKEN(X,Y) do{\
                            arrayTokens[numoftokens].line=numline;\
                            arrayTokens[numoftokens].col=numcol;\
                            arrayTokens[numoftokens].tag=(X);\
                            arrayTokens[numoftokens].value=(Y);\
                            ptrbuffer=ptrbufferstart;\
                            numoftokens++;\
                            }while(0);

  PRINTDEBUG("Open File in path: %s\n", readFileName);
  while((character = fgetc(readFile)) != EOF)
  {
    //#ifdef TEST2
    //putchar( character );
    //#endif
    if (islower(character)) //id
    {

      *ptrbuffer = character;
      ptrbuffer++;
      numcol++,
      character = fgetc(readFile);

      while(search(character) == 100 | search(character) == 101)
      {
        //printf("%s %s: \n" , "entro a ciclo: ", buffer);
        *ptrbuffer = character;
        ptrbuffer++;
        numcol++;
        character = fgetc(readFile);
      }
      putchar(character);
      putchar('\n');
      if( (search(character) != 255 ))
      {
        //printf("%s %s\n", "termine cadena: ", buffer );
        SAVENEWTOKEN((&tags[0]),ptrbufferstart);
        SAVENEWTOKEN((&tags[(search(character))]),(char *)character);


      }



    }
    //memset(buffer,'0',sizeof(buffer)*SIZEBUFF);



  }
  PRINTDEBUG("Cerrando archivo: %s\n", readFileName);
  fclose(readFile);

  readFile = fopen ( "ListTokens.txt", "w+");
  printf("%i\n", numoftokens );
  sprintf(buffer,"%i.\n",numoftokens);
  fputs(buffer,readFile);
  
    PRINTDEBUG("Cerrando archivo: %s\n", writeFileName);
  fclose(readFile);
  PRINTDEBUG("fin");
  return 0;
}





/******************************************************************************
* definitions of test files
* test1.exe open and close file
* test2.exe read print and close fileName
*
*
*******************************************************************************/
