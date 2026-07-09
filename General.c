#include "Header.h"
void validate(int argc,char * argv[],Flist ** Head)
{
	if(argc == 1)
	{
		printf("ERROR : No Files Passed as Input\n");
	}
	int count = 0;
	for(int i=1;i<argc;i++)
	{
		char * extn = strstr(argv[i],".txt");
		if(extn)
		{
			if(strcmp(extn,".txt"))
			{
				printf("ERROR : '%s' File Extension is Invalid\n",argv[i]);
				continue;
			}
		}
		else
		{
			printf("ERROR : '%s' File Extension is Invalid\n",argv[i]);
			continue;
		}
		FILE * fp = fopen(argv[i],"r"); 
		if(fp == NULL)
		{
			printf("ERROR : '%s' File Not Exist\n",argv[i]);
			continue;
		}
		fseek(fp,0,SEEK_END);
		if(0 == ftell(fp))
		{
			printf("ERROR : '%s' File is Empty\n",argv[i]);
			continue;
		}
		else
		{
			//check whether the input file is not an backup file
			rewind(fp);
			char check[50];
			fscanf(fp,"%[^\n]\n",check);
			if(fgetc(fp) == '#')
			{
				printf("ERROR : '%s' File is Not an Valid File\n",argv[i]);
				continue;
			}
		}
		fclose(fp);
		if(count == 0)
		{
			insert_last(Head,argv[i]);
			count++;
		}
		else
		{
			int flag = 0;
			Flist * temp = *Head;
			while(temp != NULL)
			{
				if(!(strcmp(argv[i],temp -> f_name)))
				{
					printf("ERROR : '%s' File is a Duplicate File\n",argv[i]);
					flag = 1;
					break;
				}
				temp = temp -> link;
			}
			if(flag == 0)
			{
				insert_last(Head,argv[i]);
			}
		}
	}
	print_list(*Head);
}
int insert_last(Flist **head,char * f_name)
{
	Flist * new =malloc(sizeof(Flist));
	if(new == NULL)
	{
		return FAILURE;
	}
	new -> f_name = f_name;
	new -> link = NULL;
	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}
	Flist * temp = *head;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}
void print_list(Flist *head)
{
	if (head == NULL)
	{
		printf("INFO : Pass Some Valid Files\n");
	}
	else
	{
		while (head)
		{
			printf("%s -> ", head -> f_name);
			head = head -> link;
		}

		printf("NULL\n");
	}
}

