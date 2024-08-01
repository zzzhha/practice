#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

 struct CARD
{
	char suit[10];//��ɫ
	char face[10];//��ֵ
};

//���ֻ�ɫ
char suit[4][15] = {"diamonds","clubs","hearts","spades",};
char face[13][15] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//const char *suit[4] = {"diamonds","clubs","hearts","spades",};
//������ʮ������

void createCards(CARD *card)//��ʦ��
{
	int i = 0;
	for (i = 0; i < 52; i++)
	{
		strcpy(card[i].suit, suit[i / 13]);
		strcpy(card[i].face, face[i % 13]);
	}
	strcpy(card[i].suit, "red");
	strcpy(card[i++].face, "joker");
	strcpy(card[i].suit, "black");
	strcpy(card[i].face, "joker");
}
void createCards_my(CARD* card)//�ҵİ�
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		for(int j=0;j<13;j++)
		{
			strcpy(card[i*13+j].suit, suit[i]);
			strcpy(card[i * 13 + j].face, face[j]);
		}
	}
	strcpy(card[52].suit, "red");
	strcpy(card[52].suit, "joker");
	strcpy(card[53].suit, "black");
	strcpy(card[53].suit, "joker");
}
//ϴ��
void shuffleCards(CARD* card)
{
	srand((unsigned)time(0));
	for (int i = 0; i < 54; i++)//ѭ��54�Σ�ÿ��ѭ�������Ƶ�˳��
	{
		int ret = rand() % 54;
		if (i != ret)
		{
			swap(card[i], card[ret]);
		}
	}
}

void shuffleCards_my(CARD* card)
{
	srand((unsigned)time(0));
	for (int i = 0; i < 54; i++)
	{
		int ret = rand() % 54;
		CARD temp = card[ret];
		card[ret] = card[i];
		card[i] = temp;
		
	}

}

//����
void dealCards(CARD* card)
{
	CARD player[3][17],finalCards[3];
	int p1 = 0,p2 = 0,p3 = 0;
	for (int i = 0; i < 51; i++)
	{
		if (i % 3 == 0)
			player[0][p1++] = card[i];
		else if (i % 3 == 1)
			player[1][p2++] = card[i];
		else
			player[2][p3++] = card[i];
	}
	for (int i = 0; i < 3; i++)
	{
		finalCards[i] = card[i + 51];
	}
}
void dealCards_2(CARD* card)
{
	cout << "���1\t\t" << "���2\t\t" << "���3\t\t" << endl;
	for (int i = 0; i < 51; i++)
	{
		if (i % 3 == 0&&i!=0)
			cout << endl;
		cout << card[i].suit << "  " << card[i].face << "\t";
	}
	cout << endl << "����>>>>>" << endl;
	for (int i = 51; i < 54; i++)
	{
		cout << card[i].suit << "  " << card[i].face<<"\t";
	}
}
int main()
{
	CARD card[54];
	createCards(card);
	shuffleCards(card);
	dealCards(card);
	dealCards_2(card);
	/*for (int i = 0; i < 54; i++)
	{
		cout << card[i].suit << "  " << card[i].face << endl;
	}*/
	return 0;
}
