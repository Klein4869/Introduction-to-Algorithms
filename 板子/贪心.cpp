#include <iostream>
#include <queue>
#include <algorithm>

#define forUp(i, s, e) for(int i = s; i <= e; ++i)

using namespace std;

struct thing{
    int d;
    int e;

    bool operator < (const thing &a) const {
        return a.d > d;
    }
};

thing t[100005];

bool cmp(thing a, thing b){
    return a.e < b.e;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n){
        priority_queue<thing> q;
        forUp(i, 0, n-1){
            int d, e;
            cin >> d >> e;
            t[i].d = d; t[i].e = e;
        }
        sort(t, t+n, cmp);
        long long now = 0;
        int ans = 0;
        int i = 1;
        forUp(i, 0, n-1) {
//            cout << t[i].d << ", " << t[i].e << endl;
            thing tmp;
            tmp.d = t[i].d;
            tmp.e = t[i].e;
            now += t[i].d;
//            cout << now << endl;
            q.push(tmp);
            if (now > tmp.e) {
                now -= q.top().d;
//                cout << now << endl;
                q.pop();
            }
        }
        cout << q.size() << endl;
    }
    return 0;
}