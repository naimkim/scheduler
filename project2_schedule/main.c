#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int exit_flag = 0;
	char name[200];
	char place[100], typeName[100];	
	size_t size;
	int month;
	int day;
	int type;
	void *list;
	void *ndPtr;
	void *schedInfo;
	int option;
	int cnt=1;
	
	//1. FILE pointer open & error handling
	//fill code here ----
	FILE *fp;
	fp = fopen("schedule.dat", "r");
	if (fp == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	//initializing the list
	printf("Reading the data files... \n");
	list = (void*)list_genList();
	
	
	
	
	//2. read from the file
	while ( !feof(fp) )/* fill code here -- read from the file*/
	{	
		fgets(name, sizeof(name),fp);
		
		//fill code here -- generate genSchedInfo structure by genSchedInfo function 
		void* sched_genSchedInfo;
		schedInfo = sched_genSchedInfo;
		
		//put the scheduling info instance generated by genSchedInfo function
		list_addTail(schedInfo, list);
		
	}
	
	//fill code here ---- close the file pointer
	fclose(fp);
	
	
	printf("Read done! %i schedules are read\n", list_len(list));
	
	
	//program starts
	while(exit_flag == 0) 
	{
		//3. menu printing
		//fill code here ---- 
		printf("1. print all the schedules\n");
		printf("2. search for schedules in the month\n");
		printf("3. search for schedules in the place\n");
		printf("4. search for specific type schedule\n");
		printf("5. exit");
		//4. get option from keyboard
		//fill code here ----
		printf(" select an option : ");
		scanf("%d", &option);
		
		//error handling
	 	if ((option>5)||(option<1))
		{
			printf("not exist\n");
			continue;
		}
					
			switch(option)
			{
				case 1: //print all the schedules
					printf("printing all the schedules in the scheduler.....\n\n\n");
				
					if(cnt <list_len(list)) //every schedule printf
					{
					ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)
					{
					//file code here -- print count and each scheduling info element
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					printf("---------------------------\n");
					printf("%d", cnt);
						
					sched_print(ndPtr); 	
					cnt++;
					//fill code this part - end
					fclose(ndPtr);
					}
					}
				break;
				
				case 2:
					printf("which month ? : ");
					scanf("%i", &month);
				
					if( sched_getMonth(ndPtr) == month) 
					{
					ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)
					{
					//file code here -- print scheduling info elements matching to the month						
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
		
					printf("---------------------------\n");
					printf("%d", cnt);
					sched_print(ndPtr); 
					cnt++;		
					//fill code this part - end
					fclose(ndPtr);					
					}
					}
				
				break;
				
				case 3:
					printf("which place ? : ");
					scanf("%s", place);
					
					//sched_getplace?
					if( sched_getPlace(ndPtr) == place) 
					{ 
					ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)
					{
					//file cod here -- print scheduling info elements matching to the place
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)			
		
					printf("---------------------------\n");
					printf("%d", cnt);
					sched_print(ndPtr);
					cnt++; 	
					//fill code this part - end
					fclose(ndPtr);					
					}
					}
				
				break;
				
				case 4:
					printf("which type ?\n");
					sched_printTypes();
					printf("your choice : ");
					scanf("%s", typeName);
					
					//typeName is string 
					if ((sched_convertType(typeName) >= '0') && (sched_convertType(typeName) <= '6') )/* fill code here -- convert the type and check if the type is valid */
					{
					ndPtr = list;
						while (list_isEndNode(ndPtr) == 0)
						{
						ndPtr = list_getNextNd(ndPtr); //get the next node from the list
						schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
						
						if( (sched_getType(ndPtr))== (sched_convertType(typeName)) ) 
						{		
						printf("---------------------------\n");
						printf("%d", cnt);
						
						sched_print(ndPtr); 	
						}
						//fill code this part - end
						fclose(ndPtr);
						}
					}
					else
					{
					printf("wrong type name!\n");
					}
				break;
				
				case 5:
					printf("Bye!\n\n");
					exit_flag = 1;
				break;
				
				default:
					printf("wrong command! input again\n");
				break;
			}	
	}
	
	return 0;
}
