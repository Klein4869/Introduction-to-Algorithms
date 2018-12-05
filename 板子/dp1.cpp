#include <iostream>

#define for_up(i, start, end) for(int i = start; i < end; ++i)

using namespace std;

int main(int argc, char *argv[]) {
	int M, N;
	scanf("%d%d",&M, &N);
	long long H[100005];
	for_up(i, 0, N){
		scanf("%lld", &H[i]);
	}
	
}