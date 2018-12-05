//完全背包

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
		int f[20005] = {0};
		for (int j = 0;j < i;++j) {
			for (int flag = 0; flag <= T;++flag) {//需要计入某个物品已经被选的结果
				if (flag - t[j] >= 0)
					f[flag] = max(f[flag], f[flag-t[j]]+v[j]);//状态转移方程
			}
		}
		cout << f[T] << "\n";
	}
}