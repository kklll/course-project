#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <graphics.h>		// 引用图形库头文件，此头文件用来进行图形化界面的设计
#include <conio.h>			// 引用图形库头文件，此头文件进行图形化界面设计。

typedef struct node
{
	char info;				//储存字符
	int data;				//储存权值
	int encode[20];		//储存其二叉编码
	node *lchild, *rchild, *next;
}hufnode;
typedef struct stack
{
	hufnode data[100];
	int top;
}stack_1;
typedef struct queue
{
	int front;
	int rear;
	int data[100];
}queue;

void QuickSort(hufnode y[], int left, int right);//数组元素快速排序
hufnode *tolink(hufnode a[], int count);				//将排序后的数组元素用链表连起来
int readdata(hufnode x[]);							//从文件读取数据
hufnode *insert(hufnode * root, hufnode *s);					//取两最小节点将节点插入
hufnode *creathuff(hufnode * root);								// 生成哈夫曼树的创建函数
void ppt();
void treeencode(hufnode *t);

void init(stack *s);
void push(stack *s, hufnode a);
hufnode *pop(stack *s);