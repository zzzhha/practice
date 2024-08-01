#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE 
{
	struct NODE* link;
	int value;
}Node;

typedef struct NODe
{
	struct NODe* fwd;
	struct NODe* bwd;
	int value;
}node;
//7不会
#define TRUE 1
#define FALSE 0
typedef struct WORD {
	char* word;
	struct WORD* next;
} Word;
typedef struct LIST {
	char letter;
	struct LIST* next;
	Word* word_list;
} List;
int
concordance_insert(List** listp, char* the_word)
{
	int first_char;
	List* current_list;
	Word* current_word;
	Word** wordp;
	int comparison;
	Word* new_word;
	/*
	** Get the first character of the word and make sure it is valid.
	*/
	first_char = *the_word;
	if (!islower(first_char))
		return FALSE;
	/*
	** First, find the word list that begins with the right letter. If it
	** does not exist, create a new one and add it.
	*/
	while ((current_list = *listp) != NULL
		&& current_list->letter < first_char)
		listp = &current_list->next;
	/*
	** If current_list is NULL or points to a node with a letter larger
	** than what we want, we’ve got to create a new word list and insert it
	** here in the primary list.
	*/
	if (current_list == NULL || current_list->letter > first_char) {
		List* new_list;
		new_list = (List*)malloc(sizeof(List));
		if (new_list == NULL)
			return FALSE;
		new_list->letter = first_char;
		new_list->word_list = NULL;
		new_list->next = current_list;
		*listp = new_list;
		current_list = new_list;
	}
	/*
** current_list now points to the node that heads the proper word list.
** Search down through it looking for our word.
*/
	wordp = &current_list->word_list;
	while ((current_word = *wordp) != NULL) {
		comparison = strcmp(current_word->word, the_word);
		if (comparison >= 0)
			break;
		wordp = &current_word->next;
	}
	/*
	** If current_word not NULL and comparison is 0, the word already is in
	** the list.
	*/
	if (current_word != NULL && comparison == 0)
		return FALSE;
	/*
	** Create a new node for the word.
	*/
	new_word = (Word*)malloc(sizeof(Word));
	if (new_word == NULL)
		return FALSE;
	new_word->word = malloc(strlen(the_word) + 1);
	if (new_word->word == NULL)
		return;
	strcpy(new_word->word, the_word);
	/*
	** Link the new node into the list.
	*/
	new_word->next = current_word;
	*wordp = new_word;
	return TRUE;
}
////6
//int dll_remove(node* rootp, node* delete)
//{
//	node* current;
//	node* next;
//	node* pervious;
//	for (current = rootp->fwd; current!= NULL; current = current->fwd)
//	{
//		if (current == delete)
//			break;
//	}
//	if (current == delete)
//	{
//		if (current->bwd == NULL)
//			rootp->fwd = current->fwd;
//		else
//			current->bwd->fwd = current->fwd;
//		if (current->fwd == NULL)
//			rootp->bwd = current->bwd;
//		else
//			current->fwd->bwd = current->bwd;
//		free(current);
//		return 1;
//	}
//	else
//		return 0;
//}
////5
//int sll_remove(struct NODE** rootp, struct NODE* node)
//{
//	struct NODE* current;
//	while ((current = *rootp) != NULL && current != node)
//	{
//		rootp = &current->link;
//	}
//	if (current == node)
//	{
//		*rootp = current->link;
//		free(current);
//		return 1;
//	}
//	else
//		return 0;
//}
////4
//struct NODE* sll_reverse(struct NODE* current)
//{
//	struct NODE* previous;
//	struct NODE* next;
//	for (previous = NULL; current != NULL; current = next)
//	{
//		next = current-> link;
//		current->link = previous;
//		previous = current;
//	}
//	return previous;
//}
////3
//int dll_insert(node** frontp, node** rearp, int value)
//{
//	node** fwdp;
//	node* next;
//	node* newnode;
//	
//	for (fwdp = frontp; (next = (*fwdp)->fwd) != NULL; fwdp = &next->fwd)
//	{
//		if (next-> value == value)
//			return 0;
//		if (next->value > value)
//			break;
//
//	}
//	newnode = (node*)malloc(sizeof(node));
//	if (newnode == NULL)
//		return -1;
//	newnode->fwd = next;
//	*fwdp = newnode;/*根据前面的循环*fwdp等同于当前节点的fwd*/
//	if (fwdp != frontp)//只要进行了循环，他就不成立
//		if (next != NULL)
//			newnode->bwd = next->bwd;
//		else
//			newnode->bwd = *rearp;
//	else//没进行循环的话，此时fwdp指向frontp，此时插入节点是在开始插入
//		newnode->bwd = NULL;
//	if (next != NULL)//如果不在末尾插入节点
//		next->bwd = newnode;
//	else//在末尾插入节点
//		*rearp = newnode;
//	return 1;
//}
////2
//sll_find(struct NODE* first, int desired_value)
//{
//	for (; first != NULL; first = first-> link)
//	{
//		if (first->value == desired_value)
//			return first;
//	}
//	return NULL;
//}
////1
//int sll_count(Node** linkp)
//{
//	int count = 0;
//	while ((*linkp) != NULL)
//	{
//		linkp = &((*linkp)->link);
//		count++;
//	}
//	return count;
//}
////12_3改写
//#define FALSE 0
//#define TRUE 1

//int sll_insert(Node** linkp, int new_value)
//{
//	Node* new;
//
//	while ((*linkp) != NULL && (*linkp)->value < new_value)
//	{
//		linkp = &((*linkp)->link);
//	}
//	new = (Node*)malloc(sizeof(Node));
//	if (new == NULL)
//		return FALSE;
//	new->value = new_value;
//	new->link = *linkp;
//	*linkp = new;
//	return TRUE;
//}
