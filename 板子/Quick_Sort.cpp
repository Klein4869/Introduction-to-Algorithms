#include <iostream>

void QuickSort(int *a, int first, int last){
	int i = first;
	int j = last;
	int key = a[i];
	while(i < j){
		while(i < j && a[j] >= key)
			j--;
		a[i] = a[j];
		while(i < j && a[i] <= key)
			i++;
		a[j] = a[i];
	}
	a[i] = key;
	QuickSort(a, first, i);
	QuickSort(a, j+1, last);
}

int main(int argc, char const *argv[])
{
	int a[9] = {0,8,7,1,2,3,4,6,5};
	QuickSort(a, )
	return 0;
}