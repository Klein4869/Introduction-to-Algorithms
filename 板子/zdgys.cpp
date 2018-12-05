#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        if(a<b) swap(a, b);
        while(a%b > 0){
            int c = b;
            int d = a%b;
            a = c;
            b = d;
            if (a < b) swap(a, b);
        }
        cout << b << endl;
    }
}