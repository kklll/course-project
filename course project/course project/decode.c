#include"storage.h"
void decode(hufmtree tree[],int new_m)			//依次读入，根据哈夫曼树译码
{
	int i, j = 0;
	char b[maxsize];
	char endflag = '2';					//结束标志取2
	i = new_m - 1;					 //从根结点开始往下搜索
	printf("输入编码(以'2'为结束标志)：");
	gets(b);
	printf("译码后的字符为:\n");
	while (b[j] != '2')
	{
		if (b[j] == '0')
			i = tree[i].lchild;				//走向左孩子
		else
			i = tree[i].rchild;				//走向右孩子
		if (tree[i].lchild == -1)			 //tree[i]是叶结点
		{	
			printf("%c", tree[i].ch);
			i = new_m - 1;						//回到根结点
		}
		j++;
	}
	printf("\n");
	if (tree[i].lchild != -1 && b[j] != '2')			//读完，但尚未到叶子结点
		printf("\n您输入的电文有错请重新输入!\n");		//输入电文有错
}