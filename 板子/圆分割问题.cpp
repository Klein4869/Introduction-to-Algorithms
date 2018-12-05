#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define Mod 100007
#define forUp(i,s,t) for(int i = s; i < t; i++)

const int mod = 1e6+7;
int ans[mod];

using namespace std;

bool cmp(int x, int y){
    return x > y;
}

int main()
{
    long long T, n;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld", &n);
        long long ans1;
        long long tmp1, tmp2, tmp3, tmp4;
        tmp1 = 1;
        forUp(i,0,4){
            tmp1 *= n;
            tmp1 %= Mod;
        }
        tmp2 = -6;
        forUp(i, 0, 3){
            tmp2 *= n;
            tmp2 %= Mod;
        }
        tmp3 = 23;
        forUp(i, 0, 2){
            tmp3 *= n;
            tmp3 %= Mod;
        }
        tmp4 = -18;
        forUp(i, 0, 1){
            tmp4 *= n;
            tmp4 %= Mod;
        }
        ans1 = tmp1;
        ans1 = (ans1+tmp2)%Mod;
        ans1 = (ans1+tmp3)%Mod;
        ans1 = (ans1+tmp4)%Mod;
        ans1 = (ans1+24)%Mod;
        if (ans1 < 0)
            ans1 += Mod;
        ans1 = (ans1 % Mod * 4167)%Mod;
        printf("%lld\n", ans1);     
    }
    return 0;
}
