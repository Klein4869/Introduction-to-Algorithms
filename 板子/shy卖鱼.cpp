#include <iostream>
#include <vector>
#include <algorithm>

#define forUp(i, s, e) for(int i = s; i <= e; i++)

struct Fish{
    long long T;
    long long D;
};

using namespace std;

bool cmp(Fish a, Fish b){
    return a.T*b.D < b.T*a.D;
}

int n;
long long a;
Fish fish[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin>>n) {
        forUp(i,0,n-1){
//            scanf("%lld%lld", &fish[i].T, &fish[i].D);
            cin >> fish[i].T >> fish[i].D;
        }
        sort(fish, fish+n, cmp);
        long long consume = 0;
        long long temp = 0;
        forUp(i, 0, n-1){
            temp += fish[i].D;
        }
        forUp(i, 0, n-1){
            temp -= fish[i].D;
            consume += temp * fish[i].T;
        }
//        printf("%lld\n", consume);
        cout << consume << "\n";
    }

    return 0;
}