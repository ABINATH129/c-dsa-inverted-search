#include "Header.h"
int Display_Database(M_node ** Index)
{
	if(check_Database_Empty(Index) != FAILURE)
	{
		printf("ERROR : Database is Empty\n");
		return FAILURE;
	}
	printf("\n\t----------DATABASE DETAILS----------\n\n");
	printf("Index\tWord\tFile_Count\tFile_Name&Word_Count\n");
	for(int i=0;i<27;i++)
	{
		if(Index[i] != NULL)
		{
			M_node * temp = Index[i];
			while(temp != NULL)
			{
				printf("%d\t",i);
				printf("%s\t",temp->word);
				printf("%d\t\t",temp->file_count);
				S_node * sub_temp = temp -> sub_link;
				while(sub_temp != NULL)
				{
					printf("%s,",sub_temp -> f_name);
					printf("%d  ",sub_temp -> word_count);
					sub_temp = sub_temp -> link;
				}
				printf("\n");
				temp = temp -> main_link;
			}	
		}
	}
	printf("\n");
}
