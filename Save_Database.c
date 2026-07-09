#include "Header.h"
int Save_Database(M_node ** Index)
{
	if(check_Database_Empty(Index) != FAILURE)
	{
		printf("ERROR : Database is Empty\n");
		return FAILURE;
	}
	char file_name[50];
	int j;
	do
	{
		j=0;
		printf("Enter a Valid File Name to Store The Database : ");
		scanf("%s",file_name);
		char * extn = strstr(file_name,".txt");
		if(extn)
		{
			if(strcmp(extn,".txt"))
			{
				printf("ERROR : '%s' Backup File Extension is Invalid\n",file_name);
				j=1;
			}
		}
		else
		{
			printf("ERROR : '%s' Backup File Extension is Invalid\n",file_name);
			j=1;
		}
	}while(j);
	FILE * fp = fopen(file_name,"w");
	if(fp == NULL)
	{
		return FAILURE;
	}
	fprintf(fp,"at %s\n",file_name);
	for(int i=0;i<27;i++)// traverse to each node and store all details in a backup file for future use
	{
		if(Index[i] != NULL)
		{
			M_node * temp = Index[i];
			while(temp)
			{
				fprintf(fp,"#%d;%s;%d;",i,temp -> word,temp -> file_count);
				S_node * sub_temp = temp -> sub_link;
				while(sub_temp)
				{
					fprintf(fp,"%s;%d;",sub_temp -> f_name,sub_temp -> word_count);
					sub_temp = sub_temp -> link;
				}
				fprintf(fp,"#\n");
				temp = temp -> main_link;
			}
		}
	}
	fclose(fp);
	return SUCCESS;
}
