#include <iostream>

#define forUp(i,s,e) for(int i = s; i <= e; ++i)

using namespace std;

int n;
int v[100005];
int dp1[100005], dp2[100005];

int main(int argc, char *argv[]) {
	while (cin >> n) {
		forUp(i, 0, n-1) cin >> v[i];
		
		if (n == 1) {
			cout << v[0] << "\n";
			continue;
		}
		
		dp1[0] = v[0];
		dp1[1] = max(dp1[0], v[1]);
		
		dp2[0] = v[1];
		dp2[1] = max(dp2[0], v[2]);
		
		forUp(i, 2, n-2) dp1[i] = max(dp1[i-1], dp1[i-2] + v[i]);
		forUp(i, 2, n-2) dp2[i] = max(dp2[i-1], dp2[i-2] + v[i+1]);
		
		cout << max(dp1[n-2], dp2[n-2]) << "\n";
	}
}