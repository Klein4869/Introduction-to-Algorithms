#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

#define _forUp(i, s, e) for(int i = s; i < e; ++i)
#define _forDown(i, s, e) for(int i = s; i > e; --i)

long long f[100];

int main(){
	srand((unsigned)time(NULL));
	int N;
	while(~scanf("%d",&N)){
		double m = 0;
		_forUp(i, 0, N){
			double x = rand()/(double)RAND_MAX;
			double y = rand()/(double)RAND_MAX;
			double z = sin(x)/x;
			if (y <= z) {
				m++;
			}
		}
		printf("%.3f\n", m/N);
	}
}