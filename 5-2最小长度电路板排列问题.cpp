#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 50;
int p[MAX][MAX];
int bestx[MAX];
int n, m; //��·���������ӿ���

class Node
{
public:
	int dep;  //��ǰ���
	int cd;   //��ǰ���г���
	int* x;   //�洢��ǰ����x[1:dep]
	int* low;  //��·��������ߵ�·��
	int* high; //��·�������ұߵ�·��

	Node()
	{
		cd = 0;
		dep = 0;
		high = new int[m + 1];
		low = new int[m + 1];
		x = new int[n + 1];
	}

	int len()  //���㵱ǰ������С����
	{
		int temp = 0;
		for (int j = 1; j <= m; j++)
		{
			if (low[j] <= n && high[j] > 0 && temp < high[j] - low[j])
				temp = high[j] - low[j];
		}
		return temp;
	}
};


int search()
{
	queue<Node> q;
	Node enode;
	int bestd = n + 1;
	int i, j;
	for (j = 1; j <= m; j++)
	{
		enode.high[j] = 0;
		enode.low[j] = n + 1;
	}
	for (i = 1; i <= n; i++)
		enode.x[i] = i;
	while (true)
	{
		if (enode.dep == n - 1) //��һ�����ӽ�㣬�Ѿ�����n-1����·�壬���������һ��
		{
			for (int j = 1; j <= m; j++)
				if (p[enode.x[n]][j] > 0 && n > enode.high[j])
					enode.high[j] = n;
			enode.cd = enode.len();
			if (enode.cd < bestd)
			{
				bestd = enode.cd;
				copy(enode.x, enode.x + n + 1, bestx);
			}
		}
		else
		{
			int cur = enode.dep + 1;
			for (i = enode.dep + 1; i <= n; i++)  //������ǰ��չ�������ж��ӽ��
			{
				Node now;
				for (int j = 1; j <= m; j++)
				{
					now.low[j] = enode.low[j];
					now.high[j] = enode.high[j];
					if (p[enode.x[i]][j] > 0)
					{
						if (cur < now.low[j])
							now.low[j] = cur;
						if (cur > now.high[j])
							now.high[j] = cur;
					}
				}
				now.cd = now.len();
				if (now.cd < bestd)
				{
					now.dep = enode.dep + 1;
					copy(enode.x, enode.x + n + 1, now.x);
					now.x[now.dep] = enode.x[i];     //�൱�ڻ����е�swap(x[dep], x[i])
					now.x[i] = enode.x[now.dep];
					q.push(now);
				}
			}
		}
		if (q.empty())
			break;
		else
		{
			enode = q.front();  //��һ����չ���
			q.pop();
		}
	}
	return bestd;
}

int main()
{
	ifstream fin("��·��.txt");
	cout << "�����·�������";
	fin >> n; cout << n;
	cout << "\n�������ӿ������";
	fin >> m; cout << m;
	cout << "\n�������\n";
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			fin >> p[i][j];
			cout << p[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n���е���С����Ϊ��" << search();
	cout << "\n�������Ϊ��\n";
	for (i = 1; i <= n; i++)
		cout << bestx[i] << " ";

	cout << endl;
	cout << endl;
	fin.close();
	return 0;
}

