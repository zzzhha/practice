#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
extern int flag;
//-----------------------数据设计-----------------------
//-------------------------view-----------------------
/*
    负责人:夏尔
    功能:
      1.展示开发人员
      2.返回主页面
    参数:void
    返回值: void
*/
#define MAX_LINES 10



// 定义一个结构体来存储每行文本
typedef struct {
    char text[100];
    int yPosition;
} Line;

void kaifastaff()
{
    // 初始化 EasyX 图形库
    setbkcolor(BLACK);
    setlinecolor(BLACK);

    // 输入的文本
    char text[] =
        "组长                                      空白『』\n"
        "副组长                                    小七\n"
        "小学长                                    呆鱼\n"
        "监督官                                    看见了\n"
        "信息官                                    4C\n"
        "技术官                                    阿星\n"
        "技术官                                    老魏\n"
        "会议记录                                  核废料\n"
        "产品经理                                  河蟹\n"
        "产品经理                                  夏尔";

    Line lines[MAX_LINES];
    int yPos = 0; // 初始垂直位置
    int lineCount = 0;

    // 将文本分割成行
    char* token = strtok(text, "\n");
    while (token != NULL && lineCount < MAX_LINES) {
        strcpy(lines[lineCount].text, token);
        lines[lineCount].yPosition = yPos;
        yPos += 50; // 每行文本的垂直间隔
        lineCount++;
        token = strtok(NULL, "\n");
    }

    // 滚动速度
    const int SCROLL_SPEED = 3;

    // 主循环
    while (true) {
        // 清除屏幕
        BeginBatchDraw();
        cleardevice();

        //获取鼠标消息
        peekmessage(&msg, EX_MOUSE);
        settextcolor(WHITE);
        // 检测鼠标点击事件
        settextstyle(60, 0, "华文琥珀");
        outtextxy(950, 10, "退出");
        if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
        {
            flag = MY_MENU;
            break;
        }

        // 更新每行文本的垂直位置
        for (int i = 0; i < lineCount; i++)
        {
            Line* line = &lines[i];
            line->yPosition += SCROLL_SPEED;
            if (line->yPosition > 960) {
                line->yPosition = -30; // 重置到屏幕顶部
            }
            settextstyle(27, 0, "微软雅黑");
            int textWidth = textwidth(line->text);
            int xPosition = (getwidth()-1 - textWidth) / 2;
            outtextxy(xPosition, line->yPosition, line->text);
            
        }
        // 延时，控制帧率
        
        Sleep(120);
        EndBatchDraw();
    }
}
//-------------------------view-----------------------