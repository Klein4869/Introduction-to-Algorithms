
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


struct Info {
	int score;

	bool operator<(const Info &a) const {
		return a.score < score;
	}
};

priority_queue<Info> q;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int i = 0, k;
		int temp = n;
		int temp1;
		Info info;
		long long ans = 0;
		while (n--) {
			scanf("%d", &info.score);
			q.push(info);
		}
		int x;
		while ((x=q.size()) >= 3) {
			int now;
			now = q.top().score;
			q.pop();
			now += q.top().score;
			q.pop();
			now += q.top().score;
			q.pop();

			info.score = now;
			q.push(info);
			ans += now;
		}
		while(!q.empty())
			q.pop();

		printf("%d\n", ans);
	}
}