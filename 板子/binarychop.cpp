#include <iostream>
#include <algorithm>

using namespace std;

int a[100005] = {0};

int main() {
    int n, t;
    while (cin >> n >> t) {
        int i = 0;
        int temp = n;
        while (n--) {
            cin >> a[i++];
        }
        sort(a, a + i);
        while (t--){
            int que;
            cin >> que;
            int p = lower_bound(a, a+temp, que)-a;
            int q = upper_bound(a, a+temp, que)-a;
            cout << q - p << " ";
        }
        cout << endl;
    }
}
