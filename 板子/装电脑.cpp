//动态规划经典习题
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n, m;
int t[2][505];
int p[505][505], f[505][505];
int dp[505][505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) {
        forUp(i, 0, n-1){
            forUp(j, 0, m-1){
                cin >> p[i][j];
            }
        }
        forUp(i, 0, n-1){
            forUp(j, 0, n-1){
                cin >> f[i][j];
            }
        }

        forUp(i, 0, n-1){
            dp[0][i] = p[i][0];
        }

        forUp(i, 1, m-1){
            forUp(j, 0, n-1){
                int temp = 999999999;
                forUp(k, 0, n-1){
                    temp = min(temp, dp[i-1][k] + f[k][j] + p[j][i]);
                }
                dp[i][j] = temp;
            }
        }

        int ans = dp[m-1][0];
        forUp(i, 1, n-1){
            ans = min(ans, dp[m-1][i]);
        }
        cout << ans << "\n";

    }
    return 0;
}