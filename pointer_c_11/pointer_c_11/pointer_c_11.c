#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void* my_calloc(int num,int size)
{
	void* p = malloc(num * size);
	if (p == NULL)
	{
		return NULL;
	}
	memset(p, 0, num * size);
	return p;
}
int* read()
{
	int* arr;
	int size;
	int count;
	int value;
	size = 100;
	arr = malloc((size + 1) * sizeof(int));
	if (arr == NULL)
	{
		return NULL;
	}
	count = 0;
	while (scanf("%d", &value) == 1)
	{
		count++;
		if (count > size)
		{
			size += 100;
			arr = realloc(arr, (size + 1) * sizeof(int));
			if (arr == NULL)
			{
				return NULL;
			}
		}
		arr[count] = value;
	}
	if (count < size) {
		arr = realloc(arr, (count + 1) * sizeof(int));
		if (arr = NULL)
			return NULL;
	}
	arr[0] = count;
	return arr;
}
char* readstring()
{
	static char* buffer = NULL;
	static int buffer_size = 0;
	int ch;
	int len;
	char* bp;
	bp = buffer;
	len = 0;
	do {
		ch = getchar();
		if (ch == '\n' || ch == EOF)
			ch = '\0';
		/*
		** If the buffer is full, make it bigger.
		*/
		if (len >= buffer_size) {
			buffer_size += 100;
			buffer = realloc(buffer, buffer_size);
			assert(buffer != NULL);
			bp = buffer + len;
		}
		*bp++ = ch;
		len += 1;
	} while (ch != '\0');
	bp = malloc(len);
	assert(bp != 0);
	strcpy(bp, buffer);
	return bp;
}

typedef struct NODE {
	int value;
	struct NODE* link;
} Node;
Node* newnode(int value) {
	Node* new;
	new = (Node*)malloc(sizeof(Node));
	assert(new != 0);
	new -> value = value;
	return new;
}
int main()
{
	Node* head;
	head = newnode(5);
	head -> link = newnode(10);
	head -> link-> link = newnode(15);
	head -> link-> link-> link = 0;
	return 0;
}
