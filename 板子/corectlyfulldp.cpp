#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, k;
	while (cin >> T >> k) {
		int v[305]={0}, t[305] = {0}, i = 0;
		while (k--) {
			cin >> v[i] >> t[i];
			i++;
		}
		int f[20005];
		f[0] = 0;
		for (int l = 1; l < 20005; ++l) {
			f[l] = -(999999);           //初始化为很大的负数，这样只有装满的背包才是正数
		}
		for (int j = 0;j < i;++j) {
			for (int flag = T; flag > 0;--flag) {
				if (flag - t[j] >= 0)
					f[flag] = max(f[flag], f[flag-t[j]]+v[j]);//每样物品不重复则是01背包问题
			}
		}
		if (f[T] > 0)
			cout << f[T] << "\n";
		else
			cout << "jpx" << "\n";
	}
}