#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node{
    int adjvex;
    int weight;
    struct node *next;
}Node;

typedef struct edge{
    Node *firstNode = NULL;
}Edge;

Edge _edge[2005];

vector<int> u(1005, 0), v(1005, 0), w(1005, 0), t(1005, 0), c(1005, 0);

int main() {
    int n, m, i, j;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    i = 0;
    while (m--) {
        cin >> u[i] >> v[i] >> w[i];
        i++;
    }
    j = 0;
    while (n--) {
        cin >> t[j] >> c[j];
        j++;
    }
    for (int k = 0; k < i; ++k) {
        Node *p = new Node;
        if(t[u[k]] >= w[k]){
            p->weight = t[u[k]];
            p->adjvex = v[k];
        }
        p->next = _edge[u[k]].firstNode;
        _edge[u[k]].firstNode = p;
    }
}