
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZEARRAY 	10001


int main(int argc, char const *argv[]) {
  static char inputArray[SIZEARRAY];
  char pArray[SIZEARRAY]=calloc(SIZEARRAY,sizeof(char));
  char *indexinput;
  char *indexp;
  char flag;
  indexinput=&inputArray;
  indexp=&pArray;
  flag=1;
  while (1) {
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
        if( flag == 0)
        {
          printf("%s\n", "parentisis balanceados" );
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
