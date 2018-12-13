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
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t)); //메모리를 할당한다. 
	
	strcpy(mvPtr->name, name); //문자열을 가리키기 위해 strcpy를 사용한다. 
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
	printf("----------------------------------------\n");
	
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
	
	printMv(arg); //arg 즉, mvPtr이 가리키는 것이 printMv에 들어가는것이다. 
	
	return 1; //1을 리턴해줌으로써 cnt가 누적된다. 따라서 출력된 영화의 개수를 말함.   
}

int mv_printScore(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	float* score = (float*)arg; //형변환을 해준다. 
	
	if (mvPtr == NULL) 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	else if( (mvPtr->score) >= *score ) //입력한 값보다 크거나 같으면 출력한다. 
	{
		printMv(mvPtr); //mvPtr이 가리키는 값을 출력한다. 
		printf("----------------------------------------\n");
		return 1; //1을 리턴해줌으로써 cnt가 누적된다. 따라서 출력된 영화의 개수를 말함.   
	}

	return 0;
}

int mv_printRunTime(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	int* runTime = (int*)arg;//형변환을 해준다. 
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	else if( (mvPtr->runTime) >= *runTime ) // 입력한 값보다 크거나 같으면 출력한다. 
	{
		printMv(mvPtr); //mvPtr이 가리키는 값을 출력한다. 
		printf("----------------------------------------\n");
		return 1; //1을 리턴해줌으로써 cnt가 누적된다. 따라서 출력된 영화의 개수를 말함.   
	}
	return 0;
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	char* country = (char*)arg;//형변환을 해준다. 
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	else if( strcmp((mvPtr->madeIn), country)==0) //문자열을 비교할 때는 strcmp를 사용해야한다. 입력한 값이 같으면 출력한다. 
	{
		printMv(mvPtr); //mvPtr이 가리키는 값을 출력한다. 
		printf("----------------------------------------\n");
		return 1; //1을 리턴해줌으로써 cnt가 누적된다. 따라서 출력된 영화의 개수를 말함.
	}
	return 0;
}




