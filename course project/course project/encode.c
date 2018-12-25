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

#include"storage.h"
int count()						//记录文件内节点个数
{
	int count = 0;
	char info;
	int fru;
	FILE *fp = fopen("data.txt", "r");
	while (fscanf(fp, "%c %d\n", &info, &fru) >= 0)
	{
		count++;
	}
	return count;
}

void creat(hufmtree tree[])
{
	int i = 0;
	char info;
	int fru;
	FILE *fp = fopen("data.txt", "r");
	if (fp)
		printf("文件打开成功");
	else
	{
		printf("文件打开失败，请重试！");
		exit(0);
	}
	while (fscanf(fp, "%c %d\n", &info, &fru) >= 0)			 //读入文件数据
	{
		tree[i].ch = info;
		tree[i].weight = fru;
		i++;
	}
}
void huffman(hufmtree tree[],int new_m,int new_n)//建立哈夫曼树
{
	int i, j, p1, p2;						//p1,p2分别记住每次合并时权值最小和次小的两个根结点的下标
	int count;
	int small1, small2, f;
	char c;
	creat(tree);
	for (i = 0; i < new_m; i++)			 //初始化
	{
		tree[i].parent = 0;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = 0;
	}
	for (i = new_n; i < new_m; i++)				 //进行new_n-1次合并，产生new_n-1个新结点
	{
		p1 = 0; p2 = 0;
		small1 = maxval; small2 = maxval;		 //maxval是float类型的最大值
		for (j = 0; j < i; j++)					 //选出两个权值最小的根结点
			if (tree[j].parent == 0)
				if (tree[j].weight < small1)
				{
					small2 = small1;		 //改变最小权、次小权及对应的位置
					small1 = tree[j].weight;
					p2 = p1;
					p1 = j;
				}
				else
					if (tree[j].weight < small2)
					{
						small2 = tree[j].weight;		 //改变次小权及位置
						p2 = j;
					}
		tree[p1].parent = i;
		tree[p2].parent = i;
		tree[i].lchild = p1;				//最小权根结点是新结点的左孩子
		tree[i].rchild = p2;				//次小权根结点是新结点的右孩子
		tree[i].weight = tree[p1].weight + tree[p2].weight;
	}
}
void huffmancode(codetype code[], hufmtree tree[],int new_m,int new_n)//根据哈夫曼树求出哈夫曼编码
//codetype code[]为求出的哈夫曼编码
//hufmtree tree[]为已知的哈夫曼树
{
	int i, c, p;
	codetype cd;
	for (i = 0; i < new_n; i++)
	{
		cd.start = new_n;
		cd.ch = tree[i].ch;
		c = i;						//从叶结点出发向上回溯
		p = tree[i].parent;			//tree[p]是tree[i]的双亲
		while (p != 0)
		{
			cd.start--;
			if (tree[p].lchild == c)
				cd.bits[cd.start] = '0';		 //tree[i]是左子树，生成代码'0'
			else
				cd.bits[cd.start] = '1';		 //tree[i]是右子树，生成代码'1'
			c = p;
			p = tree[p].parent;
		}
		code[i] = cd;							//第i+1个字符的编码存入code[i]
	}
}
