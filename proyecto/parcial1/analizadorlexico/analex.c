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
  char value[SIZEBUFF];
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
  char temp;

  readFileName = argv[1];
  readFile     = fopen(readFileName,"r");
  ptrbuffer= buffer;
  ptrbufferstart= buffer;
  numcol=0;
  numline=0;
  character = 0;
  numoftokens=0;
  writeFileName="ListTokens.txt";

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
        character = fgetc(readFile);
        numcol++;
      }
      temp = search(character);
      if( temp < 255 )
      {
        arrayTokens[numoftokens].line=numline;
        arrayTokens[numoftokens].col=numcol;
        arrayTokens[numoftokens].tag="ID";
        strcpy(arrayTokens[numoftokens].value,buffer);

      }
      else if( temp == 255){
        arrayTokens[numoftokens].line=numline;
        arrayTokens[numoftokens].col=numcol;
        arrayTokens[numoftokens].tag="ERROR";
        strcpy(arrayTokens[numoftokens].value,buffer);
      }
        ptrbuffer=ptrbufferstart;
        numoftokens++;

      }



    }
    else if(isdigit(character))
    {
      *ptrbuffer = character;
      ptrbuffer++;
      numcol++,
      character = fgetc(readFile);
      while (isdigit(character))
      {
        /* code */
        *ptrbuffer = character;
        ptrbuffer++;
        numcol++,
        character = fgetc(readFile);
      }
      if(character == '.')
      {
        *ptrbuffer = character;
        ptrbuffer++;
        numcol++,
        character = fgetc(readFile);
        while (isdigit(character))
        {
          /* code */
          *ptrbuffer = character;
          ptrbuffer++;
          numcol++,
          character = fgetc(readFile);
        }
        // REAL
        arrayTokens[numoftokens].line=numline;
        arrayTokens[numoftokens].col=numcol;
        arrayTokens[numoftokens].tag="REAL";
        strcpy(arrayTokens[numoftokens].value,buffer);

      }
      else//ENTERO
      {
        arrayTokens[numoftokens].line=numline;
        arrayTokens[numoftokens].col=numcol;
        arrayTokens[numoftokens].tag="ENTETO";
        strcpy(arrayTokens[numoftokens].value,buffer);
      }

        ptrbuffer=ptrbufferstart;
        numoftokens++;
    }
    else if (character == '\n')
    {
        if ((character = fgetc(readFile)== '\r') {
          numline++:
        }
        else{
          numline++;
        }
    }
    else if ( character  =='\r')
    {
      if ((character = fgetc(readFile)== '\n')
      {
        numline++;
      }
      else{
        numline++;
      }
    }
    else if (character == '(')
    {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="PAR";
      arrayTokens[numoftokens].value='(';

    }
    else if (character == ')')
    {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="PAR";
      arrayTokens[numoftokens].value=')';

    }
    else if (character == '{')
    {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="COR";
      arrayTokens[numoftokens].value='{';

    }
    else if (character == '}')
    {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="COR";
      arrayTokens[numoftokens].value='}';

    }
    else if (character == ',') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="COMA";
      arrayTokens[numoftokens].value=',';

    }
    else if (character == ';') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="PC";
      arrayTokens[numoftokens].value=';';

    }
    else if (character == '<') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="OR";
      arrayTokens[numoftokens].value='<';

    }
    else if (character == '>') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="OR";
      arrayTokens[numoftokens].value='>';

    }
    else if (character == '!') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="NOT";
      arrayTokens[numoftokens].value='!';

    }

    else if (character == '=') {
      if((character== fgetc(readFile)== '='))
      {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="OR";
      arrayTokens[numoftokens].value='==';
      }
      else
      {
        arrayTokens[numoftokens].line=numline;
        arrayTokens[numoftokens].col=numcol;
        arrayTokens[numoftokens].tag="ASIGN";
        arrayTokens[numoftokens].value='=';
      }
    }

    else if (character == '|') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="OL";
      arrayTokens[numoftokens].value='|';

    }

    else if (character == '&') {
      arrayTokens[numoftokens].line=numline;
      arrayTokens[numoftokens].col=numcol;
      arrayTokens[numoftokens].tag="OL";
      arrayTokens[numoftokens].value='&';

    }




  }
  PRINTDEBUG("Cerrando archivo: %s\n", readFileName);
  fclose(readFile);

  readFile = fopen ( "ListTokens.txt", "w+");
  printf("%i\n", numoftokens );
  sprintf(buffer,"%i.\n",numoftokens);
  fputs(buffer,readFile);
  for (int i = 0; i < numoftokens; i++)
  {
    //printf("%s\n",arrayTokens[i].tag );
    fputs(arrayTokens[i].tag,readFile);fputs(",",readFile);
    fputs(arrayTokens[i].value,readFile);fputs(",",readFile);
    sprintf(buffer,"%i,",arrayTokens[i].col);fputs(buffer,readFile);
    sprintf(buffer,"%i\n\r",arrayTokens[i].line);fputs(buffer,readFile);
  }
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
