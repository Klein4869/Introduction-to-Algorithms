#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a1[1000005] = {0};
long long sum[1000005] = {0};
long long tmp[1000005] = {0};

long long ans;
int L, R;

void Merge(long long l, long long m, long long r) {
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r) {
		if (sum[i] <= sum[j]) {
			tmp[k++] = sum[i++];
		} else {
			int x = lower_bound(sum + l, sum + m + 1, sum[j] - R) - sum;
			int y = upper_bound(sum + l, sum + m + 1, sum[j] - L) - sum;
			ans += y - x;
			tmp[k++] = sum[j++];
		}
	}
	while (i <= m) tmp[k++] = sum[i++];
	while (j <= r) {
		int temp = sum[j]-R;
		temp = sum[j]-L;
		int x = lower_bound(sum + l, sum + m + 1, sum[j] - R) - sum;
		int y = upper_bound(sum + l, sum + m + 1, sum[j] - L) - sum;
		ans += y - x;
		tmp[k++] = sum[j++];
	}
	for (int i = l; i <= r; i++)
		sum[i] = tmp[i];
}

void Merge_sort(int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		Merge_sort(l, m);
		Merge_sort(m + 1, r);
		Merge(l, m, r);
	}
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	while (T--) {
		int n;
		int i = 1;
		cin >> n >> L >> R;
		ans = 0;
		while (n--) {
			cin >> a1[i];
			sum[i] = sum[i - 1] + a1[i];
			i++;
		}
		if (L <= R) {
			Merge_sort(0, i - 1);
			printf("%lld\n", ans);
		} else {
			printf("0\n");
		}
	}
}