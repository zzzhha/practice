#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>


void menu()
{
	printf("*******************************************\n");
	printf("****        1.play       0.exit        ****\n");
	printf("*******************************************\n");
}
void game()
{
	int ret = 0,guess=0;
	//��ʱ���������ʱ��
	ret = rand() % 100; //ȡ������ʹ��������1 - 99֮��
	while(1)
	{
		printf("�������:>");
		scanf("%d", &guess);
			if (guess > ret)
				printf("���� ɵ��\n");
			if (guess < ret)
				printf("С�� ɵ��\n");
			if (guess == ret)
			{

				printf("������������ô�� \n");
				break;
			}
	}


}
int main()
{
	srand((unsigned)time(NULL));//ʱ���
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
//int main()
//{
//
//	int a, b, sum;
//	sum = 5;
//
//	srand((unsigned)time(NULL));//ʱ���
//	a = rand() % 100;//ȡ������ʹ��������1-99֮��
//
//	while (1)
//	{
//
//		sum--;
//
//		scanf("%d", &b);
//		if (b > a)
//			printf("���� ɵ�� ������ֻ��%d�λ����� ��ϧ��С��\n", sum);
//		if (b < a)
//			printf("С�� ɵ�� ������ֻ��%d�λ����� ��ϧ��С��\n", sum);
//		if (b == a)
//		{
//
//			printf("������������ô�� \n");
//			break;
//		}
//		if (sum == 0)
//		{
//
//			printf("����ɵ�� �ټ��� ��ȥ������");
//			//system("shutdown -s -t 10");
//
//			break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "welcome to china";
//	//��ӡ����ÿ�����������ֽ�Ҳ����Ҫ����##
//	char arr2[] = "################";
//	//���ϣ������left++���left+=2��rightҲ��
//	int right = sizeof(arr1) / sizeof(arr1)[0] - 2;//=strlen(arr)-1
//	int left = 0;
//		while (left <= right)
//		{
//			arr2[left] = arr1[left];
//			arr2[right] = arr1[right];
//			printf("%s\n",arr2);
//			Sleep(1000);//����Ǽ��٣�1000Ϊ����Ҳ����1s
//			system("cls");//cls�����Ļ
//			left++;
//			right--;
//		}


//}

//int main()
//{
//	int a = 1, b = 1;
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			printf("%d*%d=%-2d  ", a, b, a * b);
//		}
//		printf("\n");
//int main()
//{
//	int a=1, b=1;
//    for (a = 1; a <= 9; a++)
//	{ 
//		for (b = 1; b <a; b++)
//		{
//			printf("%d*%d=%-2d  ",a,b, a * b);//��ӡ����
//		}
//		printf("%d*%d=%d\n",a,b, a * b);//��ӡ����
//	}//�ܴ�ӡ�������������ǵĳ˷��ھ���
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int max = arr[0], i;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 1; i < sz; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("%d", max);
//	return 0;
//}
//int main()
//{
//	int arr[10] = {0};
//	
//	int max,i;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//		max = arr[0];
//		if (arr[i] > max) 
//		{
//			max = arr[i];
//		}	
//	}
//	printf("max=%d", max);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;			
//	}
//	printf("%lf", sum);
//	return 0;
//}
//int main()
//{
//	int a, b;
//	double c=0.0,d=0.0;
//	for (a = 1; a < 100; a += 2)
//	{
//		c += 1.0 / a;
//	}
//	for (b = 2; b <= 100; b += 2)
//	{
//		d += 1.0 / b;
//	} 
//	printf("%lf\n",c-d);
//	return 0;
//}
//int main()
//{
//	int a,i=0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (a % 10 == 9)
//		{
//			i++;  
//		}
//		if(a/10==9)
//		{
//			i++;
//		}
//	}
//	printf("������%d��9\n", i);
//
//	return 0;
//}
//int main()
//{
//	int a, b, d;
//	static c = 1;
//	scanf("%d%d",&a,&b);
//	
//	for (; c <= b || c <= a; c++)
//	{
//			if (b % c == 0 && a % c == 0)
//			{
//				d = c;
//			}
//	}
//	printf("%d",d);
//	return 0;
//}
//int main()
//{
//	int i;
//	for (i = 1; i < =100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b && a > c && b > c)
//		printf("%d %d %d", a, b, c);
//	else if (a > b && a > c && c > b)
//		printf("%d %d %d", a, c, b);
//	else if (b > a && b > c && a > c)
//		printf("%d %d %d", b, a, c);
//	else if (b > a && b > c && c > a)
//		printf("%d %d %d", b, c, a);
//	else if (c > b && c > a && a > b)
//		printf("%d %d %d", c, a, b);
//	else if (c > b && c > a && b > a)
//		printf("%d %d %d", c, b, a);
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int n;
//		n = a;
//		a = b;
//		b = n;
//	}
//	if (a < c)
//	{
//		int m;
//		m = a;
//		a = c;
//		c = m;
//	}
//	if (b < c)
//	{
//		int y;
//		y = b;
//		b = c;
//		c = y;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	char id[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������");
//		scanf("%s", password);
//		if (strcmp(password, "1499623600") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//	}
//		if (i == 3)
//			printf("��½�ɹ�");
//	
//
//	return 0;
//}
//int main()
//{
//	//int password = "1499623600";
//	//int id="1499623600";
//	char x[20] = { 0 }, y[30] = {0};
//	int i,ch,nh;
//	int n = 3;
//	for (i = 1; i <= n; i++)
//	{
//		printf("�������˺ź�����\n");
//		printf("�˺�");
//		scanf("%s", x);
//		/*while (ch=getchar()!='\n')
//		{
//			;
//		}*/
//		printf("����");
//		scanf("%s",y);
//		/*while (nh = getchar() != '\n')
//		{
//			;
//		}*/
//		if (strcmp(x,"1499623600",y,"123456")==0)
//		{
//			printf("��½�ɹ�");
//			break;
//		}
//		else if(i==1||i==2||i==3)
//		{
//			printf("�����˺Ż��������������");
//		}
//	}
//	if (i >3)
//		printf("��������������Ѵ�������������������");
//			return 0;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k;
//	scanf("%d",&k);
//	int left = 0;
//	int sz = sizeof(arr) / sizeof arr[0];
//	int right = sz - 1;
//	int mid;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid]<k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±���%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("û�ҵ�");
//	return 0;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k;
//	scanf("%d", &k);
//	int i;
//	int se = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < se; i++)
//		if ( k== arr[i])
//		{
//			printf("�ҵ���i,�±���%d\n", i);
//			break;
//		}
//	if(i==se)
//	{
//		printf("û����\n");
//	
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int n;
//	int x = 1;
//	int y = 0;
//	scanf("%d", &n);
//	for (; i <= n; i++)
//{
//		x *= i;
//	y += x;
//}
//		printf("%d", y);
//	return 0;
//}
//int main() 
//{ 
//	int day;
//	scanf("%d",&day);
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n"); break;
//	case 2:
//		printf("���ڶ�\n"); break;
//	case 3:
//		printf("������\n"); break;
//	case 4:
//		printf("������\n"); break;
//	case 5:
//		printf("������\n"); break;
//	case 6:
//		printf("������\n"); break;
//	case 7:
//		printf("������\n"); break;
// default:
// printf("���޴���\n");
//	}
//	return 0;
//}
//int main()
//{
//	int day;
//	scanf("%d",&day);
//	if (day == 1)
//		printf("����һ\n");
//	else if (day == 2)
//		printf("���ڶ�\n");
//	else if (day == 3)
//		printf("������\n");
//	else if (day == 4)
//		printf("������\n");
//	else if (day == 5)
//		printf("������\n");
//	else if (day == 6)
//		printf("������\n");
//	else if (day == 7)
//		printf("������\n");
//	return  0;
//}
//int a = 1;
//int main()
//{
//	while (a <= 100)
//	{
//		if (1 == a % 2)
//			printf("%d\n",a);
//		a++;
//	}
//}
//int main()
//{
//	int a=1;
//	for (a=1;a <= 100;a++)
//	{
//		if (1 == a % 2)
//			printf("%d\n", a);
//	}
//		return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	if (1 == a % 2)
//		printf("%d������",a);
//	return 0;
//}
//int main()
//{
//    float a,b;
//    scanf("%f %f",&a,&b);
//    printf("%.2f", 1 / (1 / a + 1 / b));
//    return 0;
//}
//int main()
//{
//	float f, c;
//	scanf("%f",&f);
//	c = (5*(f-32))/9.0;
//	printf("%.5f",c);
//    return 0;
//}
//int main()
//{
//	float x, a, y, b;
//	scanf("%f%f%f%f",&x,&a,&y,&b);
//	printf("%.2f", 1.0*(b * y - a * x) / (b - a));
//	return 0;
//}
//int main()
//{
//	char a;
//		scanf("%c",&a);
//		printf("  %c\n",a);
//		printf(" %c%c%c\n", a,a,a);
//		printf("%c%c%c%c%c\n",a,a,a,a, a);
//		return 0;
//}
//int main()
//{
//	int a;
//	int b;
//	int c;
//	scanf("%d%d%d", &a, &b, &c);
//	printf("%8d%8d%8d", a,b,c);
//	return 0;
//}

//int main()
//{
//	printf("Hello,World!\n");
//
//	return 0;
//}
//int main()
//{
//    int x;
//    scanf("%d", &x);
//    printf("I am %d years old.", x);
//    return 0;
//}
//int main()
//{
//	int a;
//    int b;
//	scanf_s("%d %d", &a, &b);
//	if (a <= b)
//		printf("yes\n");
//	else
//		printf("no\n");
//	return 0;
//}
//Add �� x, y��
//{ int x;
//  int y;
//  int z;
//  z = x + y;
//}
//int main()
//{
//	long long x, y;
//	scanf("%lld%lld", &x ,&y);
//		printf("%lld", x+y);
//return 0;
//}
