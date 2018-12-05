#include <iostream>
#include <vector>
#include <cmath>
#define fir(i, start, end) for(int i = start; i <= end; ++i)

using namespace std;
string num;

int main(){
	int N, M;
	while (~scanf("%d%d", &N, &M)) {
		num = "";
		int i = 1;
		if(N == 1 && M == 1){
			printf("%d\n", 0);
			continue;
		}
		N--;
		num += "0";
		while (N-- && M > pow(2, i)) {
			string s = num;
			fir(i, 0, s.length()-1){
				if(s[i] == '1')
					s[i] = '0';
				else {
					s[i] = '1';
				}
			}
			num += s;
		}
		printf("%d\n", num[M-1]);
	}
}