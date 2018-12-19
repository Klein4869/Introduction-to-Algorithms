#include <iostream>
#define MAX 999999999

using namespace std;

int M,S,T,min_t,max_dis;

int main()
{
    while(cin>>M>>S>>T){
        min_t = MAX;
        max_dis = -1;
        for(int i = 0;i <= 10 && T >= i && S - 17*i >= 0; ++i)
        {
            int m = M+i;
            int time = i, dis = 17*i;
            while(time < T && dis < S){
                if(m < 10) m += 5;
                else{m-=9;dis+=60;}

                time++;
            }
            if(dis >= S) min_t = min(min_t, time);
            if(dis < S) max_dis = max(max_dis, dis);
        }
        if(min_t != MAX) cout << "Yes\n" << min_t << "\n";
        else cout << "No\n" << max_dis << "\n";
    }
    return 0;
}

