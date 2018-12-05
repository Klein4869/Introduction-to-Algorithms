#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int vends[100005];
int ans[100005];

int getEnd(int i){
    if (vends[i] != i)
        vends[i] = getEnd(vends[i]);
    return vends[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, m;
    cin >> k >> m;
    for (int i = 0; i < 100005; ++i) {
        vends[i] = i;
        ans[i] = 1;
    }
    while(m--){
        int start, end, x, y;
        cin >> start >> end;
        x = getEnd(start);
        y = getEnd(end);
        if (x != y){
            vends[x] = y;
            ans[y] += ans[x];
        }
    }
    int max = 0;
    for (int j = 0; j < 100000; ++j) {
        if (ans[j] > max)
            max = ans[j];
    }
    cout << max << "\n";
}
