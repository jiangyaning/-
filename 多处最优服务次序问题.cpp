#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int i, n, j, k, minx;
	int s;
	double t;
	int a[10005], b[1005];
	while (cin >> n >> s)
	{
		for (i = 0;i < n;i++)
			cin >> a[i];
		sort(a, a + n);//快速排序服务时间
		memset(b, 0, sizeof(b));
		for (i = 0;i < n;i++)
		{
			minx = 0x7fffffff;
			k = 0;
			for (j = 0;j < s;j++)
			{
				if (minx > b[j])
				{
					minx = b[j];
					k = j;
				}
			}
			b[k] += a[i];
			a[i] = b[k];
		}
		t = 0;
		for (i = 0;i < n;i++)
			t += a[i];
		t /= n;
		printf("%d\n", (int)(t + 0.5));
	}
	return 0;
}
