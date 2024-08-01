#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main()
{
	double fahr;
	double cels;
	printf("Please input cels: ");
	scanf("%lf", &cels);
	fahr = 9.0 / 5 * cels + 32;
	printf("The fahr is: %.2f", fahr);
}
//int main()
//{
//	char* arr1[10] = {
//	"Sunday",
//	"Monday",
//	"Tuesday",
//	"Wednesday",
//	"Thursday",
//	"Friday",
//	"Saturday",
//	};
//	printf("Please enter a string:\n");
//	char arr[50];
//	gets(arr);
//	for (int i = 0; i < 7; i++)
//	{
//		if (strcmp(arr1[i], arr) == 0)
//		{
//			printf("%s is %d\n", arr, i);
//			return 0;
//		}
//	}
//	printf("Not found!\n");
//	return 0;
//}
//int main()
//{
//	int flag1 = 0;
//	int flag2 = 0;
//	int flag3 = 0;
//	int flag4 = 1;
//	int flag5 = 0;
//	int flag = 0;
//	char arr[50];
//	char sp[5] = { '@','-','_','#','~' };
//	fgets(arr, 50, stdin);
//	arr[strcspn(arr, "\n")] = 0;
//	for (int i = 0; i < strlen(arr) - 1; i++)
//	{
//		if (isdigit(arr[i]))
//		{
//			flag1=1;
//			break;
//		}
//	}
//	for (int i = 0; i < strlen(arr) - 1; i++)
//	{
//		if (islower(arr[i]))
//		{
//			flag2 = 1;
//			break;
//		}
//	}
//	for (int i = 0; i < strlen(arr) - 1; i++)
//	{
//		if (isupper(arr[i]))
//		{
//			flag3 = 1;
//			break;
//		}
//	}
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		if ((!isalnum(arr[i]))&&
//				(arr[i] != '#' || arr[i] != '~' || arr[i] != '@' || arr[i] != '_' || arr[i] != '-'))
//			{
//				flag4 = 0;
//				break;
//			}
//
//	}
//	if (strlen(arr) > 8)
//	{
//		flag5 = 1;
//	}
//
//	if (!flag4)
//	{
//		printf("密码中存在非法字符\n");
//		flag = 1;
//	}
//	if (!flag5)
//	{
//		printf("密码长度太短");
//		flag = 1;
//	}
//	int sum = flag1 + flag2 + flag3 + !flag4;
//	if (sum < 3)
//	{
//		if (!flag5)
//			printf("且密码中应包含大小写字母、数字、其它符号四种中至少三种字符");
//		else
//			printf("密码中应包含大小写字母、数字、其它符号四种中至少三种字符");
//		flag = 1;
//	}
//	if (!flag)
//	{
//		printf("密码设置成功\n");
//	}
//	return 0;
//}
//void gcd(int a, int b, int* g) 
//{
//	if (b == 0) {
//		*g = a;
//	}
//	else {
//		gcd(b, a % b, g);
//	}
//}
//void simplify(int* numerator, int* denominator) 
//{
//	int g;
//	gcd(*numerator, *denominator, &g);
//	*numerator /= g;
//	*denominator /= g;
//}
//int main()
//{
//	int a, b, c, d;
//	char o;
//	char str[100];
//	int numerator, denominator;
//	while(scanf("%s", str)!=EOF)
//	{
//		
//		sscanf(str, "%d/%d%c%d/%d", &a, &b, &o, &c, &d);
//		switch (o)
//		{
//		case '+':
//			numerator = a * d + b * c;
//			denominator = b * d;
//			break;
//		case '-':
//			numerator = a * d - b * c;
//			denominator = b * d;
//			break;
//		}
//		simplify(&numerator, &denominator);
//		if (denominator < 0)
//		{
//			numerator = -numerator;
//			denominator = -denominator;
//		}
//		if (numerator == denominator)
//		{
//			printf("1\n");
//		}
//		if (numerator == 0)
//		{
//			printf("0\n");
//		}
//		else
//		{
//			printf("%d/%d\n", numerator, denominator);
//		}
//	}
//	
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("请输入n(n<10):");
//	scanf("%d", &n);
//	char arr[10][20];
//	printf("请输入%d个字符串",n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n- 1 - i; j++)
//		{
//			if (strcmp(arr[j], arr[j + 1]) > 0)
//			{
//				char temp[50];
//				strcpy(temp, arr[j]);
//				strcpy(arr[j], arr[j + 1]);
//				strcpy(arr[j + 1], temp);
//
//			}
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[5][20];
//	printf("Input five countries' names:\n");
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5 - 1 - i; j++)
//		{
//			if (strcmp(arr[j], arr[j + 1]) > 0)
//			{
//				char temp[50];
//				strcpy(temp, arr[j]);
//				strcpy(arr[j], arr[j + 1]);
//				strcpy(arr[j + 1], temp);
//
//			}
//		}
//	}
//	printf("The minimum is:%s\n", arr[0]);
//	return 0;
//}

//int IsNumIn(char word[])
//{
//	for (int i = 0; word[i]!='\0'; i++)
//	{
//		if (isdigit(word[i]))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int IsSpcIn(char word[])
//{
//	if (strchr(word, ' ') != NULL)
//		return 1;
//	return 0;
//}
//
//void Trim(char oldWord[], char newWord[])
//{
//	int start = 0;
//	int end = strlen(oldWord) - 1;
//	while (start <= end && (isspace(oldWord[start]) || oldWord[start] == '\t' || oldWord[start] == '\n')) {
//		start++;
//	}
//	while (end >= start && (isspace(oldWord[end]) || oldWord[end] == '\t' || oldWord[end] == '\n')) {
//		end--;
//	}
//	strncpy(newWord, oldWord + start, end - start + 1);
//	newWord[end - start + 1] = '\0';
//}
//
//void Seg(char words[], char wArray[][100])
//{
//	int count = 0;
//	char word[100];
//	int i = 0, j = 0;
//	while (words[i] != '\0') {
//		while (isspace(words[i])) {
//			i++;
//		}
//		j = 0;
//		while (!isspace(words[i]) && words[i] != '\0') {
//			word[j++] = words[i++];
//		}
//		word[j] = '\0';
//		strcpy(wArray[count++], word);
//	}
//}
//
//int main()
//{
//	char input[1000];
//	char words[1000];
//	char wArray[100][100];  
//	fgets(input, 1000, stdin); 
//	input[strcspn(input, "\n")] = 0; 
//	if (IsNumIn(input)|| IsSpcIn(input))
//	{
//		printf("error");
//		return 0;
//	}
//	Trim(input, words);
//	Seg(words, wArray);
//	return 0;
//}
//int main()
//{
//	char arr[8][20];
//	for (int i = 0; i < 8; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < 8 ; i++)
//	{
//		for (int j = 0; j < 8 - 1-i; j++)
//		{
//			if (strcmp(arr[j], arr[j + 1]) > 0)
//			{
//				char temp[50];
//				strcpy(temp, arr[j]);
//				strcpy(arr[j], arr[j + 1]);
//				strcpy(arr[j + 1], temp);
//				
//			}
//		}
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	char* arr1[10] = {
//	"Sunday",
//	"Monday",
//	"Tuesday",
//	"Wednesday",
//	"Thursday",
//	"Friday",
//	"Saturday",
//	};
//	printf("Please enter a string:\n");
//	char arr[10];
//	scanf("%s", arr);
//	for (int i = 0; i < 7; i++)
//	{
//		if (!strcmp(arr1[i], arr))
//		{
//			printf("%s is %d\n", arr, i);
//			return 0;
//		}
//	}
//	printf("Not found!\n");
//	return 0;
//}
//int main()
//{
//	char* arr1[10] = {
//		"sunday",
//		"monday",
//		"tuesday",
//		"wednesday",
//		"thursday",
//		"friday",
//		"saturday",
//	};
//	char arr[10];
//	printf("Enter a string:");
//	scanf("%s", arr);
//	for (int i = 0; i < 7; i++)
//	{
//		if (!strcmp(arr1[i], arr))
//		{
//			printf("%s is %d\n", arr, i);
//			return 0;
//		}
//	}
//	printf("Error\n");
//	return 0;
//}
//int main()
//{
//	char arr[10][50];
//	int n;
//	printf("请输入需要排序的字符串个数：");
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("请输入第%d个字符串：", i + 1);
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < n ; i++)
//	{
//		for (int j = 0; j < n - 1-i; j++)
//		{
//			if (strcmp(arr[j], arr[j + 1]) > 0)
//			{
//				char temp[50];
//				strcpy(temp, arr[j]);
//				strcpy(arr[j], arr[j + 1]);
//				strcpy(arr[j + 1], temp);
//				
//			}
//		}
//	}
//	printf("排序后的字符串顺序为：\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("第%d个字符串为：%s \n", i+1,arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[256] = { 0 };
//	char str[35] = { 0 };
//	printf("请输入任意字符串：");
//	fgets(str, 31, stdin);
//	str[strcspn(str, "\n")] = 0;
//	for (int i = 0; str[i] != '\0'; i++) 
//	{
//		arr[(unsigned char)str[i]]++;
//	}
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (arr[(unsigned char)str[i]] == 1)
//		{
//			printf("输入字符串中第一次出现的单个字符是：%c\n", str[i]);
//			return 0;
//		}
//	}
//	printf("这个字符串中没有只出现一次的字符\n");
//	return 0;
//}
//int main()
//{
//	char arr[35] = {0};
//	printf("请输入任意字符串：");
//	fgets(arr, 30, stdin);
//	int flag = 1;
//	int count = 0;
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		char* ch = 0;
//		if ((ch = strchr(arr, arr[i])) && ch == arr + i)
//		{
//			if ((ch = strchr(arr + i+1, arr[i]))==NULL)
//			{
//				printf("输入字符串中第一次出现的单个字符是：%c\n",arr[i]);
//				flag = 0;
//				break;
//			}
//			else
//			{
//				count++;
//			}
//		}
//		else
//		{
//			count++;
//		}
//	}
//	if (count == strlen(arr))
//		printf("这个字符串中没有只出现一次的字符\n");
//	return 0;
//}