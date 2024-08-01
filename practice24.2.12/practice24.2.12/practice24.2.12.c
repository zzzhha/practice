#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBKS 10
//struct book
//{
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//	int flag;
//};
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	char* find;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		find = strchr(st, '\n');
//		if (find)
//			*find = '\0';
//		else while (getchar() != '\n')
//			continue;
//	}
//	return ret_val;
//}
//void mkfile()
//{
//	FILE* fp = fopen("book.dat", "a");
//	fclose(fp);
//}
//int main()
//{
//	struct book library[MAXBKS];
//	int count = 0;
//	int index, filecount;
//	FILE* pbooks;
//	int size = sizeof(struct book);
//	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
//	{
//		mkfile();
//		fputs("Can't open book.dat file\n", stderr);
//		exit(1);
//	}
//	rewind(pbooks);
//	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
//	{
//		if (count == 0)
//		{
//			puts("Current contents of book.dat:");
//		}
//		printf("%s by %s $%.2f\n", library[count].title, library[count].author, library[count].value);
//		count++;
//	}
//	filecount = count;
//	if (count == MAXBKS)
//	{
//		fputs("The book.dat file is full.", stderr);
//		exit(2);
//	}
//	puts("Please add new book titles.");
//	puts("Press [enter] at the start of a line to stop.");
//	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
//	{
//		puts("Now enter the author.");
//		s_gets(library[count].author, MAXAUTL);
//		puts("Now enter the value");
//		scanf("%f", &library[count].value);
//		library[count++].flag = 1;
//		while (getchar() != '\n')
//		{
//			continue;
//		}
//		if (count < MAXBKS)
//		{
//			puts("Enter the next title");
//		}
//	}
//	if (count > 0)
//	{
//		puts("Here is the list of your books:");
//		for (index = 0; index < count; index++)
//		{
//			printf("%s by %s:$%.2f\n", library[index].title, library[index].author, library[index].value);
//		}
//		int fn;
//		char a[MAXTITL];
//		puts("Do you wanna delete your book(1/0)?");
//		while (scanf("%d", &fn) == 1 && fn)
//		{
//			puts("Input the bppk name that you wanna delete:");
//			scanf("%s", a);
//			int i;
//			for (i = 0; i < count; i++)
//			{
//				if (!strcmp(library[i].title, a))
//				{
//					library[i].flag = 0;
//					break;
//				}
//			}
//			if (i == count)
//			{
//				printf("There is no book named %s\n", a);
//			}
//			puts("Do you wanna delete your book again(1/0)?");
//		}
//		puts("Do you wanna change the info of your books(1/0)?");
//		while (scanf("%d", &fn) == 1 && fn)
//		{
//			puts("Input the book name that you wanna change:");
//			scanf("%s", a);
//			int i;
//			for (i = 0; i < count; i++)
//			{
//				if (!strcmp(library[i].title, a))
//				{
//					puts("Now enter the author.");
//					scanf("%s", library[i].author);
//					puts("Now enter the value.");
//					scanf("%s", library[i].value);
//					while (getchar() != '\0')
//					{
//						continue;
//					}
//					break;
//				}
//			}
//			if (i == count)
//			{
//				printf("There is no book named %s\n", a);
//			}
//			puts("Do you wanna delete your book again(1/0)?");
//		}
//		fclose(pbooks);
//		FILE* fp = fopen("book.dat", "w");
//		int j;
//		for (j = 0; j < count; j++)
//		{
//			if (library[j].flag)
//			{
//				fwrite(&library[j], size, 1, fp);
//			}
//		}
//		fclose(fp);
//	}
//	else 
//	{
//		puts("No books? Too bad!\n");
//	}
//	puts("Bye.\n");
//	return 0;
//}
//int a;
//static int b;
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	static int c = 0;
//	int i = 0;
//	extern int a;
//	for (; i < 5; i++)
//	{
//		static int d = 0;
//		static int f;
//		printf("%d%d%d%d%d\n", a, b, c,d,f);
//		a++, b++, c++,d++,f++;
//		printf("%d%d%d%d%d\n", a, b, c,d,f);
//	}
//	printf("%d%d%d\n", a, b, c);
//	int g = add(a, b);
//	printf("%d\n", g);
//	printf("%d", a);
//	return 0;
//}
//#define MAX 10
//struct member {
//	char first_name[20];
//	char last_name[20];
//	int bat;
//	int hit;
//	int walk;
//	int RBI;
//	float average;
//};
//void clear(struct member* p)
//{
//	int i;
//	for (i = 0; i < MAX; i++)
//	{
//		strcpy(p[i].first_name, "");
//		strcpy(p[i].last_name, "");
//		p[i].bat = 0;
//		p[i].hit = 0;
//		p[i].walk = 0;
//		p[i].RBI = 0;
//		p[i].average = 0;
//	}
//}
//void get_info(struct member* p)
//{
//	int number, bat, hit, walk, RBI;
//	char firstname[20], lastname[20], filename[20] = "c:\\info.txt";
//	FILE *fp;
//	printf("input the file name:");
//	scanf("%s", filename);
//	while (fscanf(fp, "%d %s %s %d %d %d %d\n", &number, firstname, lastname, &bat, &walk, &RBI) == 7)
//	{
//		strcpy(p[number].first_name, firstname);
//		strcpy(p[number].last_name, lastname);
//		p[number].bat += bat;
//		p[number].hit += hit;
//		p[number].walk += walk;
//		p[number].RBI += RBI;
//	}
//	fclose(fp);
//}
//void cal_average(struct member* p)
//{
//	int i;
//	for (i = 0; i < MAX; i++)
//	{
//		if (p[i].bat)
//		{
//			p[i].average = (float)p[i].hit / (float)p[i].bat;
//		}
//	}
//}
//void display(struct member* p)
//{
//	int i;
//	struct member total = { "","",0,0,0,0,0 };
//	printf("%7s%10s%s10%5s%5s%5s%5s%10s\n""number", "firstname", "lastname",
//		"bat", "hit", "walk", "RBI", "average");
//	for (i = 0; i < MAX; i++)
//	{
//		if (p[i].bat)
//		{
//			printf("%7d%10s%10s%5d%5d%5d%5d%10g\n", i, p[i].first_name, p[i].last_name, p[i].bat, p[i].hit, p[i].walk, p[i].RBI, p[i].average);
//			total.bat += p[i].bat;
//			total.bat += p[i].bat;
//			total.hit += p[i].hit;
//			total.walk += p[i].walk;
//			total.RBI += p[i].RBI;
//		}
//		if(total.bat)
//		{
//			total.average = 1.0*total.hit / total.bat;
//			printf("%27s%5d%5d%5d%5d%10g\n", "total team", total.bat, total.hit, total.walk, total.RBI, total.average);
//		}
//	}
//}
//int main()
//{
//	struct member members[MAX];
//	clear(members);
//	get_info(members);
//	cal_aveerage(members);
//	display(members);
//	return 0;
//}
//struct name {
//	char first_name[20];
//	char last_name[20];
//};
//struct student {
//	struct name full_name;
//	float grade[3];
//	float average;
//};
//void get_name_grade(struct student *list)
//{
//	char f_name[20];
//	char l_name[20];
//	int i = 0;
//	for (; i < 4; i++)
//	{
//		printf("input your the no.%d student first name(<20):",i+1);
//		fgets(f_name, 20, stdin);
//		printf("input your the no.%d student last name(<20):",i+1);
//		fgets(l_name, 20, stdin);
//		strcpy(list[i].full_name.first_name,f_name);
//		strcpy(list[i].full_name.last_name, l_name);
//		printf("input your the no.%d student score.(three float):",i+1);
//		scanf("%f%f%f", &list[i].grade[0], &list[i].grade[1], &list[i].grade[2]);
//	}
//}
//void get_average(struct student *list)
//{
//	int i = 0;
//	for (; i < 4; i++)
//	{
//		list[i].average = (list[i].grade[1] + list[i].grade[2] + list[i].grade[3]) / 3;
//	}
//}
//void printf_info(struct student* list)
//{
//	int i = 0;
//	for (; i < 0; i++)
//	{
//		printf("the no.%d information is:\n", i + 1);
//		printf("%s %s per lesson grade is:%f,%f,%f and average is:%.2f\n",
//			list[i].full_name.first_name, list[i].full_name.last_name,
//		list[i].grade[1], list[i].grade[2], list[i].grade[3],list[i].average);
//	}
//}
//void get_all_average(struct student* list)
//{
//	float average = (list[0].average + list[1].average + list[2].average + list[3].average) / 4;
//	printf("the all average is %.2f", average);
//}
//int main()
//{
//	struct student list[4];
//	get_name_grade(list);
//	get_average(list);
//	printf_info(list);
//	get_all_average(list);
//	return 0;
//}