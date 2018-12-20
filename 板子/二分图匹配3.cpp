#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n,m,ans;
vector<int> G[1005];//记录二分图
int match[1005],visit[1005];

int A[1005], B[1005];

bool dfs(int x){//dfs寻找增广路
    for(int i = 0; i < G[x].size();++i){
        int to = G[x][i];
        if(!visit[to]){//to点未访问
            visit[to] = 1;
            if(!match[to] || dfs(match[to])){
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch(){
    ans = 0;
    memset(match,0,sizeof(match));
    forUp(i,1,m){
        memset(visit,0,sizeof(visit));
        if(dfs(i)) ans++;
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        forUp(i,1,1004) G[i].clear();
        forUp(i, 1, n) scanf("%d", &A[i]);
        forUp(i, 1, m){
            scanf("%d", &B[i]);
            forUp(j,1,n){
                if(B[i]%A[j] == 0)
                    G[i].push_back(j);//建立二分图
            }
        }
        printf("%d\n", MaxMatch());
    }
    return 0;
}
