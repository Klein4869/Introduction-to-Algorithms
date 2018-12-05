#include <iostream>

int veca[1000005];

using namespace std;
int main(int argc, char *argv[]) {
	
	int n;
	while(~scanf("%d", &n)){
		int i = 0;
		while (n--) {
			scanf("%d", &veca[i++]);
		}
		int t;
		scanf("%d", &t);
		while (t--) {
			int target;
			scanf("%d", &target);
			int ans = lower_bound(veca, veca+i, target)-veca;
			printf("%d ", ans+1);
		}
		printf("\n");
	}
}