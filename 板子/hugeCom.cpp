#include <iostream>

using namespace std;
const long long M = 100007;
long long ff[M+5];  //打表，记录n!，避免重复计算

//求最大公因数
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

//解线性同余方程，扩展欧几里德定理
long long x,y;
void Extended_gcd(long long a,long long b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}

//计算不大的C(n,m)
long long C(long long a,long long b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    long long c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}

//Lucas定理
long long Combination(long long n, long long m)
{
    long long ans=1;
    long long a,b;
    while(m||n)
    {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
    return ans;
}

int main()
{
    long long i,n;
    ff[0]=1;
    for(i=1;i<=M;i++)  //预计算n!
        ff[i]=(ff[i-1]*i)%M;

    while(cin >> n){
        long long b = n/2LL;
        long long a = n-b;
        long long ans = 0;
        for (; b <= n ; ++b, a--) {
            ans = ans%M + Combination(b+1LL, a)%M;
        }
        cout << ans%M << endl;
    }

    return 0;
}
