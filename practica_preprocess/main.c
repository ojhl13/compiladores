
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>


char * searchname (char *data)
{
	return "test";
}


int main(int argc, char  **argv[])
{
	char typespace[] ={'\t','\n', ' ', '\r' };
	char *fileName = argv[1];
	int type = (int) argv[2];
	int character;
	char temp;
	FILE * myFile = fopen(fileName,"r");
	char *name = searchname(fileName);
	printf("%s %s \n", "Abriendo archivo: ", name);
	printf("Path: %s\n",  fileName);
	char flag = 0; //1 caracter pasado esapcio 0 caracter pasado otra cosa
	char start =0; // inicionado
	while((character = fgetc(myFile)) != EOF)
	{
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
				getc(stdin);//delay(100);//temp =getchar();
				start =1;
			}
			else if ( flag == 1 && start == 0 )
			{
				flag=0;
				start ==1;
				putchar(character);
				getc(stdin);//delay(100);//temp =getchar();
			}
			else
			{
					flag=0;
				start=1;
				putchar(' ');
				putchar(character);
				getc(stdin);//delay(100);//temp =getchar();
			}
		}
	}


	printf("Cerrando archivo: %s\n", name);
	fclose(myFile);
	return 0;

}
