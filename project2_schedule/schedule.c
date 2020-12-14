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
	drama=0, 			//드라마 
	movie=1, 			//영화 
	advertisement=2, 	//광고 
	entertainment=3, 	//예능 
	meeting=4,			//회의 
	fitness=5,			//운동 
	privacy=6,			//개인사 
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


void sched_printTypes(void) //스케줄 유형 번호  print
{
	int i=0;
	

	while(i<MAX_TYPE) 
	{
		printf("- %s\n", type_string[i]);
		i++;
		
	}
	
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info0! (object is NULL)\n");
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
	if (schedPtr == NULL)
	{
		printf("[ERROR] failed to print the schedule Info1! (object is NULL)\n");
	}
	
	//allocate memory 
	schedPtr = (schedInfo_t *) malloc(200*sizeof(schedInfo_t));
	
	//set the member variables 멤버 변수 설정... 
	*schedPtr->name;
	*(schedPtr+1)->place;
	(schedPtr+2)->type;
	(schedPtr+3)->month;
	(schedPtr+4)->day;
	
	free(schedPtr);
	
	return (void*)schedPtr ;
}



//get month information from the scheduler info structure 스케줄정보 구조체로 부터  
float sched_getMonth(void* obj)
{
	int x;
	
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info2! (object is NULL)\n");
	}
	
	//month information 
	schedPtr = schedPtr + 3;
	
	void* sched_genSchedInfo(schedPtr);
	
	month_string[schedPtr->month][4] = x;
	
	return x ;	
}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{
	int y;
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info3! (object is NULL)\n");
	}
	
	schedPtr = schedPtr + 2;
	
	void* sched_genSchedInfo(schedPtr);
	
	type_string[schedPtr->type][20] = y;
	
	return y ;	
}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info4! (object is NULL)\n");
	}
	
	schedPtr = schedPtr + 1 ;
	
	void* sched_genSchedInfo(schedPtr);
	
	return (void*)schedPtr ;
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
	
	return typeName;

}

