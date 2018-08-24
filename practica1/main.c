#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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
    for (size_t len = 0; len < strlen(inputArray)-1; len++) {
//      printf("%i\n", indexinput);
  //    printf("%i\n", indexoutput);
    //  printf("%i\n", indexp);
      if(  isdigit(inputArray[indexinput]) )
      {
          outputArray[indexoutput] = inputArray[indexinput];
          //printf("add out :%c\n", outputArray[indexoutput]);
          indexoutput++;
          indexinput++;
      }else{
        if(indexp == 0){
          pArray[indexp] = inputArray[indexinput];
          indexp++;

        }
        else{
          if(inputArray[indexinput] == '^'){
            if(pArray[indexinput-1] == '^'){
              outputArray[indexoutput] = pArray[indexp-1];
              indexoutput++; 
            }
            else{
              pArray[indexp]= inputArray[indexinput];
              indexp++;
            }
          }
          else if (inputArray[indexinput] == '*' || inputArray[indexinput] == '/'){
            if(pArray[indexp-1] == '*' || pArray[indexp-1] == '/' ){
              outputArray[indexoutput] = pArray[indexp-1];
              pArray[indexp-1]= inputArray[indexinput];
              indexoutput++;
            }
            else if (pArray[indexp-1] == '-' || pArray[indexp-1] == '+'){
              pArray[indexp]= inputArray[indexinput];
              indexp++;
            }
            else if(pArray[indexp-1] == '^'){

              while(1)
              {
                if(pArray[indexp-1] == '+' || pArray[indexp-1] == '-'){
                  pArray[indexp]=inputArray[indexinput];
                  break;
                  //outputArray[indexoutput]=pArray[indexp-1];
                  //indexp--;
                  //indexoutput++;
                }
                else if(pArray[indexp-1] == '*' || pArray[indexp-1] == '/'){
                  outputArray[indexoutput] = pArray[indexp-1];
                  pArray[indexp]= inputArray[indexinput];
                  indexoutput++;
                  break;
                }
                else if (pArray[indexp-1] == '^'){
                  outputArray[indexoutput] = pArray[indexp-1];
                  indexp--;
                  indexoutput++;
                  break;
                }
                else{
                  break;
                }
                 printf("\n%s: ", "E1" );
                i=indexinput;
                while(i < strlen(inputArray)-1 ) {

                  putc(inputArray[i],stdout);
                  i++;
                }
                printf("\n%s: ", "E2" );
                for (int k = 0; k <= indexoutput; k++) {
                  putc(outputArray[k],stdout);
                }
                printf("\n%s: ","P" );
                for (int j = 0; j <= indexp; j++) {
                  putc(pArray[j],stdout);
                }
                printf("\n" );

              }
            }
          }
          else if(inputArray[indexinput] == '+' || inputArray[indexinput] == '-'){
            if(pArray[indexp-1] == '+' || pArray[indexp-1] == '-'){
              outputArray[indexoutput]=pArray[indexp-1];
              pArray[indexp-1]= inputArray[indexinput];
              indexoutput++;
            }
            else if (pArray[indexp-1] == '*' || pArray[indexp-1] == '/' || pArray[indexp-1] == '^'){
              while (1) {
                if(pArray[indexp-1] == '+' || pArray[indexp-1] == '-'){
                  outputArray[indexoutput]=pArray[indexp-1];
                  pArray[indexp-1]= inputArray[indexinput];
                  indexoutput++;  indexp--;
                  break;

                }
                else if(pArray[indexp-1] == '*' || pArray[indexp-1] == '/' || pArray[indexp-1] == '^' ){
                  //printf("%s\n","compare - con ^" );
                  outputArray[indexoutput] = pArray[indexp-1];
                    indexp--;
                  indexoutput++;
                }

                printf("\n%s: ", "E1" );
                i=indexinput;
                while(i < strlen(inputArray)-1 ) {

                  putc(inputArray[i],stdout);
                  i++;
                }
                printf("\n%s: ", "E2" );
                for (int k = 0; k <= indexoutput; k++) {
                  putc(outputArray[k],stdout);
                }
                printf("\n%s: ","P" );
                for (int j = 0; j <= indexp; j++) {
                  putc(pArray[j],stdout);
                }
                printf("\n" );


              }
            }
            else{

            }
          }

        }
      indexinput++;
      }
      printf("\n%s: ", "E1" );
      i=indexinput;
      while(i < strlen(inputArray)-1 ) {

        putc(inputArray[i],stdout);
        i++;
      }
      printf("\n%s: ", "E2" );
      for (int k = 0; k <= indexoutput; k++) {
        putc(outputArray[k],stdout);
      }
      printf("\n%s: ","P" );
      for (int j = 0; j <= indexp; j++) {
        putc(pArray[j],stdout);
      }
      printf("\n" );

    }
    while(indexp >= 0){
      outputArray[indexoutput]=pArray[indexp];
      indexp--;
      indexoutput++;
      printf("\n%s: ", "E1" );
      i=indexinput;
      while(i < strlen(inputArray)-1 ) {

        putc(inputArray[i],stdout);
        i++;
      }
      printf("\n%s: ", "E2" );
      for (int k = 0; k <= indexoutput; k++) {
        putc(outputArray[k],stdout);
      }
      printf("\n%s: ","P" );
      for (int j = 0; j <= indexp; j++) {
        putc(pArray[j],stdout);
      }
      printf("\n" );
    }

	}

	else
	{
		printf("%s\n", "errror leyendo teclado" );
	}

  return 0;

}
