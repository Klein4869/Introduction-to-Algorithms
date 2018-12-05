#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node{
    int adjvex;
    int is_find = 0;
    struct node* next;
}Node;

typedef struct edge{
    Node *firstNode = NULL;
}Edge;

vector <int> DFN(105, 0);
vector <int> LOW(105, 0);
vector <int> visit(105, 0);
vector <int> s;
vector <int> instack(105, 0);
int counter = 0;
int vertexNum;
int flag;

void tarjan(Edge _edge[], int u){
    DFN[u] = LOW[u] = ++counter;
    visit[u] = 1;
    s.push_back(u);
    instack[u] = 1;

    node *p = _edge[u].firstNode;

    while (p != NULL){
        int v = p->adjvex;
        if (visit[v] == 0){
            tarjan(_edge, v);
            LOW[u] = min(LOW[u], LOW[v]);
        } else if (instack[v]){
            LOW[u] = min(LOW[u], DFN[v]);
        }
        p = p->next;
    }
    int m, num = 0;
    if (DFN[u] == LOW[u]){
        do{
            m = s[s.size() - 1];
            s.pop_back();
            instack[m] = 0;
            num++;
        }while (m!=u);
        if (num == vertexNum){
            flag = 1;
        }
    }
}

int main(){
    int k, m;
    while(cin >> k >> m){
        int i = 0;
        Edge n[105];
        while (m--) {
            int start, end;
            node *p = new Node;
            node *q = new Node;
            cin >> start >> end;
            p->adjvex = end;
            q->adjvex = start;
            p->next = n[start].firstNode;
            n[start].firstNode = p;
            q->next = n[end].firstNode;
            n[end].firstNode = q;
            i++;
        }
        vertexNum = k;
        flag = 0;
        for (int j = 0; j < 105; ++j) {
            DFN[j] = 0;
            LOW[j] = 0;
            s.clear();
            visit[j] = 0;
            instack[j] = 0;
        }
        tarjan(n, 0);
        if (flag == 1){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
}