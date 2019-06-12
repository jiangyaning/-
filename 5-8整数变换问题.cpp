/*��һ��������������¼��sign[]�����¼��ǰ��·������minsign[]��¼���ٱ任��������Ӧ��·����
sign[]��minsign[]����ʼ��Ϊ-1�����ֵΪ0��ʾ������f�����ֵΪ1��ʾ������g��
��һ��whileѭ������minsign����ӡ����Ӧ�ĺ�������
*/
#include<iostream>
#include<fstream>
#include<sstream> 
using namespace std;

class IntChange {
public:
	int n;//���任������
	int m;//��Ҫ�任�ɵ�����
	int nowcount;//��ǰ�ѱ任�Ĵ��� 
	int mincount;//��¼��С�ı任����
	int* sign;//��¼·����0��ʾ������f,1��ʾ������g 
	int* minsign;//��¼��С�任������·�� 
	int* recordx;//��¼���ֹ���ֵ 

	int Backtrack(int x);

	int test(int x) {
		int i = 1;
		while (recordx[i] != -1) {
			if (x == recordx[i])	return 0;
			i++;
		}
		return 1;
	}

	int f(int i) {
		return 3 * i;
	}

	int g(int i) {
		return i / 2;
	}
};

int IntChange::Backtrack(int x)
{
	if (test(x) == 0) {
		return 0;
	}//���n�Ƿ��ܹ�ת��Ϊm 
	if (x == m) {
		if (nowcount < mincount) {
			mincount = nowcount;
			for (int i = 1;i <= n;i++) minsign[i] = sign[i];
		}
		return 1;//���� 
	}
	nowcount++;
	recordx[nowcount] = x;
	if (nowcount < mincount) {//��ǰ�ı任����С��mincount 
		if (x < m) {
			sign[nowcount] = 0;
			Backtrack(f(x));//��xС��mʱ�Ƚ���������	    	
		}
		else {
			sign[nowcount] = 1;
			Backtrack(g(x));//��X����mʱ���������� 			
		}
	}
}

void Compute(int n, int m, ofstream& outfile)
{
	IntChange ic;//ʵ����һ������
	ic.n = n;
	ic.m = m;
	ic.nowcount = 0;
	ic.mincount = INT_MAX;
	ic.sign = new int[256];
	ic.minsign = new int[256];
	ic.recordx = new int[256];
	for (int i = 0;i <= n;i++) {
		ic.sign[i] = -1;ic.minsign[i] = -1;ic.recordx[i] = -1;//��ʼ��Ϊ-1 
	}

	if (ic.Backtrack(ic.n) == 1) {
		outfile << ic.mincount << endl;
		int i = 1;
		while (ic.minsign[i] != -1) {
			if (ic.minsign[i] == 0) outfile << "f";
			else outfile << "g";
			i++;
		}
		outfile << endl;
	}
	else {
		outfile << ic.n << "�޷�ת��Ϊ" << ic.m << endl;
	}
	delete[]ic.sign;
	delete[]ic.minsign;
}


int main() {
	ifstream cinfile;
	cinfile.open("input.txt", ios::in);
	int n, m;
	cinfile >> n >> m;
	cinfile.close();

	ofstream outfile;
	outfile.open("output.txt", ios::out);
	Compute(n, m, outfile);
	outfile.close();
	return 0;
}

