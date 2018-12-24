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
此文件用来进行编码输出
---------------------------------------------------------------------------------
*/
#include"dynamic_storage.c"
//int  functionbianma(node *head )/*定义编码函数*/
//{
//	int code[10];
//	int n;
//	if (head)
//	{
//		if (head->lchid == NULL && head->rchild == NULL)
//			printf("id为%c权值为%d的叶子节点的哈夫曼编码为：",head->data, head->fru);
//		int i;
//		for (i = 0; i <= n; i++)
//		{
//			printf("%d", code[i]);
//		}
//		printf("\n");
//	}
//	else
//	{
//		code[n] = 0;
//		functionbianma(head->lchild, n + 1);
//		code[n] = 1;
//		functionbianma(head->rchild, n + 1);
//
//	}
//}
//int display(node *head)
//{
//	if (head)
//	{
//		display(head->lchild);
//		printf("id为%c的叶子节点的权值为%d",head->data, head->fru);
//		display(head->rchild);
//
//	}
//}