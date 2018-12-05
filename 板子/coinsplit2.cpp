#include <iostream>
#include <vector>
#define forinRange(i,s,t) for(int i = s; i <= t; i++)

const int mod = 1e6+7;

using namespace std;

int dp[50005][355];//d[i][j]表示有j个数组成i的方案数

int main()
{
	int i,n,m;
	while(cin >> n){
		dp[1][1] = 1;
		forinRange(i, 2, n) {
			forinRange(j, 1, min(350, i)) {
				dp[i][j] = (dp[i - j][j] + dp[i - j][j - 1])%mod;//分为带1的和不带1的
			}
		}
		long long ans=0;
		forinRange(i, 1, 350)
			ans = (ans + dp[n][i])%mod;
		printf("%d\n", ans);
	}

	return 0;
}