#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/
void menuView();

/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init() {
    //在此处完成代码
    flag = 1;
    int i;//控制map行
    for (i = 0; i < 19; i++)
    {
        int j;//控制列
        for (j = 0; j < 19; j++)
        {
            map[i][j] = 0;//使map数组全为0
        }
    }
}

int isWin(int x, int y) {
    //在此处完成代码
    int i, j;
    int count = 1;//记录当前落子与旁边的字相接的有多少个
    int gg = 0;
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 19; j++)
        {
            if (map[i][j] == 0)
                continue;
            if (j < 19 - 4)//横着是否胜利
            {
                if (map[i][j] == map[i][j + 1] &&
                    map[i][j] == map[i][j + 2] &&
                    map[i][j] == map[i][j + 3] &&
                    map[i][j] == map[i][j + 4] &&
                    map[i][j] != 0)
                {
                    gg = 1;
                }
            }
            if (i < 19 - 4)//竖着是否胜利
            {
                if (map[i][j] == map[i + 1][j] &&
                    map[i][j] == map[i + 2][j] &&
                    map[i][j] == map[i + 3][j] &&
                    map[i][j] == map[i + 4][j] &&
                    map[i][j] != 0)
                {
                    gg = 1;
                }
            }
            if (i < 19 - 4 && j < 19 - 4)//左上至右下是否胜利
            {
                if (map[i][j] == map[i + 1][j + 1] &&
                    map[i][j] == map[i + 2][j + 2] &&
                    map[i][j] == map[i + 3][j + 3] &&
                    map[i][j] == map[i + 4][j + 4] &&
                    map[i][j] != 0)
                {
                    gg = 1;
                }
            }
            if ((i < 19 - 4) && (j >= 4))//右上至左下是否胜利
                if (map[i][j] == map[i + 1][j - 1] &&
                    map[i][j] == map[i + 2][j - 2] &&
                    map[i][j] == map[i + 3][j - 3] &&
                    map[i][j] == map[i + 4][j - 4] &&
                    map[i][j] != 0)
                {
                    gg = 1;
                }

        }
    }
    if (gg)//判断赢没赢
    {
        if (flag % 2 == 1)
        {
            return 1;//黑子赢了
        }
        else
        {
            return 2;//白子赢了
        }
    }
    else
    {
        return 0;//没有获胜
    }
}

int playerMove(int x, int y) {
    //在此处完成代码
    if (x > 19 || y > 19)
    {
        printf("落子错误请再来一次(行要小于等于%d,列要小于等于%d)\n", 19, 19);
        return 0;
    }
    else if (map[x - 1][y - 1] != 0)
    {
        printf("落子错误,请重试");
        return 0;
    }
    else
    {
        if (flag % 2)//黑子移动
        {

            map[x - 1][y - 1] = 1;
            return 1;
        }
        else//白子移动
        {
            map[x - 1][y - 1] = 2;
            return 1;
        }
    }
}

void menuView() {
    //在此处完成代码
    int i;
    int ch;
    do
    {
        printf("***********************************************\n");
        printf("*************** 五    子    棋 ****************\n");
        printf("***********************************************\n");
        printf("*************** 1.开 始 游 戏  ****************\n");
        printf("***********************************************\n");
        printf("*************** 2.进 入 设 置（敬请期待）******\n");
        printf("***********************************************\n");
        printf("*************** 0.退 出 游 戏  ****************\n");
        printf("***********************************************\n");

        printf("\n");
        printf("请选择(1/0):>");
        scanf("%d", &i);
        switch (i)
        {
        case  1:
            printf("game start!\n");
            gameView();
            break;
        case 2:
            break;
        case  0:
            printf("欢迎下次游玩本游戏:)\n");
            exit(0);
        default:
            printf("你输入的格式不正确，请重新输入\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } while (i);
}

void gameView_ShowMap() {
    //在此处完成代码
    int i = 0;
    for (i = 0; i < 19; i++)
    {
        int j = 0;
        for (j = 0; j < 19; j++)
        {
            printf(" %d ", map[i][j]);//打印当前数组内容
            if (j != 19 - 1)
            {
                printf("|");//打印棋盘中的竖杠，每两个数字中间一个竖杠，最外层两边没有
            }
        }
        printf("\n");//换行打印一行横杠
        for (j = 0; j < 19; j++)
        {
            if (i != 19 - 1)//打印棋盘中的横杠，每两个数字中间一个横杠，最上和最下边没有
            {
                printf("___ ");
            }
        }
        printf("\n");//换行继续打印数组内容和竖杠
    }
}

void winView() {
    //在此处完成代码
    if (flag % 2)
    {
        printf("恭喜！黑子玩家胜利！\n");
    }
    else
    {
        printf("恭喜！白子玩家胜利！\n");
    }
}

void gameView() {
    //在此处完成代码
    init();//初始化数组
    gameView_ShowMap();
    while (1)
    {
        int x, y;
        printf("第%d回合\n", flag);
        if (flag % 2)
        {
            printf("请黑子落棋:>");
        }
        else
        {
            printf("请白子落棋:>");
        }
        scanf("%d%d", &x, &y);
        if (playerMove(x, y))
        {
            gameView_ShowMap();
            if (isWin(x, y))
            {
                winView();
                break;
            }
            if (flag == 19 * 19)
            {
                printf("平局！\n");
                break;
            }
            flag++;
        }
    }
}
//测试题第二题：
//1）游戏逻辑判断 service
//	 用户输入 view
//	 用户输入数据非法判断/类型判断 service
//   界面展示 view
//	 游戏数据修改 service
//2）1 true
//	 2 false
//	 3 false
//	 4 true
//	 5 false
//测试题第三题：
//-------------数据设计---------------
//每张图的大小 int map[10][10];
//关卡 level
//	 0 表示墙壁
//	 1 表示可行动区域
//	 3 表示箱子目的地
//	 9 表示人物和箱子目的地重叠
// 	 C 表示人物
// 	 B 表示箱子
//	 D 箱子和目的地重合
//-------------数据设计---------------
//-------------函数声明---------------
//void menuVuew();
//void levelView();
//void gameView();
//void winView();
//void setView();
//void rankView();