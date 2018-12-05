#include <iostream>
#include <cmath>

using namespace std;

int** getdp (int m, int n)
{
	int **dp = new int *[m + 1];
	for( int i = 0; i <= m; i++ )
	{
		dp[i] = new int[n + 1];
		for( int j = 0; j <= n; j++ )
		{
			dp[i][j] = 1;
		}
	}

	for( int i = 2; i <= m; ++i)
	{
		for( int j = 2; j <= n; ++j)
		{
			if( i > j )
			{
				dp[i][j] = dp[j][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - i];
			}
		}
	}
	return dp;
}

int main()
{
	int i,n,m;
	int **dp = getdp(1001, 10001);
	while(cin >> n >> m){
		cout << dp[m][n-m] << endl;
	}

	return 0;
}