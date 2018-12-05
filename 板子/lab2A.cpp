#include <iostream>

using namespace std;

void swap_two(int *x, int *y){
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void turn_arr(int a[], int len){
	for (int i = 0;i < len/2;++i) {
		swap_two(&a[i], &a[len-i-1]);
	}
}

int fun_b(unsigned x){
	int val = 0;
	int i;
	for (i = 0;i != 32;++i) {
		val = (x&1) | (2*val);
		x >>= 1;
	}
	return val;
}

int decode2(int x, int y, int z){
	int edx = y;
	edx -= z;
	int eax = edx;
	eax <<= 31;
	eax >>= 31;
	edx *= x;
	eax ^= edx;
	return eax;
}

int foo(int a){
	int i;
	int result = a+2;
	for (i = 0;i < a;++i) {
		result += i + 5;
		result *= i+3;
	}
	return result;
}

void bubble(int x[], int length){
	for (int i = 0; i < length ;++i) {
		for (int j = 0;j < length - i - 1;++j) {
			if (x[j] > x[j+1]) {
				swap_two(&x[j], &x[j+1]);
			}
		}
	}
}

int main(int argc, char *argv[]) {
//	int a = 5, b = 1, ans; 
//
//	asm(
//		"movl %1, %eax;"
//		"mull %2, %eax;"
//		"movl %eax, %0;"
//		:"=r"(ans)
//		:"r"(a), "r"(b)
//		:"%eax"
//	);
//	printf("%d",b); return 0;
//	int x[10] = {9,7,8,10,2,3,5,4,1,6};
//	for (int i = 0; i < 10;++i) {
//		cout << x[i] << " ";
//	}
//	cout << endl;
//	bubble(x, 10);
//	for (int i = 0; i < 10;++i) {
//		cout << x[i] << " ";
//	}
//	cout << endl;
	int x = 1234;
	cout << bitset<sizeof(int)*8>(x) << endl;
	cout << bitset<sizeof(int)*8>(fun_b((unsigned)x)) << endl;
}