#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 			//��� 
	movie=1, 			//��ȭ 
	advertisement=2, 	//���� 
	entertainment=3, 	//���� 
	meeting=4,			//ȸ�� 
	fitness=5,			//� 
	privacy=6,			//���λ� 
} scheduleType_e;



//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) //������ ���� ��ȣ  
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) //������ �̸�, ����, ��¥, ��� ���  
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}


//generating a structure of scheduling information
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;
	
	//error handler
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
		return -1;
	}
	//allocate memory 
	schedPtr = (schedInfo_t *) malloc(200*sizeof(schedInfo_t));
	//set the member variables ��� ���� ����... 
	//schedPtr->name = ;
	//schedPtr->place = ;
	schedPtr->type = type_string[MAX_TYPE][20];
	schedPtr->month = month_string[13][4];
	//schedPtr.day = ;
	
	return ;
}



//get month information from the scheduler info structure ���������� ����ü�� ����  
float sched_getMonth(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	//month information 
	void* sched_genSchedInfo(schedPtr);
	
	return;
	
}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	
	void* sched_genSchedInfo(schedPtr);
	
	return;	
}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	void* sched_genSchedInfo(schedPlace);
	
	return;
}

//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{
	scheduleType_e schedType;
	
	switch(schedType)
	{
		case drama:
			typeName = 0;
		case movie:
			typeName = 1;
		case advertisement:
			typeName = 2;
		case entertainment:
			typeName = 3;
		case meeting:
			typeName = 4;
		case fitness:
			typeName = 5;
		case privacy:
			typeName = 6;
		default:
			typeName = 7;
			break;
		
	}
	
	return;
}

