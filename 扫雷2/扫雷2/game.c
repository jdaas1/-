#include "game.h"
void arr1_initial(char show[ROWS][COLS], int rows, int cols, char a)//棋盘show初始化
{
	
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		
		for (j = 0; j < cols; j++)
		{
			show[i][j] = a;
		}
	}

}
void arr2_initial(char mine[ROWS][COLS], int rows, int cols, char a)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = a;
		}
	}
}
void arr1_printf(char show[ROWS][COLS], int row, int col)//数组打印
{
	int i, j;
	
	
	for (i = 0; i <= col ; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	

	for (i = 1; i <= row; i++)
	{
		
		
		printf("%d ", i);
		

		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}
void arr2_printf(char mine[ROWS][COLS], int rows, int cols)
{
	int i, j;


	for (i = 0; i < rows; i++)
	{


		for (j = 0; j < cols; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
}
void arr_num(char mine[ROWS][COLS], int x, int y)//num
{
	if (mine[x - 1][y] != '#')//top
	{
		mine[x - 1][y] += 1;
	}
	if (mine[x - 1][y-1] != '#')//topleft
	{
		mine[x - 1][y-1] += 1;
	}
	if (mine[x][y - 1] != '#')//left
	{
		mine[x][y - 1] += 1;
	}
	if (mine[x+1][y - 1] != '#')//bottomleft
	{
		mine[x+1][y - 1] += 1;
	}
	if (mine[x + 1][y] != '#')//bottom
	{
		mine[x + 1][y] += 1;
	}
	if (mine[x + 1][y+1] != '#')//bottomright
	{
		mine[x + 1][y+1] += 1;
	}
	if (mine[x][y + 1] != '#')//right
	{
		mine[x][y + 1] += 1;
	}
	if (mine[x-1][y + 1] != '#')//topright
	{
		mine[x-1][y + 1] += 1;
	}
}
void arr_random(char mine[ROWS][COLS], int row, int col)//随机赋值
{
	int count = EASY;
	while (count)
	{
		int x = rand() % row + 1;//1-9;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '#';
			count--;

			arr_num(mine, x, y);//num
		}

	}
}
void arr_display(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y)//display
{
	if (x <= ROW && x >= 1 && y <= COL && y >= 1)
	{
		show[x][y] = ' ';
		if (show[x - 1][y] == '*')//top
		{
			if (mine[x - 1][y] == '0')
			{
				arr_display(show, mine, x - 1, y);
			}
			else
			{
				show[x - 1][y] = mine[x - 1][y];
			}
		}
		if (show[x - 1][y - 1] == '*')//topleft
		{
			if (mine[x - 1][y - 1] == '0')
			{
				arr_display(show, mine, x - 1, y - 1);
			}
			else
			{
				show[x - 1][y - 1] = mine[x - 1][y - 1];
			}
		}
		if (show[x][y - 1] == '*')//left
		{
			if (mine[x][y - 1] == '0')
			{
				arr_display(show, mine, x, y - 1);
			}
			else
			{
				show[x][y - 1] = mine[x][y - 1];
			}
		}
		if (show[x + 1][y - 1] == '*')//bottomleft
		{
			if (mine[x + 1][y - 1] == '0')
			{
				arr_display(show, mine, x + 1, y - 1);
			}
			else
			{
				show[x + 1][y - 1] = mine[x + 1][y - 1];
			}
		}
		if (show[x + 1][y] == '*')//bottom
		{
			if (mine[x + 1][y] == '0')
			{
				arr_display(show, mine, x + 1, y);
			}
			else
			{
				show[x + 1][y] = mine[x + 1][y];
			}
		}
		if (show[x + 1][y + 1] == '*')//bottomright
		{
			if (mine[x + 1][y + 1] == '0')
			{
				arr_display(show, mine, x + 1, y + 1);
			}
			else
			{
				show[x + 1][y + 1] = mine[x + 1][y + 1];
			}
		}
		if (show[x][y + 1] == '*')//right
		{
			if (mine[x][y + 1] == '0')
			{
				arr_display(show, mine, x, y + 1);
			}
			else
			{
				show[x][y + 1] = mine[x][y + 1];
			}
		}
		if (show[x - 1][y + 1] == '*')//topright
		{
			if (mine[x - 1][y + 1] == '0')
			{
				arr_display(show, mine, x - 1, y + 1);
			}
			else
			{
				show[x - 1][y + 1] = mine[x - 1][y + 1];
			}
		}
	}
	
}
void arr_judge(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)//judge
{
	int count = 0;
	while (1)
	{
		printf("请输入：");
		int x, y;
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '#')
		{
			printf("踩雷了！\n");
			show[x][y] = mine[x][y];
			arr1_printf(show, ROW, COL);
			Sleep(2000);
			break;
		}
		
		else if(mine[x][y] == '0')
		{
			arr_display(show,mine,x,y);//范围展开
			arr1_printf(show, ROW, COL);
			/*arr2_printf(mine, ROWS, COLS);*/
		}
		else if(mine[x][y] != '0')
		{

			show[x][y] = mine[x][y];
			arr1_printf(show, ROW, COL);
		}
		int i, j;
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] == '*')
				{
					count++;
				}
			}
		}
		if (count == EASY)
		{
			break;
		}

		
	}

}