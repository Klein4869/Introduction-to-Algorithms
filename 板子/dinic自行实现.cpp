/*
思路：
1.初始化容量网络和网络流
2.构造残留网络和层次网络，若终点不在层次网络中，则退出
3.层次网络中使用DFS进行增广
4.转到2
*/
#include <iostream>
#include <queue>
#include <cstring>
#define NUM 1005
#define INF 0x3f3f3f3f

using namespace std;

typedef struct{
	int capacity;//容量
	int flow;//流量
}Edge;

Edge edge[NUM][NUM];
int V, E;//V为边数，E为点数
int level[NUM];//计算

bool BuildHierarchicalNetwork()//构建层次网络，使用BFS
{
	queue<int> q;//辅助队列
	memset(level, 0, sizeof(level));
	q.push(1);//初始时只有起点
	level[1] = 1;//起点的层次为1
	int u, v;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for (v = 1; v <= E; ++v)
		{
			if(!level[v] && edge[u][v].capacity > edge[u][v].flow) {//节点未在层次网络中且该路径未满
				level[v] = level[u] + 1;//分层
				q.push(v);//将节点压入辅助队列
			}
		}
	}
	return level[E] != 0;//汇点如果在分层网络里则level[E]不为0，这里返回true
}

int dinic_dfs(int u, int cp){//深搜找增广
	int tmp = cp;//辅助记录
	int v, t;
	if (u == E)
	{
		return cp;//如果当前节点为汇点，则直接返回
	}
	for (v = 1; v <= E&&tmp; ++v)
	{
		if (level[u] + 1 == level[v])//如果v为当前节点u的下层节点
		{
			if (edge[u][v].capacity > edge[u][v].flow)//仍有剩余容量
			{
				t = dinic_dfs(v, min(tmp, edge[u][v].capacity - edge[u][v].flow));
				edge[u][v].flow += t;
				edge[v][u].flow -= t;
				tmp -= t;
			}
		}
	}
	return cp-tmp;//返回该次增广能增加的容量
}

int dinic(){
	int sum = 0, tf = 0;
	while (BuildHierarchicalNetwork()){//如果能找到包含汇点的层次网络
		while (tf = dinic_dfs(1, INF)){//dinic_dfs(1,INF)不为0的时候循环继续
			sum += tf;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	while(cin >> E >> V){
		for (int i = 0; i < 1005; ++i)
		{
			for (int j = 0; j < 1005; ++j)
			{
				edge[i][j].capacity = 0;
				edge[i][j].flow = 0;
			}
		}
		while(V--){
			int s,e,c;
			cin >> s >> e >> c;//分别是起点、终点、容量
			edge[s][e].capacity += c;
		}
		int ans = dinic();
		cout << ans << "\n";
	}
	return 0;
}