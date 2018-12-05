#include <iostream>

using namespace std;

int fib(int x, int y, int n){
	if (n == 1) {
		return x%100007;
	}
	return fib(y%100007, (x+y)%100007, n-1);
}

int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		cout << fib (2,3,n)%100007 << endl;
	}
}