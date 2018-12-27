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

#include"head.h"
void  ppt()
{
	initgraph(1152, 786);   // 创建绘图窗口，大小为 640x480 像素SHOWCONSOLE
	setbkcolor(WHITE);				// 设置背景色为蓝色
	cleardevice();					//填充
	setcolor(RED);
	circle(576, 25, 25); // 画圆，圆心(576,25)，半径 25
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}

/*
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>

void menu();
int check_button(int,int);
void button1(MOUSEMSG,int,int,int,int);
void button2(MOUSEMSG,int,int,int,int);

/*struct MOUSEMSG
{
	UINT uMsg;      // 当前鼠标消息
	bool mkCtrl;    // Ctrl 键是否按下
	bool mkShift;   // Shift 键是否按下
	bool mkLButton; // 鼠标左键是否按下
	bool mkMButton; // 鼠标中键是否按下
	bool mkRButton; // 鼠标右键是否按下
	int x;          // 当前鼠标 x 坐标
	int y;          // 当前鼠标 y 坐标
	int wheel;      // 鼠标滚轮滚动值
};

typedef struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
}btnode; //树的结构体

int temp;  //根据树的深度得到初始缩减值
int suojian = 1;  //树依次向下时的缩减变量
btnode *t;      //树的根节点


btnode *create(char *pre, char *in, int n) {
	btnode *s;    //当前节点
	char *p;      //中序数据的指针
	int k;        //记录位置
	if (n <= 0) return NULL;   //如果当前递归层次没有数据，返回空指针
	s = (btnode *)malloc(sizeof(btnode));   //为当前节点分配内存空间
	s->data = *pre;                         //当前节点赋值（先序序列的首值）
	for (p = in; p < in + n; p++)
		if (*p == *pre)
			break;                            //查找p的位置
	k = p - in;
	s->lchild = create(pre + 1, in, k);         //创建当前树的左子树
	s->rchild = create(pre + k + 1, p + 1, n - k - 1);  //创建当前树的右子树
	return s;                             //返回当前节点
}//根据先序和中序创建二叉树

btnode *getree(btnode *s, char *str) {
	btnode *p[50], *n = NULL;
	int top = -1, j = 0, k;
	char ch;
	s = NULL;
	while ((ch = str[j++]) != '\0') {
		switch (ch) {
		case '(':top++; p[top] = n; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:n = (btnode *)malloc(sizeof(btnode));
			n->data = ch; n->lchild = n->rchild = NULL;

			if (s == NULL)
				s = n;
			else {
				switch (k) {
				case 1:p[top]->lchild = n; break;
				case 2:p[top]->rchild = n; break;
				}
			}
		}
	}
	return s;
}                              //创建树


int deep(btnode *s) {
	int dl, dr;
	if (s == NULL) return 0;
	else {
		dl = deep(s->lchild);
		dr = deep(s->rchild);
		return (dl > dr) ? (dl + 1) : (dr + 1);
	}
}//求树的深度

void draw(int x, int y, char c) {
	circle(x, y, 20); Sleep(100);//画圈并暂停100ms
	outtextxy(x - 5, y - 5, c);   //输出元素
}


void print(btnode *s, int x, int y) {
	if (s != NULL)
		draw(x, y, s->data);
	if (s->lchild != NULL) {
		suojian++;//缩减值自增1
		line(x - 14, y + 14, x - temp / suojian, y + 100 - 20); Sleep(100);//画线并暂停100ms
		print(s->lchild, x - temp / suojian, y + 100);//递归调用左子树
	}
	if (s->rchild != NULL) {
		suojian++;//缩减值自增1
		line(x + 14, y + 14, x + temp / suojian, y + 100 - 20); Sleep(100);//画线并暂停100ms
		print(s->rchild, x + temp / suojian, y + 100);//递归调用右子树
	}
	suojian--;
}//画树的递归算法


void main() {
	IMAGE img;
	initgraph(1000, 700);        //创建图形窗口
	setfillcolor(RED);       //设置填充色
	setbkcolor(WHITE);         //设置背景色
	settextcolor(GREEN);       //设置文本颜色
	setcolor(BLACK);           //画线的颜色
	setbkmode(TRANSPARENT);    //透明填充
	print(t, 500, 100);            //画二叉树（根节点，根节点x坐标，根节点y坐标）
	getch();                     //暂停
}

void menu() {
	MOUSEMSG m;              //鼠标变量
	IMAGE img;
	bar3d(400, 200, 600, 250, 2, true);        //画实心条
	outtextxy(420, 220, "由先序和中序画二叉树");   //实心条中的文字
	bar3d(400, 260, 600, 310, 2, true);
	outtextxy(420, 280, "输入广义表画二叉树");
	while (1) {
		m = GetMouseMsg();                          //等待鼠标事件
		if (m.uMsg == WM_LBUTTONDOWN)   //当鼠标左键点击时break
			if (check_button(m.x, m.y) == 1)
			{
				button1(m, 400, 200, 600, 250); break;
			}
			else if (check_button(m.x, m.y) == 2)
			{
				button2(m, 400, 260, 600, 310); break;
			}
	}
	cleardevice();	                       //清除图形界面内容
	loadimage(&img, "IMAGE", "back");
	putimage(0, 0, &img);
	setlinestyle(0, 2, NULL);
}


int check_button(int x, int y) {
	if (x > 400 && x < 600 && y>200 && y < 250)
		return 1;
	else if (x > 400 && x < 600 && y>260 && y < 310)
		return 2;
}                                     //检查鼠标按下时的位置

void button1(MOUSEMSG m, int x1, int y1, int x2, int y2) {
	int dis = 1;
	char xianxu[20], zhongxu[20];     //先序序列和中序序列
	int n, high;                //n为序列长度，high为树的高度
	line(x1 + dis, y1 + dis, x2 - dis, y1 + dis);
	line(x2 - dis, y1 + dis, x2 - dis, y2 - dis);
	line(x2 - dis, y2 - dis, x1 + dis, y2 - dis);
	line(x1 + dis, y2 - dis, x1 + dis, y1 + dis);
	Sleep(200);
	//xianxu="ABDGLMHEIKCFJ";
	//zhongxu="MLGDHBEKIACJF";   //为当前序列赋值
	InputBox(xianxu, 20, "请输入先序序列：");
	InputBox(zhongxu, 20, "请输入中序序列：");
	n = strlen(xianxu);          //n获得序列长度
	t = create(xianxu, zhongxu, n);   //创建二叉树
	high = deep(t);
	high--;                      //求得当前高度减1
	temp = 1000 / high;              //获得初始缩减值

}                                        //第一个按键

void button2(MOUSEMSG m, int x1, int y1, int x2, int y2) {
	int dis = 1;
	char str[20];
	line(x1 + dis, y1 + dis, x2 - dis, y1 + dis);
	line(x2 - dis, y1 + dis, x2 - dis, y2 - dis);
	line(x2 - dis, y2 - dis, x1 + dis, y2 - dis);
	line(x1 + dis, y2 - dis, x1 + dis, y1 + dis);
	Sleep(200);
	//str="A(B(D(,G)),C(E,F))";  //为当前树赋值
	InputBox(str, 20, "请输入树，如：A(B(D(,G)),C(E,F))");
	temp = 200;
	t = getree(t, str);
}
*/                                                //这部分功能暂时未做
