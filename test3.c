#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dataassi1.h"

void main()
{
	int i;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.\t Create molecule\n");
		printf("2.\t Insert nucleotide\n");
		printf("3.\t Delete nucleotide\n");
		printf("4.\t Print molecule\n");
		printf("5.\t Print all the molecules generated\n");
		printf("6.\t Split the molecule\n");
		printf("7.\t Quit\n");
		printf("Enter your choice\n");
		scanf("%d",&i);
		
		switch(i)
		{
			case 1: createmolecule1();
			         break;
			  
			case 2: insertnucleo();
			         break;
			case 3: deletenucleo();
			         break;
			case 4: printmolecule1();
			         break;
			case 5: printallmolecules();
			         break;
			case 6:  splitmolecule();
			          break;        
			case 7: exit(EXIT_SUCCESS);
			
			default: printf("Invalid input given\n");
		}
	}
}			
			
			 
	
	
	
	
	
	
	
	
	
	
	
		








