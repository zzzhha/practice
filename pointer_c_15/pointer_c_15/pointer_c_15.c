#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

//8.9.10.11²»»á

////8
//#define BUFFER_SIZE 64
//void
//dump(FILE* stream)
//{
//	long offset;
//	unsigned char data[16];
//	int len;
//	char buffer[BUFFER_SIZE];
//	/*
//	** Initialize the buffer that will be used for output.
//	*/
//	memset(buffer, ' ', BUFFER_SIZE - 1);
//	buffer[45] ='*';
//	buffer[62] = '*';
//	buffer[BUFFER_SIZE-1] = '\0';
//	offset = 0;
//	while ((len = fread(data, 1, 16, stream)) > 0) {
//		char* hex_ptr;
//		char* char_ptr;
//		int i;
//		/*
//		** Start building the output buffer with the offset.
//		*/
//		sprintf(buffer, "%06X ", offset);
//		/*
//		** Prepare pointers to the hex and character portions of the
//		** buffer and initialize them to spaces.
//		*/
//		hex_ptr = buffer + 8;
//		char_ptr = buffer + 46;
//		memset(hex_ptr, ' ', 35);
//		memset(char_ptr, ' ', 16);
//		/*
//		** Now translate the data to both of the output forms and store
//		** it in the buffer.
//		*/
//		for (i = 0; i < len; i += 1) {
//			/*
//			** Convert the next character to hex. Must overwrite
//			** the NUL that sprintf inserts with a space.
//			*/
//			sprintf(hex_ptr, "%02X", data[i]);
//			hex_ptr += 2;
//			*hex_ptr =' ';
//			/*
//			** Leave a space between each group of 4 values in the
//			** hex portion of the line.
//			*/
//			if (i % 4 == 3)
//				hex_ptr++;
//			/*
//			** If the character is printable, put it in the char
//			** portion of the line, else put a dot in.
//			*/
//			if (isprint(data[i]) || data[i] == ' ')
//				*char_ptr++ = data[i];
//			else
//				*char_ptr++ = '.';
//		}
//		puts(buffer);
//		offset += len;
//	}
//}
///*
//** Main program. Dump the file (if there is an argument) or stdin.
//*/
//int
//main(int ac, char** av)
//{
//	if (ac <= 1)
//		dump(stdin);
//	else {
//		FILE* stream;
//		stream = fopen(av[1], "rb");
//		if (stream == NULL) {
//			perror(av[1]);
//			exit(EXIT_FAILURE);
//		}
//		dump(stream);
//		fclose(stream);
//	}
//	return EXIT_SUCCESS;
//}
////7
//int main()
//{
//	char buffer[512];
//	while (fgets(buffer, 512, stdin) != NULL) {
//		int age[10];
//		int members;
//		int sum;
//		int i;
//		members = sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d",
//			age, age + 1, age + 2, age + 3, age + 4, age + 5, age + 6,
//			age + 7, age + 8, age + 9);
//		if (members == 0)
//			continue;
//		sum = 0;
//		for (i = 0; i < members; i += 1)
//			sum += age[i];
//		printf("%5.2f: %s", (double)sum / members, buffer);
//	}
//}
////6
//int numericc_palindrome(int value)
//{
//	int n = value;
//	int ret, sum=0;
//	while (n != 0)
//	{
//		ret = value % 10;
//		sum = sum * 10 + ret;
//		n /= 10;
//	}
//	if (sum == value)
//	{
//		printf("yes");
//	}
//	else
//		printf("no");
//}
////5
//int main()
//{
//	int count = 0;
//	FILE* input;
//	FILE* output;
//	FILE* openfile();
//	input = openfile("Input", "r");
//	output = openfile("Output", "w");
//	char arr[85];
//	while (fgets(arr, 80, input) != NULL)
//	{
//		count += strlen(arr);
//		fputs(arr, output);
//	}
//	fclose(input);
//	fclose(output);
//	return 0;
//}
////4
//int main()
//{
//	FILE* input;
//	FILE* output;
//	FILE* openfile();
//	input = openfile("Input", "r");
//	output = openfile("Output", "w");
//	char arr[85];
//	while (fgets(arr, 80, input) != NULL)
//		fputs(arr, output);
//	fclose(input);
//	fclose(output);
//	return 0;
//}
////3
//int main()
//{
//	char arr[85];
//	
//	while(fgets(arr, 80, stdin)!=NULL)
//	{
//		for (int i = 0; i < strlen(arr); i++)
//		{
//			printf("%c\n", arr[i]);
//		}
//	}
//}
////2
//int main()
//{
//	char arr[85];
//	fgets(arr, 80, stdin);
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		printf("%c\n", arr[i]);
//	}
//	return 0;
//}
////1
//int main()
//{
//	char ch=getch();
//	printf(ch);
//	printf("\n");
//	return 0;
//}