#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	char arr[105];
	scanf("%s", arr);
	int sz = strlen(arr);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (i != sz - 1)
		{
			printf("%c", arr[i] + arr[i + 1]);
		}
		else
			printf("%c", arr[0] + arr[i]);
	}
	return 0;
}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	char arr1[10];
//	char arr2[10];
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s%s", arr1,arr2);
//		if (arr1[0] == arr2[0])
//		{
//			printf("Tie\n");
//		}
//		else if (arr1[0] == 'R')
//		{
//			if (arr2[0] == 'P')printf("Player2\n");
//			else printf("Player1\n");
//		}
//		else if (arr1[0] == 'P')
//		{
//			if (arr2[0] == 'S')printf("Player2\n");
//			else printf( "Player1\n");
//		}
//		else if (arr1[0] == 'S')
//		{
//			if (arr2[0] == 'R')printf("Player2\n");
//			else printf("Player1\n");
//		}
//	}
//	return 0;
//}
//int main()
//{
//	float n;
//	scanf("%f", &n);
//	char arr1[500] = { 0 };
//	char arr2[500] = { 0 };
//	int i = 0;
//	int count = 0;
//	scanf("%s", arr1);
//	scanf("%s", arr2);
//	int sz = (int)strlen(arr1);
//	for (i = 0; i < sz; i++)
//	{
//		if(arr1[i]==arr2[i])
//		{
//			count++;
//		}
//	}
//	float ret = 1.0f * count / sz;
//	if (ret > n)
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}
//
// �ҵ�һ��ֻ����һ�ε��ַ�
//char firstUniqueChar(char* s) {
//    // ����һ����СΪ26������������ÿ��Сд��ĸ���ֵĴ���  
//    int count[26] = { 0 };
//    int len = strlen(s);
//    char firstChar = 0; // ����û��ֻ����һ�ε��ַ�  
//
//    // �����ַ�����ͳ��ÿ���ַ����ֵĴ���  
//    for (int i = 0; i < len; i++) {
//        count[s[i] - 'a']++;
//    }
//
//    // �ٴα����ַ������ҵ���һ��ֻ����һ�ε��ַ�  
//    for (int i = 0; i < len; i++) {
//        if (count[s[i] - 'a'] == 1) {
//            firstChar = s[i];
//            break; // �ҵ���ֱ������ѭ��  
//        }
//    }
//
//    return firstChar;
//}
//
//int main() {
//    char s[1105] = { 0 };
//    scanf("%s", s);
//    char result = firstUniqueChar(s);
//
//    if (result == 0)
//    {
//        printf("no\n");
//    }
//    else
//    {
//        printf("%c\n", result);
//    }
//
//    return 0;
//}
//
// ֱ��ͼ
//void countOccurrences(int* arr, int size) {
//    // ��һ�����ҵ������е����ֵ  
//    int Fmax = 0;
//    for (int i = 0; i < size; i++) {
//        if (arr[i] > Fmax) {
//            Fmax = arr[i];
//        }
//    }
//
//    // �ڶ�������������ʼ����������  
//    int* count = (int*)calloc(Fmax + 1, sizeof(int));
//    if (count == NULL) {
//        perror("Memory allocation failed");
//        return;
//    }
//
//    // ��������ͳ��ÿ�����ĳ��ִ���  
//    for (int i = 0; i < size; i++) {
//        if (arr[i] <= Fmax) {
//            count[arr[i]]++;
//        }
//    }
//
//    // ���Ĳ�����˳�����ÿ�����ĳ��ִ���  
//    for (int i = 0; i <= Fmax; i++) {
//        printf("%d\n", count[i]);
//    }
//
//    // �ͷ��ڴ�  
//    free(count);
//}
//
//int main() {
//    int arr[100000] = { 0 };
//    int n;
//    scanf("%d", &n);
//    int i = 0;
//    for (; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    countOccurrences(arr, n);
//
//    return 0;
//}