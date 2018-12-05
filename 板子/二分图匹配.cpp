#include <iostream>
#include <cstdio>
#include <cstring>//memset所在地
#include <cstdlib>
#include <vector>

using namespace std;

int n, ans;

vector<int> G[1005];//
int match[1005];
int visit[1005];//记录是否访问

struct followers {
	int attack;//随从的攻击
	int life;//随从的生命值
}A[1005], B[1005];//A[i]记录自己的随从, B[i]记录敌人的随从

bool dfs(int x){//深度优先遍历寻找增广路
	for (int i = 0; i < G[x].size(); ++i)
	{
		int to = G[x][i];
		if (!visit[to]) //如果未被访问过
		{
			visit[to] = 1;//访问记录
			if(!match[to] || dfs(match[to]))//不是匹配点
			{
				match[to] = x;//匹配记录
				return true;
			}
		}
	}
	return false;
}

int maxMatch(){//匈牙利算法最大匹配
	ans = 0;
	memset(match, 0, sizeof(match));//全都为未匹配点
	for (int i = 1; i <= n; ++i)//遍历每个点作为起点，找到一个未匹配点
	{
		memset(visit, 0, sizeof(visit));//全部设为未访问点
		if (dfs(i))//从某节点尝试扩展
		{
			ans++;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		int a, l, p;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a >> l >> p;
			if (p == 0)
			{
				A[i].attack = a;
				A[i].life = l;
			}
			else if (p == 1)
			{
				A[i].attack = a;
				A[i].life = 999999999;
			}
			else if (p == 2){
				A[i].attack = 999999999;
				A[i].life = l;
			}
			else if (p == 3){
				A[i].attack = 999999999;
				A[i].life = 999999999;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> B[i].attack >> B[i].life;
		}
		for (int i = 1; i <= n; ++i)
		{
			G[i].clear();
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (A[i].attack >= B[j].life && A[i].life > B[j].attack)
				{
					 G[i].push_back(j);//第i个随从能攻击的随从(不导致本身死亡)
				}
			}
		}
		if(n == maxMatch())
			cout << "YES\n";
		else{
			cout << "NO\n";
		}
	}
	return 0;
}