#include <iostream>
#include <climits>

#define for_up(i, start, end) for(int i = start;i < end; ++i)
using namespace std;

double p[503], q[503];
double e[503][503], w[503][503], root[503][503];

void Optimal_BST(int n){
	for_up(i, 1, n+2){
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	for_up(l, 1, n+1){
		for_up(i, 1, n-l+2){
			int j = i+l-1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for_up(r, i, j+1){
				double t = e[i][r-1] + e[r+1][j] + w[i][j];
				if (t < e[i][j]) {
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	while (~scanf("%d", &n)) {
		for_up(i, 1, n+1){
			scanf("%lf", &p[i]);
		}
		for_up(i, 0, n+1){
			scanf("%lf", &q[i]);
		}
		Optimal_BST(n);
		printf("%.0lf\n", e[1][n]);
	}
}