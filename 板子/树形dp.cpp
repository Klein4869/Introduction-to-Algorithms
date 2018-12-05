#include <iostream>
#include <cstring>

#define forUp(i, s, e) for(int i = s; i <= e; ++i)

using namespace std;

int n;
int dp[6005][2];//dp[i][0]代表i没去, dp[i][1]代表i去了
int father[6005];
bool visit[6005];

void tree_dp(int node)
{	
	visit[node] = 1;
	forUp(i, 1, n)
	{
		if (!visit[i] && father[i] == node)//如果未访问过且父节点为node
		{
			//递归调用孩子节点
			tree_dp(i);
			dp[node][1] += dp[i][0];//父去子不去
			dp[node][0] += max(dp[i][1], dp[i][0]);//子去父不去，子不去父不去
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	int f,c,root;
	while(cin >> n){
		memset(dp, 0, sizeof(dp));
		memset(father, 0, sizeof(father));
		memset(visit, 0, sizeof(visit));
		forUp(i, 1, n){
			cin >> dp[i][1];
		}
		int x,y;
		while(cin >> x >> y&& (x != 0 && y!= 0)){
			father[x] = y;
		}
		while(father[x]){
			x = father[x];
		}
		tree_dp(x);
		cout << max(dp[x][0], dp[x][1]) << "\n";
	}
	return 0;
}