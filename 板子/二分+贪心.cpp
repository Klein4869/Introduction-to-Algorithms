#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

int n, m;
int d[10005];
int sum;

bool check(int x){//检查二分答案是大是小
    int cnt = 0;
    int temp = 0;
    forUp(i, 0, m){
        if (d[i] > x) return false;

        if (temp + d[i] > x){
            temp = d[i];
            cnt++;
        } else
            temp += d[i];
    }
    return cnt <= n-1;
}

int Search(){//二分查找
    int l = 0, r = sum;
    while (l <= r){
        int mid = (l+r)/2;
        if (check(mid))//如果范围比较大，那么则缩小r
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) {//n天只需要露营n-1次
        sum = 0;

        forUp(i, 0, m) {cin >> d[i];sum+=d[i];}//计算最大数

        int ans = Search();//二分查找
        cout << ans << "\n";

        int cnt = 0;
        int temp = 0;
        forUp(i, 0, m){
            if (d[i] + temp > ans || n - 1 - cnt > m-i){//无法再前往下一个营地（满足体力不为0）||仅剩下m-i段
                cout << temp << " ";temp = d[i];cnt++;
            } else temp += d[i];
        }
        cout << temp << "\n";
    }
    return 0;
}