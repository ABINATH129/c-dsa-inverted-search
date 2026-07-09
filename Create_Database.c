#include "Header.h"
int create_database(Flist * head,M_node ** Index)
{
	int flag = 0;
	while(head != NULL)
	{
		while(head != NULL && check_Database_Updated(head,Index) == FAILURE )
		{
			head = head -> link;
		}
		if(head == NULL)
		{
			break;
		}
		FILE * fp = fopen(head->f_name,"r");
		char word[50];
		while(1)
		{	
			fscanf(fp,"%s",word);
			if(feof(fp))
                        {
                                break;
                        }
			int i = find_index(word[0]);
			flag = 1;
			if(Index[i] == NULL)
			{
				create_main_node(&(Index[i]),1,word,NULL);
				create_sub_node(&(Index[i] -> sub_link),head -> f_name,1);
			}
			else
			{
				M_node * temp = Index[i];
				int flag = 0;
				while(temp != NULL)
				{
					if(!(strcmp(word,temp -> word)))//compare new word with words already present in that index
					{
						if(!(strcmp((temp -> sub_link)-> f_name,head -> f_name)))
						{
							((temp -> sub_link) -> word_count)++;
						}
						else
						{
							create_sub_node(&(temp -> sub_link),head -> f_name,1);
							(temp -> file_count)++;
						}
						flag = 1;
					}
					temp = temp -> main_link;
				}
				if(flag == 0)//if word not present
				{
					create_main_node(&(Index[i]),1,word,NULL);
					create_sub_node(&(Index[i] -> sub_link),head -> f_name,1);
				}
			}
		}
		fclose(fp);
		head = head -> link;
	}
	if(flag == 1)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
int find_index(char ch)
{
	if(isalpha(ch))
	{
		ch = toupper(ch);
		return ch - 'A';
	}
	else
	{
		return 26;
	}
}
int create_sub_node(S_node ** sub_head,char * f_name,int word_count)
{
	S_node * new =malloc(sizeof(S_node));
	if(new == NULL)
	{
		return FAILURE;
	}
	strcpy(new -> f_name,f_name);
	new -> word_count = word_count;
	new -> link = *sub_head;
	*sub_head = new;
	return SUCCESS;
}
int create_main_node(M_node ** main_head,int file_count,char * word,S_node * sub_head)
{
	M_node * new =malloc(sizeof(M_node));
	if(new == NULL)
	{
		return FAILURE;
	}
	new -> file_count = file_count;
	strcpy(new -> word,word);
	new -> main_link = *main_head;
	new -> sub_link = sub_head;
	*main_head = new;
	return SUCCESS;
}
int check_Database_Empty(M_node ** Index)
{
	for(int i=0;i<27;i++)
	{
		if(Index[i] != NULL)
		{
			return FAILURE;
		}
	}
	return SUCCESS;
}
int check_Database_Updated(Flist * head,M_node ** Index)
{
	//traverse to all nodes and check whether any new files passed through command line arguments
 	for(int i=0;i<27;i++)
	{
		M_node * temp = Index[i];
		while(temp != NULL)
		{
			S_node * sub_temp = temp -> sub_link;
			while(sub_temp != NULL)
			{
				if(!(strcmp(head -> f_name,sub_temp -> f_name)))
				{
					return FAILURE;
				}
				sub_temp = sub_temp -> link;
			}
			temp = temp -> main_link;
		}
	}
	return SUCCESS;
}
