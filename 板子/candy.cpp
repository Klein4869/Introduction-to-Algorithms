#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int N = 1000005;
long long Map[N];
vector<long long> cnt[N], a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, T;
	cin >> n >> m >> T;
	
	for(int i = 0; i <= n + 1; ++i) {//根据m来定cnt与a的大小
		a[i].resize(m + 2);
		cnt[i].resize(m + 2);
	}
	srand(time(0));
	for(int i = n * m; i > 0; --i) //生成随机数
		Map[i] = (rand() * 1LL << 24LL) ^ (rand() << 8LL) ^ (rand() % (1LL << 8));
	
	for(int i = 1, v; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) {	//给每一个抽屉编号
			cin >> v;
			a[i][j] = Map[v];
		}
	while(T--) {
		int x1, y1, x2, y2, v;
		cin >> x1 >> y1 >> x2 >> y2 >> v;
		++x2, ++y2;
		long long w = Map[v];
		cnt[x1][y1] += w;	//由对角线两端元素可以计算出中间的
		cnt[x1][y2] -= w;
		cnt[x2][y1] -= w;
		cnt[x2][y2] += w;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];//前缀和
			ans += (cnt[i][j] % a[i][j]) != 0;	//若cnt不为编号的整数倍则属于不满足要求的抽屉
		}
	cout << ans << "\n";
	return 0;
}