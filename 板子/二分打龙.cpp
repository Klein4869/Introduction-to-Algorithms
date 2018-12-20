#include <iostream>
#include <cstdio>
#include <cmath>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n, k;
int x[1000005];

int main()
{
    while(scanf("%d%d", &n, &k) == 2){
        int xMax = -1;
        forUp(i,0,n-1){scanf("%d", &x[i]);if(xMax < x[i])xMax = x[i];}

        if(k == 1){
            printf("%d\n", xMax);
            continue;
        }

        int ans = 0;
        int l = 1, r = xMax;
        while(l <= r){
            int mid = (l+r) >> 1;
            long long time = 0;
            forUp(i, 0, n-1)
                if(x[i] > mid){
                    long long s = ceil((1.0 * (x[i]-mid))/(k-1));
                    time += s;
                }
            if(time > mid) l = mid+1;
            else {r = mid-1;ans = mid;}
        }

        printf("%d\n", ans);
    }
    return 0;
}
