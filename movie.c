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
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t)); //�޸𸮸� �Ҵ��Ѵ�. 
	
	strcpy(mvPtr->name, name); //���ڿ��� ����Ű�� ���� strcpy�� ����Ѵ�. 
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
	//printMv�� ��������
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	arg = mvPtr;
	mvPtr->name;
	mvPtr->madeIn;
	mvPtr->runTime;
	mvPtr->score;
	
	printMv(arg); //arg ��, mvPtr�� ����Ű�� ���� printMv�� ���°��̴�. 
	
	return 1; //1�� �����������ν� cnt�� �����ȴ�. ���� ��µ� ��ȭ�� ������ ����.   
}

int mv_printScore(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	float* score = (float*)arg; //����ȯ�� ���ش�. 
	
	if (mvPtr == NULL) 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	else if( (mvPtr->score) >= *score ) //�Է��� ������ ũ�ų� ������ ����Ѵ�. 
	{
		printMv(mvPtr); //mvPtr�� ����Ű�� ���� ����Ѵ�. 
		printf("----------------------------------------\n");
		return 1; //1�� �����������ν� cnt�� �����ȴ�. ���� ��µ� ��ȭ�� ������ ����.   
	}

	return 0;
}

int mv_printRunTime(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	int* runTime = (int*)arg;//����ȯ�� ���ش�. 
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	else if( (mvPtr->runTime) >= *runTime ) // �Է��� ������ ũ�ų� ������ ����Ѵ�. 
	{
		printMv(mvPtr); //mvPtr�� ����Ű�� ���� ����Ѵ�. 
		printf("----------------------------------------\n");
		return 1; //1�� �����������ν� cnt�� �����ȴ�. ���� ��µ� ��ȭ�� ������ ����.   
	}
	return 0;
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	char* country = (char*)arg;//����ȯ�� ���ش�. 
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	else if( strcmp((mvPtr->madeIn), country)==0) //���ڿ��� ���� ���� strcmp�� ����ؾ��Ѵ�. �Է��� ���� ������ ����Ѵ�. 
	{
		printMv(mvPtr); //mvPtr�� ����Ű�� ���� ����Ѵ�. 
		printf("----------------------------------------\n");
		return 1; //1�� �����������ν� cnt�� �����ȴ�. ���� ��µ� ��ȭ�� ������ ����.
	}
	return 0;
}




