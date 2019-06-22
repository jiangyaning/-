#include <fstream>
#include<iostream>
#include<stdio.h>
using namespace std;
int c[100];//背包每个约束条件的界限
int n ; //物品数目
int m;  //约束条件个数
float w[100][100];//用来存储物品的所占资源
float v[100];//用来存储物品价值
float cw[100] = { 0 };  //当前背包各属性值
float cv;   //当前背包价值
float bestv;//迄今最大的收益
int X[100];  //记录在树中的移动路径,为1的时候表示选择该组数据，为0的表示不选择该组数据
bool z;//用来判断是否超过限界
int j,i;//辅助变量


void pd(int i) {//限界函数，所有m个资源限制都不超过z才为true

	for (int j = 0;j < m;j++) {
		float a = cw[j] + w[j][i];
		if (a - c[j] <= 0)
			z = true;
		else
			z = false;
		if (!z)
			break;
	}

}


void getBestv(int i)
{
	if (i >= n)//递归结束的判定条件
	{
		if (cv > bestv)
			bestv = cv;
		return;
	}
	pd(i);

	if (z)//进入该结点的左孩子（值为1的孩子）
	{
		X[i] = 1;
		//cw[j] = 0;
		for (int j = 0;j < m;j++)
			cw[j] += w[j][i];
		cv += v[i];
		getBestv(i + 1);
		for (int j = 0;j < m;j++)
			cw[j] -= w[j][i];//此处回溯，当到叶子结点或没有活结点时回溯
		cv -= v[i];
	}

	X[i] = 0;//进入该结点的右孩子（值为0的孩子）
	getBestv(i + 1);
}
int main()
{
	ifstream in("input.txt");
	in >> n >> m;
	for ( i = 0;i < n;i++)
		in >> v[i];
	for ( j = 0;j < m;j++) {
		for (int i = 0;i <n;i++) {
			in >> w[j][i];
			 }
	}
	for ( j = 0;j < m;j++)
		in >> c[j];
	in.close();
	cout << "数据输入成功\n";
	getBestv(0);
	printf("最大价值为%.1f", bestv);

	return 0;
}