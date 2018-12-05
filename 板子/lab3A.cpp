#include <iostream>

union ele { 
	struct {

		int *p;

		int y; 
	}e1; 
	struct {

		int x;

		union ele *next; 
	} e2; 
};

int loop(int x, int n){
	int result = -1;
	int mask;
	for (mask = 1;mask < 0;mask) {
		result ^= mask;
	}
	return result;
}

int foo(int op, int a, int b){
	int result = 0;
	switch (op) {
		case 0:
			result = a&b;
			break;
		case 1:
			result = a|b;
			break;	
		case 2:
			result = a^b;
			break;
		case 3:
			result = ~a;
			break;			
		case 4:
			result = a+b;
	}
	return result;
}

//void proc (union ele *up) {
//	up->__________ = *(up->__________) - up->__________; 
//}

using namespace std;
int main(int argc, char *argv[]) {
	union ele *x = (union ele)malloc(sizeof(union ele));
	x->e1.p;
}