#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct vector {
	int size;
	int count;
	int* data;
}vector;


vector * get_new_vector(int n)//初始化
{
	vector* p = (vector*)malloc(sizeof(vector));
	p->size = n;
	p->count = 0;
	p->data = (int*)malloc(sizeof(int) * n);
	return p;
}

int expand(vector* v)
{
	if (v == NULL) return 0;
	printf("expand v form %d to %d\n", v->size, 2 * v->size);
	int *p = (int*)realloc(v->data, sizeof(int) * 2 * v->size);
	if (p == NULL) return;
	v->data = p;
	v->size *= 2;
	return 1;
}
int insert_vector(vector* v, int pos, int val)
{
	if (pos < 0 || pos > v->count)
		return 0;
	if ((v->size == v->count) && (!expand(v)))
		return 0;
	for (int i = v->count - 1 ; i >= pos; i--)
	{
		v->data[i + 1] = v->data[i];
	}
	v->data[pos] = val;
	v->count++;
	return 1;
}

int my_detele_vector(vector* v, int value)//自己实现版
{
	if (v->count == 0)
		return 0;
	for (int i = 0; i < v->count; i++)
	{
		if (v->data[i] == value)
		{
			for (; i < v->count-1; i++)
			{
				v->data[i]=v->data[i+1];
			}
			v->data[i] = 0;
		}
	}
	v->count--;
	return 1;
}

int erase(vector* v, int pos)//老师的
{
	if (pos < 0 || pos >= v->count)
		return 0;
	for (int i = pos+1; i < v->count; i++)
	{
		v->data[i-1] = v->data[i];
	}
	v->count--;
	return 1;
}
void output_vector(vector* v)
{
	printf("\n\n");
	int len = 0;
	for (int i = 0; i < v->size; i++)
	{
		len+=printf("%3d ",i);//计算输出了多长
	}
	printf("\n");
	for (int i = 0; i < len; i++)//输出登场的横线
	{
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < v->count; i++)
	{
		printf("%3d ", v->data[i]);
	}
	printf("\n");
}

void clear_vector(vector* v)//清空
{
	if (v == NULL) return;
	free(v->data);
	free(v);
}

#define MAX 20
int main()
{
	srand((time(0)));
	
	vector* v = get_new_vector(2);
	for (int i = 0; i < MAX; i++)
	{
		; int pos, val, op = rand() % 4, ret;
		switch (op)
		{
			case 0:
			case 1:
			case 2:
				pos = rand() % (v->count + 2);
				val = rand() % 100;
				ret = insert_vector(v, pos, val);
				printf("insert %d  at %d to vector =%d\n",val,pos, ret);
				break;
			case 3:
				pos = rand() % (v->count + 2);
				ret = erase(v, pos);
				printf("erase item at %d in vector =%d\n", pos, ret);
				break;
		}
		output_vector(v);
	}
	clear_vector(v);
	return 0;
}