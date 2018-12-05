#include <iostream>
#include <cstring>

using namespace std;

int n;
string x;
long long ans;
long long dp[25][25];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		cin >> x;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = x[0] - '0';
		for (int i = 1; i < x.length(); ++i)//0个乘号时的初始化
		{
			dp[i][0] = dp[i-1][0] * 10 + (x[i] - '0');
		}
		for (int i = 0; i < x.length(); ++i)//遍历数组不同长度
		{
			int tmp = (n < i?n:i);//添加乘号的最多数
			for (int j = 1; j <= tmp; ++j)//遍历所有乘号数量
			{
				for (int k = 1; k <= (i-j+1); ++k)//遍历所有能添加乘号的位置（i-k）
				{
					long long temp = dp[i-k][j-1];
					long long temp2 = 0;
					for (int l = i-k+1; l <= i; ++l)
					{
						temp2 = temp2 * 10 + (x[l] - '0');
					}
					ans = temp * temp2;
					if(dp[i][j] < ans)
						dp[i][j] = ans;
				}
			}
		}
		cout << dp[x.length()-1][n] << "\n";
	}
	return 0;
}