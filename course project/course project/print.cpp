/*
---------------------------------------------------------------------------------
此文件用来进行编码图形化界面输出
---------------------------------------------------------------------------------
*/

#include"head.h"					//引入总头文件
void  draw_main(hufnode *s)
{
	int a = 1400;
	int b = 0;
	initgraph(1920, 1080);			// 创建绘图窗口，SHOWCONSOLE
	setbkcolor(WHITE);			// 设置背景填充颜色
	cleardevice();						//进行填充
	setcolor(BLACK);
	drawdemo(s, 860, 20, a, b);				//递归调用画树的子文件
	_getch();						 // 检测键盘输入时间。
	closegraph();					 // 关闭绘图窗口

}


void draw(int x, int y, char c)
{
	circle(x, y, 10); Sleep(100);//画圈并暂停100ms
	outtextxy(x - 5, y - 7, c);   //输出元素
}

void drawdemo(hufnode *s, int x, int y, int temp, int suojian)  //前序遍历递归输出图形化huffman树
{
	if (s != NULL && s->info != 'J'&&s->info != 'Z') //避免结点过多J，Z节点重合
		draw(x, y, s->info);
	if (s->lchild != NULL)
	{
		if (s->lchild->info != 'J')
		{
			suojian += 4;//缩减值自增
			line(x - 8, y + 8, x - temp / suojian, y + 50 - 10); outtextxy(x - (8 + temp / suojian) / 2, y + 19, '0'); Sleep(10);//画线并暂停10ms
			drawdemo(s->lchild, x - temp / suojian, y + 50, temp, suojian);//递归调用左子树
		}
		else
		{
			line(x - 8, y + 8, x - 25, y + 50 - 10); outtextxy(x - 25, y + 19, '0'); Sleep(10);
			draw(x - 25, y + 50, s->lchild->info);
		}   //使J，Z节点分隔开
	}
	suojian -= 4;
	if (s->rchild != NULL)
	{
		if (s->rchild->info != 'Z')
		{
			suojian += 4;//缩减值自增
			line(x + 8, y + 8, x + temp / suojian, y + 50 - 10); outtextxy(x + (8 + temp / suojian) / 2, y + 19, '1'); Sleep(10);//画线并暂停10ms
			drawdemo(s->rchild, x + temp / suojian, y + 50, temp, suojian);//递归调用右子树
		}
		else
		{
			line(x + 8, y + 8, x + 25, y + 50 - 10); outtextxy(x + 25, y + 19, '1'); Sleep(10);
			draw(x + 25, y + 50, s->rchild->info);
		}   //使J，Z节点分隔开
	}
	suojian -= 4;
}
