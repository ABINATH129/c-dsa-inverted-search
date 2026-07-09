#include "Header.h"
int Search_word(M_node ** Index)
{
	if(check_Database_Empty(Index) != FAILURE)
	{
		printf("ERROR : Database is Empty\n");
		return FAILURE;
	}
	char key[50];
	printf("Enter the Word Need to Searched in Database : ");
	scanf("%s",key);
	int i = find_index(key[0]);
	M_node * temp = Index[i];
	int flag = 0;
	while(temp)
	{
		if(!(strcmp(key,temp -> word)))// search for a word in its index 
		{
			flag = 1;
			printf("Word '%s' is Found in %d File(s)\n",key,temp -> file_count);
			S_node * sub_temp = temp -> sub_link;
			while(sub_temp)
			{
				printf("%d time(s) Present in '%s' File\n",sub_temp -> word_count,sub_temp -> f_name);
				sub_temp = sub_temp -> link;
			}
		}
		temp = temp -> main_link;
	}
	if(flag == 0)
	{
		printf("Word '%s' is not Found in Database\n",key);
	}
}
