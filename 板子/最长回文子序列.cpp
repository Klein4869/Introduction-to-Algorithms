#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin >> s){
		int dp[501][501];
		int n;
		n = s.length();
		for (int i = 0; i < n; ++i)
		{
			dp[i][i] = 1;
		}
		
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; i + j < n; ++j)
			{
				long long tmp;
				if (s[j] == s[j+i])
					tmp = dp[j+1][j+i-1] + 2;
				else
					tmp = max(dp[j+1][j+i], dp[j][j+i-1]);
				dp[j][j+i] = tmp;
			}
		}
		cout << dp[0][n-1] << "\n";
	}
}