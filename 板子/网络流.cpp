#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define N 1010
#define M 1000010
#define inf 1000000000
using namespace std;
int a[N],f[N],S,T,ans,n;
int head[N],dis[N],cnt;
struct node{
    int v,pre,f;
}e[M];
int dp(){//求LIS
    f[1]=1;
    int maxn=1;
    for(int i=2;i<=n;i++){
        int p=0;
        for(int j=i;j>=1;j--)
            if(a[j]<a[i]) 
                p=max(p,f[j]);
        f[i]=p+1;
        maxn=max(maxn,f[i]);
    }
    return maxn;
}
void add(int u,int v,int f){
    e[++cnt].v=v;
    e[cnt].f=f;
    e[cnt].pre=head[u];
    head[u]=cnt;

    e[++cnt].v=u;
    e[cnt].f=0;
    e[cnt].pre=head[v];
    head[v]=cnt;
}
void build1(){
    cnt=1;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++){
        if(f[i]==1) add(S,i,1);
        add(i,i+n,1);
        if(f[i]==ans) add(i+n,T,1);
        for(int j=1;j<i;j++)
            if(a[j]<=a[i]&&f[j]+1==f[i])
                add(j+n,i,1);
    }
}
void build2(){
    cnt=1;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++){
        if(i==1||i==n){
            if(f[i]==1) add(S,i,inf);
            add(i,i+n,inf);
            if(f[i]==ans) add(i+n,T,inf);
        }
        else {
            if(f[i]==1) add(S,i,1);
            add(i,i+n,1);
            if(f[i]==ans) add(i+n,T,1);
        }
        for(int j=1;j<i;j++)
            if(a[j]<=a[i]&&f[j]+1==f[i])
                add(j+n,i,1);
    }
}
bool bfs(){
    memset(dis,-1,sizeof(dis));
    queue<int> q;q.push(S);dis[S]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].pre)
            if(e[i].f&&dis[e[i].v]==-1){
                dis[e[i].v]=dis[u]+1;
                q.push(e[i].v);
                if(e[i].v==T) 
                    return true;
            }
    }
    return dis[T]!=-1;
}
int dinic(int x,int f){
    int rest=f;
    if(x==T) 
        return f;
    for(int i=head[x];i;i=e[i].pre)
        if(dis[e[i].v]==dis[x]+1&&e[i].f){
            int t=dinic(e[i].v,min(rest,e[i].f));
            if(!t) dis[e[i].v]=-1;
            rest-=t;
            e[i].f-=t;
            e[i^1].f+=t;
        }
    return f-rest;
}
int main(){
    scanf("%d",&n);
    S=1;
    T=n*2+1;
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    ans=dp();
    printf("%d\n",ans);
    if(ans==1) 
    {
        printf("%d\n%d",n,n);
        return 0;
    }
    build1();
    int maxflow=0;
    while(bfs()) 
        maxflow+=dinic(S,inf);
    printf("%d\n",maxflow);
    build2();
    maxflow=0;
    while(bfs()) 
        maxflow+=dinic(S,inf);
    printf("%d",maxflow);
    return 0;
}