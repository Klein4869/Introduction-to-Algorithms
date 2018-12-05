#include <cstdio>
#include <cstring>
#include <vector>
#define MaxSize 10005
using namespace std;

int n, m, k;
vector<int> G[MaxSize];//邻接矩阵
int match[MaxSize];//记录匹配点
int visit[MaxSize];//记录是否访问

bool dfs(int x)//寻找增广路径
{
    for (int i = 0; i < G[x].size(); ++i)
    {
        int to = G[x][i];
        if(!visit[to])
        {
            visit[to] = 1;
            if(!match[to] || dfs(match[to]))
            {
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()//一如既往地匈牙利算法
{
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n-1; ++i)
    {
        memset(visit, 0, sizeof(visit));//清空访问
        if(dfs(i)) ans++;//从节点i尝试扩展
    }
    return ans;
}

int main()
{
    while(~scanf("%d %d %d", &n, &m, &k))
    {
        for (int i = 0; i <= n; ++i)
            G[i].clear();

        int a, b;
        for (int i = 1; i <= k; ++i) {
            scanf("%d %d", &a, &b);
            if(a*b != 0)
                G[a].push_back(b);
        }

        printf("%d\n", MaxMatch());
    }
}