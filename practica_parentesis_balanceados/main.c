
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define SIZEARRAY 	10001


int main(int argc, char const *argv[]) {
  char inputArray[SIZEARRAY];
  char *pArray;
  char *indexinput;
  char *indexp;
  char flag;
  pArray=calloc(SIZEARRAY*sizeof(char), sizeof(char) );
  indexinput=(char*) &inputArray;
  indexp=(char*) &pArray;
  flag=1;
  while (1) {
    printf("%s\n", "start" );
    if(fgets(inputArray, (SIZEARRAY) , stdin))
  	{
        for (size_t len = 0; len < strlen(inputArray)-1; len++)
        {
               if(*indexinput == '(' )
          {
              *indexp = '(';
              indexp++;
          }
          else if (*indexinput == ')')
          {
            if( *indexp == ' ')
            {
              if (flag == 1){
                flag=0;
                printf("%s\n", "Error parentisis desbalanceados" );
              }
            }
            else if (*indexinput == '(') {
              indexp--;
            }
          }
          else
          {
              printf("%s\n","NULL character" );
          }
          indexinput++;
        }
        printf("%s\n",  "finish for" );
        if( flag == 0)
        {
          printf("%s\n", "parentisis balanceados" );
        }
        else{
          printf("%s\n",  "parentesis desbalanceados Error");
        }
        break;
    }
    else
    {
      printf("%s\n", "errror leyendo teclado" );
      break;
    }

  }
  return 0;
}
