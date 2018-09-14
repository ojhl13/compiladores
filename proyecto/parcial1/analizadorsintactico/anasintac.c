/*******************************************************************************
* Archivo : anasintac.c
* Descrip : analizador sintactico del proyecto de compilador
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
            }while(0);
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

                      char *readFileName;                            /*path of read file*/
                      FILE *readFile;
                      extern token arrayTokens[SIZEARRAY];

char readTokens(void)
{
  for (size_t i = 0; i < SIZEARRAY; i++) {

  }
}
int main(int argc, char const *argv[]) {

  readFileName = argv[1];
  readFile     = fopen(readFileName,"r");

  if(readTokens()){
    PRINTDEBUG("lectura correcta")
  }
  else{
    PRINTDEBUG("error");
  }
  while (1) {
    /* code */
    if (/* condition */) {
      /* code */
    }


  }


  return 0;
}
