#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


float celTofar(float temp);
float farTocel(float temp);


int main(int argc, char* argv[])
{
	
	
/*	float temp;
	float ctemp;
	
	temp = 0.0;
	ctemp = 0.0;
*/
	
	switch (argc){
		case 1:
			printf("text\n");
			break;
		
		case 3:
			switch (toupper(*argv[1])){
				case 'F':
					printf("%.2f\n", celTofar(atof(argv[2])));
					break;
				case 'C':
					printf("%.2f\n", farTocel(atof(argv[2])));
					break;
				default:
					printf("Unknown command.\n");
					break;	
			}
			break;
			
		default:
			printf("text!\n");
			break;
	}
	
	return 0;
}


float celTofar(float a)
{
	float temp;
	float ctemp;
	temp = a;
	ctemp = 0.0;
	
	ctemp = (temp * 1.8) + 32;
	
	return ctemp;
		
}

float farTocel(float a)
{
	float temp;
	float ctemp;
	temp = a;
	ctemp = 0.0;
	
	ctemp =  5/9 * (temp - 32);
	
	return ctemp;
		
}