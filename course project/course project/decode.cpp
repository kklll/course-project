#include"head.h"
void decode(hufnode tree[])			//依次读入，根据哈夫曼树译码
{
	hufnode *t;
	int i = 0, j = 0;
	char b[200];
	char endflag = '2';
	getchar();			//结束标志取2				 //从根结点开始往下搜索
	printf("输入编码(以'2'为结束标志)：");
	gets_s(b);
	printf("译码后的字符为:\n");
	t = &tree[0];
	while (b[j] != '2')
	{
		if (b[j] == '0')
		{
			t = t->lchild;
		}			//走向左孩子
		else
		{
			t = t->rchild;
		}			//走向右孩子
		if (t->lchild == NULL)			 //tree[i]是叶结点
		{
			printf("%c", t->info);
			t = &tree[0];//回到根结点
		}
		j++;
	}
	printf("\n");
	if (tree[j].lchild != NULL && b[j] != '2')			//读完，但尚未到叶子结点
		printf("\n您输入的电文有错请重新输入!\n");		//输入电文有错
}
