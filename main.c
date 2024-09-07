
#include "game.h"
void maun()
{
	printf("###################\n");
	printf("#### 扫雷游戏 #####\n");
	printf("###1.play  0.quit##\n");
	printf("###################\n");
}
void game()
{

	//数组的创建
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	//数组初始化
	arr1_initial(show, ROWS, COLS, '*');
	arr2_initial(mine, ROWS, COLS, '0');
	//打印数组
	arr1_printf(show, ROW, COL);
	//arr2_printf(mine, ROWS, COLS);
	
	//随机赋值
	arr_random(mine, ROW, COL);
	/*arr1_printf(show, ROW, COL);
	arr2_printf(mine, ROWS, COLS);*/

	

	//踩雷的判断

	arr_judge(show,mine, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do//选择循环
	{
		maun();//菜单

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//调用game函数进入游戏
			break;
		case 0:

			printf("游戏结束\n");
			Sleep(2000);//暂停两秒
			break;
		default:
			printf("输入错误，请输入正确数字！\n");
		};
	} while (input);

	return 0;
}
