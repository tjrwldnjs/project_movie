#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
	
	//1. reading the movie.dat-----------------------------
	fp = fopen("movie.dat","r"); //1.1 FILE open
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	printf("Reading the data file\n");
	
	//1.3 read each movie data from the file and add it to the linked list
	while  (fscanf(fp,"%s %s %d %f", name, country, &runTime, &score) != EOF)
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo() //무비인포 불러오기
		mvInfo = mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);	
	}
	
	fclose(fp);	//1.4 FILE close
	
	//2. program start
	while(exit_flag == 0)
	{
		//2.1 print menu message and get input option
		printf("\n----------------MENU----------------\n");
		printf("1. Print all movies\n");
		printf("2. Search for specific country movies\n");
		printf("3. Search for specific runtime movies\n");
		printf("4. Search for specific score movies\n");
		printf("5. Exit\n\n");
		
		printf("Input a number : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL;
				
				cnt = list_repeatFunc(repFunc, arg, list); //몇 개의 영화가 출력되었는지 알아보기 위해서. 
				printf("\nTotally %d movies are listed\n",cnt);
				
				break;
				
			case 2: //print movies of specific country
				
				arg = &country; //문자열로 받은거 	
				printf("Input country : ");
				scanf("%s", &country); //문자열로 국가받기 
				printf("----------------------------------------\n");
				
				repFunc = mv_printCountry;
				
				cnt = list_repeatFunc(repFunc, arg, list);//몇 개의 영화가 출력되었는지 알아보기 위해서. 
				printf("\nTotally %d movies are listed\n",cnt);
				break;	
				
				
			case 3: //print movies with long runtime
				arg = &runTime;
				printf("Input runTime : ");
				scanf("%d", &runTime); 
				printf("----------------------------------------\n");
				
				repFunc = mv_printRunTime;
				
				cnt = list_repeatFunc(repFunc, arg, list);//몇 개의 영화가 출력되었는지 알아보기 위해서. 
				printf("\nTotally %d movies are listed\n",cnt);
			
				break;
				
			case 4: //print movies with high score
				
				arg = &score;
				printf("Input score : ");
				scanf("%f", &score); 
				printf("----------------------------------------\n");
				
				repFunc = mv_printScore;
				
				cnt = list_repeatFunc(repFunc, arg, list);//몇 개의 영화가 출력되었는지 알아보기 위해서. 
				printf("\nTotally %d movies are listed\n",cnt);
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
				
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		
		//2.3 print number of movies
		
	}
	
	return 0;
}
