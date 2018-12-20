#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n;
int A[10005];
short dp[10005][10005];

int main()
{
    while(~scanf("%d", &n)){
        forUp(i, 0, n-1) scanf("%d", &A[i]);
        sort(A,A+n);

        int ans = 2;
        //dp[i][j]代表以A[i],A[j]开头的等差数列的大小
        forUp(i,0,n-2)
            forUp(j,i+1,n-1)
                dp[i][j] = 2;
        forDown(j, n-2, 1){//从后往前计算
            int i = j-1, k = j+1;
            while(i >= 0 && k < n){
                if(A[i]+A[k] < 2*A[j]) k++;
                else if(A[i] + A[k] > 2*A[j]) i--;
                else{
                    dp[i][j] = dp[j][k] + 1;
                    if(dp[i][j] > ans) ans=dp[i][j];
                    i--;k++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
