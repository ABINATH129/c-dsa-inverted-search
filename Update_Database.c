#include "Header.h"
int Update_Database(M_node ** Index)
{
	if(check_Database_Empty(Index) == FAILURE)
	{
		return FAILURE;
	}
	char File_name[50];
	printf("Enter the Backup File For Updatation : ");
	scanf("%s",File_name);
	char * extn = strstr(File_name,".txt");
	if(extn)
	{
		if(strcmp(extn,".txt"))
		{
			printf("ERROR : '%s' Backup File Extension is Invalid\n",File_name);
			return FAILURE;
		}
	}
	else
	{
		printf("ERROR : '%s' Backup File Extension is Invalid\n",File_name);
		return FAILURE;
	}
	FILE * fp = fopen(File_name,"r");
	if(fp == NULL)
	{
		printf("ERROR : '%s' No Such File Exist\n",File_name);
		return FAILURE;
	}
	char check[50];
	fscanf(fp,"%s ",check);
	if(!(strcmp(check,"at")))//validation for whether its a backup file or not
	{
		fscanf(fp,"%[^\n]\n",check);
		if(strcmp(check,File_name))
		{
			printf("ERROR : '%s' File is Not an Backup File\n",File_name);
			return FAILURE;
		}
	}
	else
	{
		printf("ERROR : '%s' File is Not an Backup File\n",File_name);
		return FAILURE;
	}
	int i=0,file_count=0,word_count=0;
	char word[50];
	char file_name[50];
	while(1)//store all datas from backup file and create new nodes and store it
	{
		fscanf(fp,"#%d;%[^;];%d;",&i,word,&file_count);
		create_main_node(&(Index[i]),file_count,word,NULL);
		for(int j=0;j<file_count;j++)
		{
			fscanf(fp,"%[^;];%d;",file_name,&word_count);
			create_sub_node(&(Index[i] -> sub_link),file_name,word_count);
		}
		if(feof(fp))
		{
			break;
		}
		fseek(fp,2,SEEK_CUR);
	}
	fclose(fp);
	return SUCCESS;
}
