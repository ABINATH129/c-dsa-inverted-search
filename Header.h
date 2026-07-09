#ifndef Header_H
#define Header_H

// Inclusion of Neccessary Header Files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defining Structures for Linked List Nodes

typedef struct File_node
{
	char * f_name;
	struct File_node * link;
}Flist;//structure for valid file names from command line arguments
typedef struct Main_node
{
	int file_count;
	char word[50];
        struct Main_node * main_link;
        struct Sub_node * sub_link;
}M_node;//structure for main node
typedef struct Sub_node
{
        char f_name[50];
	int word_count;
        struct Sub_node * link;
}S_node;//structure for sub node

// Defining Macros from Better Readability

#define SUCCESS 1
#define FAILURE 0

// Neccessary Function Prototypes To Implement Inverted Search

void validate(int,char *[],Flist **);
int insert_last(Flist **,char *);
void print_list(Flist *);
int find_index(char);
int create_main_node(M_node **,int,char *,S_node *);
int create_sub_node(S_node **,char *,int);
int check_Database_Empty(M_node **);
int check_Database_Updated(Flist *,M_node **);
int Save_Database(M_node ** );

int create_database(Flist *,M_node **);
int Display_Database(M_node **);
int Search_word(M_node **);
int Save_Database(M_node **);
int Update_Database(M_node **);
#endif
