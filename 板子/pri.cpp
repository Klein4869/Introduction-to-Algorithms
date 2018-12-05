#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



struct Info
{
    int score;
    //重载"<"操作符，指定优先级；
    bool operator < (const Info &a) const
    {
        //按score由小到大排列，如果要由大到小排列，使用“>”即可；
        return a.score < score;
    }
};
priority_queue<Info> q;
int main(){
    int n;
    while(~scanf("%d", &n)){
        int i = 0, k;
        int temp = n;
        int temp1;
        Info info;
        long long ans = 0;
        while(n--){
            scanf("%d", &info.score);
            q.push(info);
        }
        int now = q.top().score;
        q.pop();
        while (!q.empty()){
            now += q.top().score;
            q.pop();
            ans += now;
        }

        printf("%d\n", ans);
    }
}
