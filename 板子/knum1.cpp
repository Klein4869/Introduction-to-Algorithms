#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> s(1000005, 0);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 插入排序
void insertSorting(int *arr, int from, int to) {

    int i, j, t;
    int sc;
    for (i = from + 1; i <= to; ++i) {
        sc = arr[i];
        j = i - 1;
        while(j >= from) {
            // 找到一个不满足arr[j] <= sc
            if (arr[j] > sc) {
                --j;
            } else {
                break;
            }
        }
        // 将arr[j + 1, i - 1]向前移动一个位置
        // 即arr[j + 2, i]
        for (t = i; t > j; --t) {
            arr[t] = arr[t - 1];
        }
        arr[j + 1] = sc;
    }
}

// 讲指定位置pivot的元素作为主元
int partition(int *arr, int from, int to, int pivot) {
    int sc = arr[pivot];
    swap(arr + from, arr + pivot);
    int low = from;
    int high = to;
    while (low < high) {
        while (low < high && sc <= arr[high]) {
            --high;
        }
        arr[low] = arr[high];

        while (low < high && sc >= arr[low]) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = sc;
    return high;
}

// 利用BFPRT 求解第k小元素
//求第k大时用n-k+1
int BFPRT(int *arr, int from, int to, int ith) { //from=0,to=n-1,ith从1开始
    // 当元素小于5个的时候直接插入并且返回
    if(to - from + 1 <= 5) {
        insertSorting(arr, from, to);
        return arr[from + ith - 1];
    }

    int t = from - 1;
    // 作为每5个数组的开始和结束的index
    int st, ed;
    // 至少有一组元素能进入这个循环, 也就是 to - from + 1 > 5
    for (st = from; (ed = st + 4) <= to; st += 5) {
        insertSorting(arr, st, ed);
        ++t;
        swap(arr + t, arr + st + 2);
    }

    // 关心的是中位数的位置，而不是中位数的值
    int pivot = (from + t) >> 1;
    BFPRT(arr, from, t, pivot - from + 1);

    int m = partition(arr, from, to, pivot);
    // pivot 为第几小
    int cur = m - from + 1;

    int res;
    if (cur == ith) {
        res = arr[m];
    } else if (cur < ith) {
        res = BFPRT(arr, m + 1, to, ith - cur);
    } else {
        res = BFPRT(arr, from, m - 1, ith);
    }
    return res;
}

int select_k(int l, int r,int k) //l=0,r=n-1
{   //k=n-k 第k大 k=k-1 第k小
    if(l>=r)    return s[l];

    //rand
    int plot = l + rand()%(r-l+1);
    int tmp = s[plot];
    s[plot] = s[l];
    s[l] = tmp;
    //rand

    //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
    int i = l, j = r, x = s[l];
    while (i < j)
    {
        while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
            j--;
        if(i < j)
            s[i++] = s[j];

        while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
            i++;
        if(i < j)
            s[j--] = s[i];
    }
    s[i] = x;
    if(k==s[i])
        return i;
    else if(k<i)
        return select_k(l, i - 1,k);
    else
        return select_k(i + 1, r,k);
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        int i = 0, k;
        int temp = n;
        while(n--){
            scanf("%lld", &s[i++]);
        }
        scanf("%d", &k);
        sort(s.begin(), s.begin()+i);
        int ans = lower_bound(s.begin(), unique(s.begin(), s.begin()+i), k) - s.begin();
//        printf("%d\n", select_k(1, i-1, temp+1-k));
        printf("%ld\n", unique(s.begin(), s.begin()+i)-s.begin());
        printf("%d\n", ans);
    }
}
