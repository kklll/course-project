/*
直接写函数比如:
int function()
{
	int s;
	scanf(%d,&s);
	return s;
}
1、因为最终要在main函数中调用各个函数，所以大家不要写重名函数自己调试的时候写main函数发给我的时侯只要函数，剩下的什么都不要
只把自己那块的函数代码写好就ok。
2、勤写注释，最好每行都有注释，写明白每行代码是用来干什么的，每个变量的意义是什么。
3、及时交流，上完一次机交流一下自己写到哪个部分了。
4、遇到不会的问题及时交流，希望大家做一次就做到最好。

---------------------------------------------------------------------------------
此函数用来建立动态储存结构（链表）
建立储存结构

测试：
将数据读入，正确输出就OK。


*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node			    //链表的结构定义
{
	char data;					//字符
	int fru;					//权值
	struct node *next;
}node;
void display(node *head)		//链表显示函数
{
	node *p;
	p = head;
	if (!p)
		printf("此链表为空，无法输出\n");
	else
	{
		printf("此链表各节点值为:\n");
		while (p)
		{
			printf("%c", p->data);
			printf("%5d", p->fru);
			printf("\n");
			p = p->next;
		}
		printf("\n");
	}
}
node *creat()
{
	node *h = NULL, *q = NULL, *p = NULL;
	int i=1;
	/*printf("输入链表节点个数:\n");*/
	FILE *fp = fopen("data.txt", "r");
	if (fp)
	{
		printf("文件读取成功\n");
	}
	else
	{
		printf("文件读取失败\n");
		exit(0);
	}
	h = (node *)malloc(sizeof(node));
	fscanf(fp, "%c %d\n", &h->data, &h->fru);
	p = (node *)malloc(sizeof(node));
	fscanf(fp, "%c %d\n", &p->data, &p->fru);
	h->next = p;
	q = p;
	while (1)
	{
		p = (node *)malloc(sizeof(node));
		if (i == 1)
		{
			q->next = p;
			i++;
		}
		if (fscanf(fp, "%c %d\n", &p->data, &p->fru) >= 0)
		{
			p->next = NULL;
			q->next = p;
			q = p;
		}
		else
		{
			break;
		}
	}
	return h;
}
int main()
{
	node *h;
	h = creat();
	display(h);
}
