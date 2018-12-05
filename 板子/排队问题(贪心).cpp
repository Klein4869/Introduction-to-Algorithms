#include <iostream>
#include <algorithm>

#define for_up(i, start, end) for(int i = start;i < end; ++i)

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (~scanf("%d", &n)) {
		int a[10005];
		for_up(i, 0, n){
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		long long ans = 0;
		for_up(i, 0, n){
			ans += a[i] * (n-i-1);
		}
		printf("%lld\n", ans);
	}
}