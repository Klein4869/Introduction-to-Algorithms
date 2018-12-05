#include <iostream>
#include <algorithm>

using namespace std;

typedef struct edge{
    int start;
    int end;
    int weight;
}Edge;

int special = 0;
int edgenum;
Edge _edge[600005];
int i, j, k;
int counter = 0;

bool Cmp(const edge &a, const edge &b){
    return a.weight < b.weight;
}

int getEnd(int vends[], int i){
    if(vends[i] != i)
        vends[i]=getEnd(vends,vends[i]);
    return vends[i];
}

void kruskal(){
    int p1, p2, m, n, ans = 0;
    int vends[10005];
    for(i = 0; i < 10005; ++i){
        vends[i] = i;
    }
    sort(_edge, _edge+counter, Cmp);
    for(i = 0; i < edgenum; ++i){
        p1 = _edge[i].start;
        p2 = _edge[i].end;
        if ((p1 == k || p2 == k) && special)
            continue;

        m = getEnd(vends, p1);
        n = getEnd(vends, p2);

        if(m != n){
            if (p1 == k || p2 == k)
                special = 1;
            vends[m] = n;
            ans += _edge[i].weight;
        }
    }
    cout << ans << endl;
}

int main(){
    int n, m;
    cin >> n >> m >> k;
    edgenum = m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        _edge[counter].start = a;   //Get the Edge
        _edge[counter].weight = c;
        _edge[counter++].end = b;
//        _edge[counter].start = b;
//        _edge[counter].weight = c;
//        _edge[counter++].end = a;
    }
    kruskal();
}