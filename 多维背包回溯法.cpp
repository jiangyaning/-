#include <fstream>
#include<iostream>
#include<stdio.h>
using namespace std;
int c[100];//����ÿ��Լ�������Ľ���
int n ; //��Ʒ��Ŀ
int m;  //Լ����������
float w[100][100];//�����洢��Ʒ����ռ��Դ
float v[100];//�����洢��Ʒ��ֵ
float cw[100] = { 0 };  //��ǰ����������ֵ
float cv;   //��ǰ������ֵ
float bestv;//������������
int X[100];  //��¼�����е��ƶ�·��,Ϊ1��ʱ���ʾѡ��������ݣ�Ϊ0�ı�ʾ��ѡ���������
bool z;//�����ж��Ƿ񳬹��޽�
int j,i;//��������


void pd(int i) {//�޽纯��������m����Դ���ƶ�������z��Ϊtrue

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
	if (i >= n)//�ݹ�������ж�����
	{
		if (cv > bestv)
			bestv = cv;
		return;
	}
	pd(i);

	if (z)//����ý������ӣ�ֵΪ1�ĺ��ӣ�
	{
		X[i] = 1;
		//cw[j] = 0;
		for (int j = 0;j < m;j++)
			cw[j] += w[j][i];
		cv += v[i];
		getBestv(i + 1);
		for (int j = 0;j < m;j++)
			cw[j] -= w[j][i];//�˴����ݣ�����Ҷ�ӽ���û�л���ʱ����
		cv -= v[i];
	}

	X[i] = 0;//����ý����Һ��ӣ�ֵΪ0�ĺ��ӣ�
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
	cout << "��������ɹ�\n";
	getBestv(0);
	printf("����ֵΪ%.1f", bestv);

	return 0;
}