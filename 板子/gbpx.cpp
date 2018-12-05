#include <iostream>
#define MAXINUM 10000

int num[MAXINUM];
long res = 0;
int ans[MAXINUM];

void Merge(int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int i = 0, j = 0, k;
    int L[n1+1], R[n2+1];
    for(i=0; i < n1; ++i){
        L[i] = num[p+i];
    } 
    for(j=0; j < n2, ++j){
        R[j] = num[q+j+1];
    }
    L[n1] = R[n2] = INT_MAX;
    i = 1;
    j = 1;
    for(k = p; k <= r; ++k){
        if (L[i] <= R[j])
        {
            ans[k] = L[i++];
        }
        else{
            ans[k] = R[j++];
        }
    }
}

void Merge_Sort(int p, int r){
    if (p < r)
    {
        q = (p + r)/2;
        Merge_Sort(p, q);
        Merge_Sort(q+1, r);
        Merge(p, q, r);
    }
}

int main(){
    return 0;
}