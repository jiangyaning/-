 #include <stdio.h>
int dp[100][100];
int main()
{
	int n,k,i,z,j;
	scanf("%d", &n);
	for ( i = 1;i < n;i++)
	{
		for ( j = i + 1;j <= n;j++)
		{
			scanf("%d", &dp[i][j]);
		}
	}

	for ( k = 2;k < n;k++)
	{
		for ( i = 1;i <= n - k;i++)
		{
			int j = i + k;
			for ( z = i + 1;z <= j;z++)
			{
				int temp = dp[i][z] + dp[z][j];
				if (dp[i][j] > temp)
					dp[i][j] = temp;
			}
		}
	}

	printf("%d\n", dp[1][n]);
	return 0;
}