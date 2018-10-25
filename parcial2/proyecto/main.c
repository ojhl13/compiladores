
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZEARRAY 50
#define SIZEWORD 20
#define SIZEINPUT 100




int main(int argc, char  **argv[]) {
  char arrayofreadline [SIZEARRAY][SIZEWORD];
  char *fileName = "test.txt";
  char character;
  int indexArray=0;
  int indexWord =0;


  char flag = 0; //1 caracter pasado esapcio 0 caracter pasado otra cosa
	char start =0; // inicionado


	FILE * myFile = fopen(fileName,"r");
  printf("Path: %s\n",  fileName);




  while((character = fgetc(myFile)) != EOF)
	{
  //while (character != ';') {
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
        putchar(character);

        start =1;
      }
      else if ( flag == 1 && start == 0 )
      {
        flag=0;
        start ==1;
        putchar(character);

      }
      else
      {
          flag=0;
        start=1;
        putchar(' ');
        putchar(character);

      }
    }
      //  character = fgetc(myFile);
//      }
      indexWord=0;
      indexArray=0;
}

  	printf("Cerrando archivo: %s\n", myFile);
  	fclose(myFile);
  	return 0;
}
