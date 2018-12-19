#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)
#define forDown(i,s,e) for(int i = s; i >= e; --i)

using namespace std;

const double PI = acos(-1.0);

struct Complex{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0){
        x = _x;
        y = _y;
    }
    Complex operator -(const Complex &b)const{
        return Complex(x-b.x, y-b.y);
    }
    Complex operator +(const Complex &b)const{
        return Complex(x+b.x, y+b.y);
    }
    Complex operator *(const Complex &b)const{//???
        return Complex(x*b.x-y*b.y, x*b.y+y*b.x);
    }
};

/*
 *FFT和IFFT之前的反转变换，位置i和（i的二进制反转后位置互换），len必须取2的幂（有的代码也有按位取反的做法，不知是否可行）
*/
void change(Complex y[], int len){
    int i, j ,k;
    for(i = 1, j = len/2; i < len-1; ++i){
        if (i<j) {
            swap(y[i], y[j]);
        }
        k = len/2;
        while(j >= k){
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

/*
 *
 *
*/
void fft(Complex y[], int len, int on){
    change(y, len);
    for (int h = 2;h <= len;h <<= 1) {
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for (int j = 0;j < len;j+=h) {
            Complex w(1, 0);
            for(int k = j; k < j+h/2;++k){
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1){
        for(int i = 0; i < len; ++i)
            y[i].x /= len;
    }
}

const int MAXN = 200010;
Complex x1[MAXN], x2[MAXN];
string s1, s2;
int sum[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> s1 >> s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        int len = 1;
        while(len < len1*2 || len < len2 * 2) len <<= 1;
        //初始化复数数组
        forUp(i, 0, len1-1)
            x1[i] = Complex(s1[len1-1-i] - '0', 0);
        forUp(i, len1, len-1)
            x1[i] = Complex(0, 0);
        forUp(i, 0, len2-1)
            x2[i] = Complex(s2[len2-1-i] - '0', 0);
        forUp(i, len2, len-1)
            x2[i] = Complex(0, 0);
        //
        //求DFT
        fft(x1, len, 1);
        fft(x2, len, 1);
        forUp(i, 0, len-1)
            x1[i] = x1[i]*x2[i];
        //IDFT
        fft(x1, len, -1);
        forUp(i, 0, len-1)
            sum[i] = (int)(x1[i].x+0.5);
        forUp(i, 0, len){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
        len = len1+len2-1;
        while(sum[len] <= 0 && len > 0) len--;
        forDown(i, len, 0)
            cout << sum[i];
        cout << "\n";

    }
    return 0;
}