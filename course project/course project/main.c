﻿//
//1)将权值数据存放在数据文件(文件名为data.txt，位于执行程序的当前目录中)
//2)分别采用动态和静态存储结构
//3)初始化：键盘输入字符集大小n、n个字符和n个权值，建立哈夫曼树
//4)编码：利用建好的哈夫曼树生成哈夫曼编码
//5)输出编码
//6)设字符集及频度如下表：
//字符 空格 A B C D E F G H I J K L M
//频度 186 64 13 22 32 103 21 15 47 57 15 32 20
//字符 N O P Q R S T U V W X Y Z
//频度 57 63 15 1 48 51 80 23 8 18 1 16 1
//【进一步完成内容】
//1)译码功能；
//2)显示哈夫曼树；
//3)界面设计的优化。
//
//时间节点
//星期一	星期二	星期三	星期四	星期五	星期六	星期日
//第17周	上下午
//上机	上下午
//上机	上下午
//上机	上下午
//上机	上下午
//上机	上下午
//上机	休息
//第18周	休息	休息	上下午
//上机	书写课程设计说明书、并调试程序	验收，下午课代表将说明书收齐后统一交给韩慧妍	休息	休息
//
//说明：
//l	14周随堂给学生布置任务，17周周一找指导教师说明需求分析，并汇报任务分配情况，17周周一开始上机
//l	上机时间：上午：8：30 - 11：30	下午：14：00 - 17：30
//l	上机地点：主楼五层504、500、513房间
//l	上机要求：一组两台机器，允许带笔记本，每次（上午或下午）一位同学上机并签到（至少10 - 12次）
//l	需求分析：主要分析课题的内容、需要用的数据结构、小组分工情况；格式不限。（不用交给老师）
//l	课程设计说明书：一组一份。按规定格式书写，组长负责总体，每人完成各自部分。
//l	验收：软件功能包括任务书中的所有任务，每位同学讲解自己的部分；并向指导老师提交纸质课程设计说明书。
//教师联系方式：
//李雯：13834637383
//题目负责教师：李雯
//


/*
---------------------------------------------------------------------------------
此文件为程序主函数进行各函数的调用
---------------------------------------------------------------------------------
*/


//#include <graphics.h>      // 引用图形库头文件
//#include <conio.h>
#include"storage.h"
int main()
{
	int i, j, cou, x, d;
	int new_m, new_n;
	
	cou = count();
	new_n = cou;			//存在数组开辟空间不能动态的解决方法
	new_m = 2 * cou - 1;
	//定义真正的使用量。
	do
	{
		system("color 2");
	
		printf("*********************************菜单*********************************\n");
		printf("***************************哈夫曼编码---请按2*************************\n");
		printf("***************************显示哈夫曼树-请按3*************************\n");
		printf("***************************哈夫曼译码---请按4*************************\n");

		scanf("%d", &x);

		hufmtree tree[m];
		codetype code[n];
		if (x == 2)
		{
			huffman(tree, new_m, new_n);//建立哈夫曼树
			huffmancode(code, tree, new_m, new_n);
			printf("每个字符的哈夫曼编码分别为:\n");
			for (i = 0; i < new_n; i++)
			{
				printf("%c: ", code[i].ch);
				for (j = code[i].start; j < new_n; j++)
					printf("%c ", code[i].bits[j]);
				printf("\n");
			}
		}//根据哈夫曼树求出哈夫曼编码

		if (x == 3)
		{
			system("color 3");
		}
		if (x == 4)
		{
			system("color 5");
			printf("【读入，并进行译码】\n");
			getchar();
			printf("每个字符的哈夫曼编码分别为:\n");
			for (i = 0; i < new_n; i++)
			{
				printf("%c: ", code[i].ch);
				for (j = code[i].start; j < new_n; j++)
					printf("%c ", code[i].bits[j]);
				printf("\n");
			}
			decode(tree, new_m);
		}//依次读入电文，根据哈夫曼树译码
		system("color 4");
		printf("继续操作请按1，退出请按-1\n");
		scanf("%d", &d);
		printf("***********************************************************************\n");
		system("cls");
	} while (d != -1);
	return 0;
}
