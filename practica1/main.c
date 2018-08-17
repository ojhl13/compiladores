#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZEARRAY 	10001

int main(int argc, char const *argv[]) {

  static char inputArray[SIZEARRAY];
  char outputArray[SIZEARRAY];
  char pArray[SIZEARRAY];
  int indexinput;
  int indexoutput;
  int indexp;
  int i=0;
  indexinput=0;  indexoutput=0; indexp=0;

  if(fgets(inputArray, (SIZEARRAY) , stdin))
	{
    for (size_t len = 0; len < strlen(inputArray); len++) {
      if(  (inputArray[i] <= '0') && (inputArray[i] >= '9')  )
      {
          outputArray[indexoutput] = inputArray[indexinput];

      }
      else{
        if(indexp == 0){
          pArray[indexp] = inputArray[indexinput];
          indexp++;
        }
        else{
          if(inputArray[indexinput] == '^'){
            if(inputArray[indexinput] == pArray[indexp-1]){
              outputArray[indexoutput] = pArray[indexp-1];

            }
            else{
              pArray[indexp]= inputArray[indexinput];
              indexp++;
            }
          }
          else if (inputArray[indexinput] == '*' || inputArray[indexinput] == '/'){
            if(pArray[indexp-1] == '*' || pArray[indexp-1] == '/' ){
              outputArray[indexoutput] = pArray[indexp-1];
              indexp--;
              pArray[indexp]= inputArray[indexinput];
            }
            else if(pArray[indexp-1] == '^'){
              pArray[indexp]= inputArray[indexinput];
              indexp++;
            }
            else if (pArray[indexp-1] == '-' || pArray[indexp-1] == '+'){
              while(1)
              {
                if(pArray[indexp-1] == '+' || pArray[indexp-1] == '-'){
                  outputArray[indexoutput]=pArray[indexp-1];
                  indexp--;
                  indexoutput++;
                }
                else if(pArray[indexp-1] == '*' || pArray[indexp-1] == '/'){
                  outputArray[indexoutput] = pArray[indexp-1];
                  indexp--;
                  pArray[indexp]= inputArray[indexinput];
                  break;
                }
                else{
                  break;
                }

              }
            }
          }
          else if(inputArray[indexinput] == '+' || inputArray[indexinput] == '-'){
            if(pArray[indexp-1] == '*' || pArray[indexp-1] == '/' || inputArray[indexinput] == '^'){
              pArray[indexp]= inputArray[indexinput];
              indexp++;
            }
            else if (pArray[indexp-1] == '+' || pArray[indexp-1] == '-'){
              outputArray[indexoutput]=pArray[indexp-1];
              indexp--;
              indexoutput++;
            }
            else{

            }
          }

        }

      }
      printf("\n%s: ", "E1" );
      i=indexinput;
      while(i < strlen(inputArray) ) {

        putc(inputArray[i],stdout);
        i++;
      }
      printf("\n%s: ", "E2" );
      for (int k = 0; k < indexoutput; k++) {
        putc(outputArray[k],stdout);
      }
      printf("\n%s: ","P" );
      for (int j = 0; j < indexp; j++) {
        putc(pArray[j],stdout);
      }
      indexoutput++;
      indexinput++;
    }

	}
	else
	{
		printf("%s\n", "errror leyendo teclado" );
	}

  return 0;

}
