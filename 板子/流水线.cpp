//逛漫展
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n;
int t[2][505];
int p1[505], p2[505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        forUp(i, 0, n-1) cin >> p1[i];
        forUp(i, 0, n-1) cin >> p2[i];
        forUp(i, 0, n-2) cin >> t[0][i];
        forUp(i, 0, n-2) cin >> t[1][i];

        int a1[505]={0}, a2[505]={0};

        a1[0] = p1[0]; a2[0] = p2[0];

        forUp(i, 1, n-1){
            a1[i] = min(a1[i-1] + p1[i], a2[i-1] + t[1][i-1] + p1[i]);
            a2[i] = min(a1[i-1] + t[0][i-1] + p2[i], a2[i-1] + p2[i]);
        }
        cout << min(a1[n-1], a2[n-1]) << "\n";
    }
    return 0;
}