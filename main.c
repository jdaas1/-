
#include "game.h"
void maun()
{
	printf("###################\n");
	printf("#### ɨ����Ϸ #####\n");
	printf("###1.play  0.quit##\n");
	printf("###################\n");
}
void game()
{

	//����Ĵ���
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	//�����ʼ��
	arr1_initial(show, ROWS, COLS, '*');
	arr2_initial(mine, ROWS, COLS, '0');
	//��ӡ����
	arr1_printf(show, ROW, COL);
	//arr2_printf(mine, ROWS, COLS);
	
	//�����ֵ
	arr_random(mine, ROW, COL);
	/*arr1_printf(show, ROW, COL);
	arr2_printf(mine, ROWS, COLS);*/

	

	//���׵��ж�

	arr_judge(show,mine, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do//ѡ��ѭ��
	{
		maun();//�˵�

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//����game����������Ϸ
			break;
		case 0:

			printf("��Ϸ����\n");
			Sleep(2000);//��ͣ����
			break;
		default:
			printf("���������������ȷ���֣�\n");
		};
	} while (input);

	return 0;
}
