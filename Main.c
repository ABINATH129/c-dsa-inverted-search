/* Name	       : ABINATH S
   Date        : 7/1/2026
   Description : This project implements an Inverted Search (Inverted Index) system in C to efficiently search words across 
   		 multiple text files. The system builds a database of words found in input files and stores their 
		 occurrences using a structured, memory-efficient data model.
			
		 Core Concept : Instead of scanning all files every time a search is performed, the program preprocesses 
		 		the files and creates an inverted index,where Each word is a key,Each key maps to the files 
				in which the word appears, along with its frequency.This significantly reduces search time 
				compared to linear file scanning.
   		
		 Key Advantages :	
		 		->Faster word search compared to linear scanning
				->Efficient organization using linked lists and pointer arrays
				->Supports multiple files and duplicate word handling
				->Backup and restore reduce repeated computation
*/
#include "Header.h"
int main(int argc,char *argv[])
{
	Flist * Head_Flist = NULL;
	M_node * Index[27];
	for(int i=0;i<27;i++)
	{
		Index[i] = NULL;
	}
	validate(argc,argv,&Head_Flist);
	if(Head_Flist)
	{
		int option;
		do
		{
			printf("--------------------------\n");
			printf("   1.Create Database\n");
		     	printf("   2.Display Database\n");
			printf("   3.Search Word\n");
		     	printf("   4.Save Database\n");
		     	printf("   5.Update Database\n");
		     	printf("   6.EXIT\n");
			printf("--------------------------\n");
			printf("Enter any Option : ");
			scanf("%d",&option);
			switch(option)
			{
				case 1:
					if(create_database(Head_Flist,Index) == SUCCESS)
					{
						printf("Database Created Successfully\n");
					}
					else
					{
						printf("Database Creation Failed\n");
					}
					break;
				case 2:
					Display_Database(Index);
					break;
				case 3:
					Search_word(Index);
					break;
				case 4:
					if(Save_Database(Index) == SUCCESS)
					{
						printf("Database Backup Created Successfully\n");
					}
					else
					{
						printf("Database Backup Creation Failed\n");
					}
					break;
				case 5:
					if(Update_Database(Index) == SUCCESS)
					{
						printf("Database Updated Successfully\n");
					}
					else
					{
						printf("Database Updatation Failed\n");
					}
					break;
				case 6:
					break;
				default:
					printf("INVALID OPTION\n");
			}
		}while(option != 6);
	}
}
