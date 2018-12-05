#include <iostream>

using namespace std;

void zeroPack(int *f, int cost, int weight, int T){//01背包的封装
	for (int v = T; v >= cost;--v) {
		f[v] = max(f[v], f[v-cost] + weight);
	}
}

void completePack(int *f, int cost, int weight, int T){//完全背包的封装
	for (int t = cost;t <= T;++ t) {
		f[t] = max(f[t], f[t-cost] + weight);
	}
}

void multiplePack(int *f, int cost, int weight, int T, int amount){//多重背包的封装
	if (cost * amount >= T) {	//如果某件物品的容量大于总容量，则是完全背包问题
		completePack(f, cost, weight, T);
		return;
	}
	int k = 1;
	while (k < amount) {
		zeroPack(f, cost*k, weight*k, T);
		amount = amount - k;
		k *= 2;
	}
	zeroPack(f, cost*amount, weight*amount, T);
}
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int V, N;
		int f[30005]={0};
		cin >> V >> N;
		while(N--){
			int v, w, m;
			cin >> w >> v >> m;
			if(m == 1){
				zeroPack(f, v, w, V);
			}else if(m < 233){
				multiplePack(f, v, w, V, m);
			}else{
				completePack(f, v, w, V);
			}
		}
		cout << f[V] << "\n";
	}
}