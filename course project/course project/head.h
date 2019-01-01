#pragma once
/*
此文件中包含了该程序运行所有库文件以及所有函数。
*/
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <graphics.h>		// 引用图形库头文件，此头文件用来进行图形化界面的设计
#include <conio.h>			// 引用图形库头文件，此头文件进行图形化界面设计。

typedef struct node
{
	char info;				//储存字符
	int data;				//储存权值
	char encode[20];		//储存其二叉编码
	node *lchild, *rchild, *next,* parent;			//树的左子树右子树，链表的next定义，
	//这样定义的好处是只需要定义一次结构体变量，可以实现树结构与链表结构的通用，减少代码量。
}hufnode;
typedef struct stack					//栈结构定义，此结构用来储存树的最后生成的哈夫曼编码。
{
	int data[100];
	int top;
}stack_1;

void QuickSort(hufnode y[], int left, int right);		//数组元素快速排序
hufnode *tolink(hufnode a[], int count);				//将排序后的数组元素用链表连起来
int readdata(hufnode x[]);								//从文件读取数据
hufnode *insert(hufnode * root, hufnode *s);			//取两最小节点将节点插入
hufnode *creathuff(hufnode * root);						// 生成哈夫曼树的创建函数

void treeencode(hufnode *t,hufnode *h,int count);		//用哈夫曼树来进行编码
void decode(hufnode tree[]);							//利用哈夫曼树来进行解码

void init(stack *s);						//栈初始化	
void push(stack *s, int  a);				//压栈
int pop(stack *s);							//弹栈
void draw(int x, int y, char c);			//画结点
void drawdemo(hufnode *s, int x, int y);	//画树的主函数
void draw_main(hufnode *s);					//图形化界面主函数