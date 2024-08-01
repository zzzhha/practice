#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	return 0;
}
//int main()
//{
//	char arr[10];
//	scanf("%s", arr);
//	int arr2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	char* arr3[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
//	int i = 0;
//	int count = 0;
//	for (; i < 12; i++)
//	{
//		if (strcmp(arr, arr3[i])==0)
//		{
//			break;
//		}
//		else
//		{
//			count++;
//		}
//	}
//	int sum = 0;
//	for (i = 0; i <= count; i++)
//	{
//		sum += arr2[i];
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main(int argc, char* argv[])
//{
//	FILE* fp;
//	int count = 0;
//	int para_count = 1;
//	char ch;
//	if (argc < 2)
//	{
//		exit(EXIT_FAILURE);
//	}
//	if (strlen(argv[1]) != 1)
//	{
//		exit(EXIT_FAILURE);
//	}
//	if(argc==2)
//	{
//		while ((ch = getchar()) != EOF)
//		{
//			if (ch == argv[1][0])
//			{
//				count++;
//			}
//		}
//		printf("there are %d character '%c' in your input\n",count,argv[1][0]);
//	}
//	else
//	{
//		while (++para_count < argc)
//		{
//			count = 0;
//			if (fp = fopen(argv[para_count], "r") == NULL)
//			{
//				continue;
//			}
//			while (ch = getc(fp) != EOF)
//			{
//				if (ch == argv[1][0])
//				{
//					count++;
//				}
//			}
//			printf("There are %d character '%c' in file %s.\n", count, argv[1][0],argv[para_count]);
//			fclose(fp);
//		}
//	}
//	return 0;
//}
//int main(int argc,char *argv[])
//{
//	char* line_one = (char*)malloc(256 * sizeof(char));
//	char* line_two = (char*)malloc(256 * sizeof(char));
//	int first_end = 1;
//	if (argc != 3)
//	{
//		exit(EXIT_FAILURE);
//	}
//	FILE* fp1, * fp2;
//	if (fp1 = fopen(argv[1],"r") == NULL)
//	{
//		exit(EXIT_FAILURE);
//	}
//	if (fp2 = fopen(argv[2], "r") == NULL)
//	{
//		exit(EXIT_FAILURE);
//	}
//	int i = 1;
//	while(fgets(line_one,256,fp1)!=NULL)
//	{
//		if (fgets(line_two, 256, fp2) != NULL)
//		{
//			printf("file 1 line no.%d:%s", i, line_one);
//			printf("file 2 line no.%d:%s", i, line_two);
//			i++;
//		}
//		else
//		{
//			printf("file 1 line no.%d:%s", i, line_one);
//			i++;
//		}
//	}
//	while (fgets(line_two, 256, fp2) != NULL)
//	{
//		printf("file 2 line no.%d:%s", i, line_two);
//		i++;
//	}
//	printf("COMBINE line");
//	rewind(fp1);
//	rewind(fp2);
//	i = 1;
//	while (fgets(line_one, 256, fp1) != NULL)
//	{
//		if (fgets(line_two, 256, fp2) != NULL)
//		{
//			while (*line_one != '\n')
//				putchar(*line_one++);
//			putchar('+');
//			printf(" &s",line_two);
//			i++;
//		}
//		else
//		{
//			printf("file 1 line no.%d:%s", i, line_one);
//			i++;
//		}
//	}
//	while (fgets(line_two, 256, fp2) != NULL)
//	{
//		printf("file 2 line no.%d:%s", i, line_two);
//	}
//	fclose(fp1);
//	fclose(fp2);
//	return 0;
//}
//int main()
//{
//	FILE *in, *out;
//	int ch;
//	char name[40];
//	int count = 0;
//	printf("input the file name:");
//	char file_name[40];
//	scanf("%s", file_name);
//	if (in = fopen(file_name, "w")== NULL)
//	{
//		exit(EXIT_FAILURE);
//	}
//	strncpy(name, file_name, 35);
//	name[35] = '\0';
//	strcat(name, ".red");
//	if (out = fopen(name, "w") == NULL)
//	{
//		exit(3);
//	}
//	while (ch = getc(in) != EOF)
//		if (count++ % 3 == 0)
//			putc(ch, out);
//	if (fclose(in) != 0 || fclose (out) != 0)
//		fprintf(stderr, "error\n");
//	return 0;
//}
//void append(FILE* source, FILE* dest)
//{
//	size_t bytes;
//	static char temp[4096];
//	while (bytes = fread(temp, sizeof(char), 4096, source) > 0)
//		fwrite(temp, sizeof(char), bytes, dest);
//}
//int main(int argc, char* argv[])
//{
//	FILE *fa, *fs;
//	int files = 0;
//	char file_app[81];
//	char file_src[81];
//	int ch;
//	if (argc < 3)
//	{
//		fprintf(stderr, "usage:%s dest_file src_file.\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	if(fa = (fopen(argv[1], "a+")) == NULL)
//	{
//		fprintf(stderr, "Can't open %s\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	if (setvbuf(fa, NULL, _IOFBF, 4096) != 0)
//	{
//		fputs("can't create input buffer\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	files = argc - 2;
//	while (files > 0)
//	{
//		if (fs = fopen(argv[argc - files], "r") == NULL)
//		{
//			fprintf(stderr, "Can't open %s\n", argv[1]);
//		}
//		else
//		{
//			if (setvbuf(fs, NULL, _IOFBF, 4096) != 0)
//			{
//				fputs("Can't create input buffer\n", stderr);
//				continue;
//			}
//			append(fs, fa);
//			if (ferror(fs) != 0)
//			{
//				fprintf(stderr, "Error in reading file %s.\n", file_src);
//			}
//			if (ferror(fa) != 0)
//			{
//				fprintf(stderr, "Error in reading file %s.\n", file_app);
//			}
//			fclose(fs);
//			printf("file %s appended.\n", file_src);
//			if (files > 0)
//				printf("file %s appended.\n", argv[argc - (--files)]);
//			else
//				printf("NO more and %d files appended.\n");
//		}
//	}
//	printf("done appending,and %d files appended.\n", argc - 2);
//	rewind(fa);
//	printf("%s contents:\n", file_app);
//	while ((ch = getc(fa))!= EOF)
//	{
//		putchar(ch);
//	}
//	puts("done displaying.");
//	fclose(fa);
//	return 0;
//}
//int main(int atgc,char *argv[])
//{
//	int ch;
//	FILE* fp;
//	unsigned long count = 0;
//	char file_name[50];
//	printf("Input the filename:");
//	scanf("%s", file_name);
//	if (fp = fopen(file_name, "r") == NULL)
//	{
//		printf("Can't open %s\n", a);
//		exit(EXIT_FAILURE);
//	}
//	while ((ch=getc(fp))!=EOF)
//	{
//		putc(ch, stdout);
//		count++;
//	}
//	fclose(fp);
//	printf("File %s has %lu characters\n", a, count);
//	return 0;
//}
//int main()
//{
//	printf("how many words do you wish to enter?");
//	int n;	
//	scanf("%d", &n);
//	printf("Enter %d words now:", n);
//	char**pst=(char**)malloc(n * sizeof(char*));
//	int i = 0;
//	for (; i < n; i++)
//	{
//		char arr[100];
//		scanf("%s", arr);
//		int length = strlen(arr);
//		char* str = (char*)malloc(length * sizeof(char));
//		strcpy(str, arr);
//		*(pst + i) = str;
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%s\n", *(pst + i));
//	}
//	free(pst);
//	free(str);
//	printf("done");
//	return 0;
//}
//int* make_array(int elem, int val)
//{
//	int* ps = (int*)malloc(elem*4);
//	if (ps)
//	{
//		int i = 0;
//		for (; i < elem; i++)
//		{
//			ps[i] = val;
//		}
//		return ps;
//	}
//	else
//		return NULL ;
//}
//void show_array(const int arr[], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		for (; i < 8||i<n; i++)//或者if((i+1)%8==0)putchar('\n');
//		{
//			printf("%d", arr[i]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int* pa;
//	int size;
//	int value;
//	printf("enter the number of elements");
//	while (scanf("%d", &value) == 1 && size > 0)
//	{
//		printf("enter the initialization value:");
//		scanf("%d", &size);
//		pa = make_array(size, value);
//		if (pa)
//		{
//			show_array(pa, size);
//			free(pa);
//		}
//		printf("Enter the number if elements(<1 to quit);");
//	}
//	printf("Done");
//	return 0;
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int i = 1;
//	int arr[15] = { 0 };
//	for (; i < 1000; i++)
//	{
//		int ret = rand()%10;
//		arr[ret]++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d出现了%d次",i,arr[i]);
//	}
//	return 0;
//}