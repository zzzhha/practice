#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void print(int x)
{
    if (x > 9)
    {
        print(x / 10);//函数递归，当x大于9时，令x/10，
        //将x/10再次进行一次if判断直到x<9，
        // 再从后往前以此进行最后一步（printf的那步）
    }
    printf("%d  ", x % 10);

}
int main()
{
    unsigned int num = 0;
    scanf("%d", &num);
    print(num);
    return 0;
}