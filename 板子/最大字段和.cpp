#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n;
long long a[2000010];
long long b[2000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        if(n == 0) {
            cout << 0 << "\n";
            continue;
        }
        forUp(i, 0, n-1) cin >> a[i];
        b[0] = a[0];
        long long ans = 0;
        if(b[0] > 0)
            ans = b[0];
        forUp(i, 1, n-1){
            b[i] = max(b[i-1]+a[i], a[i]);
            if (b[i] > ans){
                ans = b[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}