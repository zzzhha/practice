#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
extern int flag;
//-----------------------�������-----------------------
//-------------------------view-----------------------
/*
    ������:�Ķ�
    ����:
      1.չʾ������Ա
      2.������ҳ��
    ����:void
    ����ֵ: void
*/
#define MAX_LINES 10



// ����һ���ṹ�����洢ÿ���ı�
typedef struct {
    char text[100];
    int yPosition;
} Line;

void kaifastaff()
{
    // ��ʼ�� EasyX ͼ�ο�
    setbkcolor(BLACK);
    setlinecolor(BLACK);

    // ������ı�
    char text[] =
        "�鳤                                      �հס���\n"
        "���鳤                                    С��\n"
        "Сѧ��                                    ����\n"
        "�ල��                                    ������\n"
        "��Ϣ��                                    4C\n"
        "������                                    ����\n"
        "������                                    ��κ\n"
        "�����¼                                  �˷���\n"
        "��Ʒ����                                  ��з\n"
        "��Ʒ����                                  �Ķ�";

    Line lines[MAX_LINES];
    int yPos = 0; // ��ʼ��ֱλ��
    int lineCount = 0;

    // ���ı��ָ����
    char* token = strtok(text, "\n");
    while (token != NULL && lineCount < MAX_LINES) {
        strcpy(lines[lineCount].text, token);
        lines[lineCount].yPosition = yPos;
        yPos += 50; // ÿ���ı��Ĵ�ֱ���
        lineCount++;
        token = strtok(NULL, "\n");
    }

    // �����ٶ�
    const int SCROLL_SPEED = 3;

    // ��ѭ��
    while (true) {
        // �����Ļ
        BeginBatchDraw();
        cleardevice();

        //��ȡ�����Ϣ
        peekmessage(&msg, EX_MOUSE);
        settextcolor(WHITE);
        // ���������¼�
        settextstyle(60, 0, "��������");
        outtextxy(950, 10, "�˳�");
        if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
        {
            flag = MY_MENU;
            break;
        }

        // ����ÿ���ı��Ĵ�ֱλ��
        for (int i = 0; i < lineCount; i++)
        {
            Line* line = &lines[i];
            line->yPosition += SCROLL_SPEED;
            if (line->yPosition > 960) {
                line->yPosition = -30; // ���õ���Ļ����
            }
            settextstyle(27, 0, "΢���ź�");
            int textWidth = textwidth(line->text);
            int xPosition = (getwidth()-1 - textWidth) / 2;
            outtextxy(xPosition, line->yPosition, line->text);
            
        }
        // ��ʱ������֡��
        
        Sleep(120);
        EndBatchDraw();
    }
}
//-------------------------view-----------------------