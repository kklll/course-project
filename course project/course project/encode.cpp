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
*/

#include"head.h"
hufnode *insert(hufnode * root, hufnode *s)					//取两最小节点将节点插入
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
	hufnode *s, *rl, *rr;
	while (root&&root->next)
	{
		rl = root;
		rr = root->next;
		root = rr->next;
		s = (hufnode *)malloc(sizeof(hufnode));
		s->info = NULL;
		s->next = NULL;
		s->data = rl->data + rr->data;
		s->lchild = rl;
		s->rchild = rr;
		rl->next = rr->next = NULL;
		root = insert(root, s);						//通过多次插入实现
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
		QuickSort(y, left, i - 1);		//递归实现方法 
		QuickSort(y, i + 1, right);
	}
}
hufnode *tolink(hufnode a[], int count)				//将排序后的数组元素用链表连起来
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

void treeencode(hufnode *t)
{
	stack s;
	queue q;
	q.front = 0;
	q.rear = 0;
	int flag=0;
	int i = 0;
	init(&s);
	while (t != NULL || s.top != 0)
	{
		if (t)
		{
			push(&s, *t);
			if (t->lchild == NULL && t->rchild == NULL)
			{
				for (i = 0; i < q.rear; i++)
				{
					t->encode[i] = q.data[i];
				}
				t->encode[i] = 2;
				if (t->info != NULL)
				{
					printf("%c ", t->info);
					for (i = 0; t->encode[i] != 2; i++)
					{
						printf("%d", t->encode[i]);
					}
				}
				printf("\n");
			}
			if (flag == 0 )
				q.data[q.rear++] = 0;
			if (flag == 1 )
				q.data[q.rear++] = 1;
			t = t->lchild;
			flag = 0;
		}
		else 
		{
			t = pop(&s);
			q.rear--;
			t = t->rchild;
			flag = 1;
		}
	}
}
void init(stack *s)
{
	s->top = 0;
}
void push(stack *s, hufnode a)
{
	s->data[s->top++] = a;
}
hufnode *pop(stack *s)
{
	s->top--;
	return(&s->data[s->top]);
}