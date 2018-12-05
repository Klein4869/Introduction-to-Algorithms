#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		int m[105] = {0};
		int temp = n;
		int i = 0;
		int a, b;
		while (n--){
			cin >> m[i++];
		}
		i = temp - 1;
		a = 0; b = 0;
		while (i >= 0) {
			if(a > b){
				b += m[i];
			}else {
				a += m[i];
			}
			i--;
		}
		cout << max(a, b) << endl;
	}
}