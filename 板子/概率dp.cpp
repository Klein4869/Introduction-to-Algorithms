#include <iostream>
#include <cmath>

using namespace std;

long double C[1005][1005];

void pre_C(){//预处理组合数
    C[0][0] = 1;
    for (int i = 1; i < 1005; ++i) {
        C[i][0] = C[i-1][0]/2;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) / 2.0;
        }
    }
}

int main(){
    pre_C();
    int T;
    cin >> T;
    while (T--){
        int n, m, k;
        cin >> n >> m >> k;
        double timer = 1.0/pow(2, k);
        double dp[105][1005];//dp[i][j]表示抛i次后有j次朝上的概率
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 0; j <= n ; ++j)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for(int j = 0; j <= n && j <= i*k; ++j){
                int t;

                for (j-k>=0?t = j-k:t = 0; t <= j; ++t)//不由将正面硬币数减少而达到的量
                {
                    if (t <= n-k)
                    {
                        dp[i][j] += dp[i-1][t] * C[k][j-t];
                    }
                    else{
                        dp[i][j] += dp[i-1][t] * C[k][j - (n-k)];
                    }
                }
                if(j >= n-k)//至多能减少到n-k，至少不减少
                {
                    for (;t <= j+k && t <= n;++t)//将正面硬币数量减少而得到的量
                    {
                        dp[i][j] += dp[i-1][t] * C[k][n-j];
                    }

                }
//                int l;
//                if(j+k < n){
//                    double ans=0;
//                    for (j-k >= 0?l = j-k:l =0; l <= j ; ++l) {
//                        if (l <= n-k)
//                            ans += dp[i-1][l] * C[k][j-l];
//                        else
//                            dp[i][j] += dp[i-1][l] * C[k][j - (n-k)];
//                    }
//                    dp[i][j] = ans;
//                }
//                else{
//                    double ans = 0;
//                    for (j-k >= 0?l = j-k:l = 0; l <= j; ++l) {
//                        if (l <= n-k)
//                            ans += dp[i-1][l] * C[k][j-l];
//                        else
//                            ans += dp[i-1][l] * C[k][j - (n-k)];
//                    }
//                    for (l=j+1; l <=j+k && l <= n; ++l) {
//                        ans += dp[i-1][l] * C[k][n-j];
//                    }
//                    dp[i][j] = ans;
//                }
            }
        }
        double temp[105] = {0};
        for (int l = 0; l <= m; ++l) {
            for (int i = 0; i <= n; ++i)
            {
                temp[l] += dp[l][i];
            }
        }
        double ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans += dp[m][i] * i;
        }
        printf("%.3lf\n", ans);
    }
}