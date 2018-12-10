#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	strcpy(mvPtr->name, name);
	strcpy(mvPtr->madeIn, country);
	mvPtr->runTime = runTime;
	mvPtr->score = score;

	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


int mv_printAll(void* obj, void* arg)
{
	//printMv를 실행하자
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	arg = mvPtr;
	mvPtr->name;
	mvPtr->madeIn;
	mvPtr->runTime;
	mvPtr->score;
	
	printMv(arg); //이건가? 
	
	return 0;
}

int mv_printScore(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	float* score = (float*)arg;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	if( (mvPtr->score) >= *score ) //조건문을 채우자. 
	{
		
		printMv(mvPtr);	
	}

	return 0;
}

int mv_printRunTime(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	int* runTime = (int*)arg;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	if( (mvPtr->runTime) >= *runTime ) //조건문을 채우자. 
	{
		
		printMv(mvPtr);	
	}
	return 0;
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	char* country = (char*)arg;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	if( (mvPtr->madeIn) = /*문자열비교로 */ *country ) //조건문을 채우자. 
	{
		printMv(mvPtr);	
	}
	return 0;
}




