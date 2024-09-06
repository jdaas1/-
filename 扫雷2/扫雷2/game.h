#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1;
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY 10
#define COUNT 81
void arr1_initial(char show[ROWS][COLS], int rows, int cols, char a);//棋盘初始化
void arr2_initial(char mine[ROWS][COLS], int rows, int cols, char a);
void arr1_printf(char show[ROWS][COLS], int row, int col);//数组打印
void arr2_printf(char mine[ROWS][COLS], int rows, int cols);
void arr_random(char mine[ROWS][COLS], int row, int col);//随机赋值
void arr_num(char mine[ROWS][COLS], int x, int y);//num
void arr_judge(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);//judge
void arr_display(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y);//display