/*
---------------------------------------------------------------------------------
此文件为程序进行哈夫曼编码主文件
---------------------------------------------------------------------------------
*/


#include"head.h"
hufnode *insert(hufnode * root, hufnode *s)					//取两最小节点创建树
{
	hufnode *p1, *p2;
	if (root == NULL)
		root = s;
	else
	{
		p1 = NULL;
		p2 = root;
		while (p2&&p2->data < s->data)
		{
			p1 = p2;
			p2 = p2->next;
		}
		s->next = p2;
		if (p1 == NULL)
			root = s;
		else
			p1->next = s;
	}
	return root;
}
hufnode *creathuff(hufnode * root)								// 生成哈夫曼树的创建函数
{
	hufnode *s, *rl, *rr,*root1;
	root1 = root;
	while (root&&root->next)
	{
		rl = root;
		rr = root->next;
		root = rr->next;
		s = (hufnode *)malloc(sizeof(hufnode));
		s->parent = NULL;
		rl->parent = s;
		rr->parent = s;
		s->info = NULL;
		s->next = NULL;
		s->data = rl->data + rr->data;
		s->lchild = rl;
		s->rchild = rr;
		//rl->next = rr->next = NULL;
		root = insert(root, s);					
	}
	printf("创建完成！\n");
	return root;
}
int readdata(hufnode x[])							//从文件读取数据
{
	char ch;
	int fru;
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！");
		return 0;
	}
	int i = 0;
	while (fscanf(fp, "%c %d\n", &ch, &fru) >= 0)
	{
		x[i].info = ch;
		x[i].data = fru;
		i++;
	}
	/*for (int j = 0; j < i; j++)
	{
		printf("%c %d\n", x[j].info, x[j].data);
	}
	printf("读取成功！\n");*/
	return i;
}
void QuickSort(hufnode y[], int left, int right)				//将结构体数组快速排序
{
	hufnode x;
	int i, j, flag = 1;
	if (left < right)
	{
		i = left;
		j = right;
		x = y[i];
		while (i < j)
		{
			while (i < j&&x.data < y[j].data)
				j--;
			if (i < j)
				y[i++] = y[j];
			while (i < j&&x.data > y[i].data)
				i++;
			if (i < j)
				y[j--] = y[i];
		}
		y[i] = x;
		QuickSort(y, left, i - 1);		//递归实现
		QuickSort(y, i + 1, right);		//递归实现
	}
}
hufnode *tolink(hufnode a[], int count)				//将排序后的数组元素用链表连起来形成有序链表
{
	node *h = NULL, *q = NULL, *p = NULL;
	int  i;
	for (i = 0; i < count; i++)
	{
		p = (node *)malloc(sizeof(node));
		p->info = a[i].info;
		p->data = a[i].data;
		p->lchild = NULL;
		p->rchild = NULL;
		p->next = NULL;
		if (i == 0)
		{
			h = p; q = p;
		}
		else
		{
			q->next = p; q = p;
		}
	}
	return h;
}

void treeencode(hufnode *t,hufnode *h,int count)
{
	int i = 0,j;
	hufnode *p,*q,*tmp;
	stack s;
	init(&s);
	p = h;
	q = h;
	while(p!=NULL)
	{
		q = p;
		while (q!=t)
		{
			tmp = q;
			q = q->parent;
			if (q->lchild == tmp)
			{
				push(&s, 0);
			}
			if (q->rchild == tmp)
			{
				push(&s, 1);
			}
		}
		j = 0;
		for (j = 0; s.top > 0; j++)
		{
			p->encode[j] = pop(&s);
		}
		p->encode[j] = 2;
		if (p->info != NULL)
		{
			printf("%c ", p->info);
			for (j = 0; p->encode[j] != 2; j++)
			{
				printf("%d", p->encode[j]);
			}
			printf("\n");
		}
		p = p->next;
	}
}
void init(stack *s)					//栈的初始化具体化实现
{
	s->top = 0;
}
void push(stack *s, int a)				//压栈具体化实现
{
	s->data[s->top++] = a;
}
int pop(stack *s)					//弹栈具体化实现
{
	s->top--;
	return(s->data[s->top]);
}