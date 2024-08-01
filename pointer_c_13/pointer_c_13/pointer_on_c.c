#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


//5.
#define TRUE 1
#define FALSE 0
#define NULL 0
#define NUL '\0'
enum { NONE, FLAG, ARG };

argtype(int ch,int* control)
{
	while (*control != NUL)
		if (ch == *control++)
			return *control =='+' ? ARG : FLAG;
	return NONE;
}
/*
** Process the arguments.
*/
char** do_args(int ac, char** av, char* control,
	void (*do_arg)(int, char*), void (*illegal_arg)(int))
{
	register char* argp;
	register int ch;
	register int skip_arg;
	while ((argp = *++av) != NULL && *argp == '-') {
		skip_arg = FALSE;
		while (!skip_arg && (ch = *++argp) != NUL) {
			switch (argtype(ch, control))
			{
			case FLAG:
				(*do_arg)(ch, NULL);
				break;
			case ARG:
				if (*++argp != NUL || (argp = *++av) != NULL) {
					(*do_arg)(ch, argp);
					skip_arg = TRUE;
					break;
				}
				(*illegal_arg)(ch);
				return av;
			case NONE:
				(*illegal_arg)(ch);
				break;
			}
		}
	}
	return av;
}

////4.
//void swap(char* buffer1, char* buffer2,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		char t = *buffer1;
//		*buffer1 = *buffer2;
//		*buffer2 = t;
//		buffer1++;
//		buffer2++;
//	}
//}
//void my_qsort(void* arr, int num, int sz, int(*my_cmp)(const void* a, const void* b))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if ((my_cmp((char*)arr + j * sz, (char*)arr + (j + 1) * sz) > 0))
//			{
//				swap((char*)arr + j * sz, (char*)arr + (j + 1) * sz,sz);
//			}
//		}
//	}
//}
////3.
//typedef struct NODE
//{
//	struct NODE* next;
//	struct NODE* prev;
//	int value;
//}Node;
//typedef struct Transaction
//{
//	int type;
//}Transaction;
//
//Node* list;
//Node* current;
//Transaction* transaction;
//void add_new_trans(Node* list, Node** current, Transaction* trans);
//void delete_trans(Node* list, Node** current, Transaction* trans);
//void search(Node* list, Node** current, Transaction* trans);
//void edit(Node* list, Node** current, Transaction* trans);
//void forward(Node* list, Node** current, Transaction* trans)
//{
//	*current = (*current)-> next;
//}
//void backward(Node* list, Node** current, Transaction* trans)
//{
//	*current = (*current)->prev;
//}
//void (*function[])(Node* list, Node** current, Transaction* trans) =
//{
//	add_new_trans,
//	delete_trans,
//	forward,
//	backward,
//	search,
//	edit
//};
//#define N_TRANSACTIONS ( sizeof( function ) / sizeof( function[0]))
//int main()
//{
//	
//	scanf("%d", &transaction->type);
//	if (transaction->type < 0 || transaction->type >= N_TRANSACTIONS)
//		printf("Illegal transaction type!\en");
//	else
//		function[transaction->type](list, &current, transaction);
//	return 0;
//}
////2.
//typedef struct NODE
//{
//	struct NODE* next;
//	int value;
//}node;
//
//void dll_Traversal(node* rootp, void(*p)(node** dest))
//{
//	node* current;
//	for (current = rootp; current != NULL; current = current->next)
//	{
//		p(current);
//	}
//}
////1
//int is_not_print(int ch)
//{
//	return !isprint(ch);
//}
//
//static int(*test_func[])(int) =
//{
//	iscntrl,
//	isspace,
//	isdigit,
//	islower,
//	isupper,
//	ispunct,
//	is_not_print
//};
//char* label[] = {
//		"control",
//		"whitespace",
//		"gigit",
//		"lower case",
//		"upper case",
//		"punctuation",
//		"non-printable"
//};
//int count[7];
//int total;
//int main()
//{
//	int ch;
//	int category;
//	while ((ch = getchar()) != EOF)
//	{
//		total++;
//		for (category = 0; category < 7; category++)
//		{
//			if (test_func[category](ch))
//				count[category]++;
//		}
//	}
//	if (total == 0)
//		printf("no characters in the input!\n");
//	else
//	{
//		for (category = 0; category < 7; category++)
//		{
//			printf("%3.0f%% %s characters\n", count[category] * 100.0 / total, label[category]);
//		}
//	}
//	return 0;
//}