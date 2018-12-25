#pragma once

#include<stdio.h>
#include<stdlib.h>
#define n 100				 //叶子最大数目
#define m (2*n-1)			//最大结点总数(2*n-1)
#define maxval 10000.0
#define maxsize 100			//哈夫曼编码的最大位数
//static n;
typedef struct
{
	char ch;
	int weight;
	int lchild, rchild, parent;
}hufmtree;
typedef struct codetype
{
	char bits[n];			 //位串
	int start;				 //编码在位串中的起始位置
	char ch;				 //字符
}codetype;		

void huffman(hufmtree tree[],int new_m,int new_n);	//建立哈夫曼树
void huffmancode(codetype code[], hufmtree tree[],int new_m, int new_n);	//根据哈夫曼树求出哈夫曼编码
void decode(hufmtree tree[], int new_m);	//依次读入，根据哈夫曼树译码
int count();	//记录文件节点个数