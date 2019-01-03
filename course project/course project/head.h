#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <graphics.h>  // 引用图形库头文件，此头文件用来进行图形化界面的设计
#include <conio.h>	 // 引用图形库头文件，此头文件进行图形化界面设计。
#include<math.h>
#include<time.h>

typedef struct node
{
	char info;				//储存字符
	int data;				//储存权值
	char encode[20];		//储存其二叉编码
	node *lchild, *rchild, *next, *parent;
}hufnode;
typedef struct stack
{
	int data[100];
	int top;
}stack_1;

void QuickSort(hufnode y[], int left, int right);//数组元素快速排序
hufnode *tolink(hufnode a[], int count);				//将排序后的数组元素用链表连起来
int readdata(hufnode x[]);							//从文件读取数据
hufnode *insert(hufnode * root, hufnode *s);					//取两最小节点将节点插入
hufnode *creathuff(hufnode * root);								// 生成哈夫曼树的创建函数

void treeencode(hufnode *t, hufnode *h, int count);			//用树来编码
void decode(hufnode tree[]);						//解码

void init(stack *s);				//栈初始化	
void push(stack *s, int  a);		//压栈
int pop(stack *s);					//弹栈
void draw(int x, int y, char c);			//画结点
void drawdemo(hufnode *s, int x, int y, int temp, int suojian);  //画树
void draw_main(hufnode *s);				 //图形化界面主函数