#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int flag = 0;
vector<int> a(1000005, 0);

void Qucksort(int low, int high)
{
    if (flag >= 2)
        return;
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[(first + last + 1) /2];/*用字表的第一个记录作为枢轴*/
//    int c = a[first];
//    a[first] = key;
//    a[(first + last+1) /2] = c;

    while(first <= last)
    {
        while (first <= last && a[first] < key) {
            ++first;
        }
        while(first <= last && a[last] > key)
        {
            --last;
        }
        if (first <= last)
            swap(a[first++], a[last--]);
    }
    if (flag == 1){
        for (int i = first; i <= high; ++i) {
            cout << a[i] << " ";
        }
        flag++;
        return;
    }
    flag++;
    Qucksort(low, first-1);
    Qucksort(first+1, high);
}

int main(){
    int i = 0;
    cin >> n;
    while(n--){
        cin >> a[i++];
    }
    Qucksort(0, i-1);
//    for (int j = 0; j < i; ++j) {
//        cout << a[j] << " ";
//    }
    return 0;
}