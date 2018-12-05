#include <iostream>
#include <algorithm>

#define N 50005

using namespace std;

/*----------作业*/
class Jobtype{
	public:
		int operator <= (Jobtype a) const{
			return (key <= a.key);
		};
		int key , index;
		bool job;
};

Jobtype d[N];

/*----------排序*/
bool cmp(Jobtype a , Jobtype b)
{
	return a.key < b.key;
}

/*--------------Johnson算法*/
int FlowShop(int n , int a[] , int b[] , int c[])
{

	for(int i = 0 ; i < n ; i++){
		d[i].key = a[i] > b[i] ? b[i] : a[i];//按Johnson法则分别取对应的b[i]或a[i]值作为关键字
		d[i].job = a[i] <= b[i];//给符合条件a[i]<b[i]的放入到N1子集标记为true
		d[i].index = i;
	}

	sort(d , d+n , cmp);//对数组d按关键字升序进行排序

	int j = 0 , k = n-1;
	for(int i = 0 ; i < n ; i++){
		if(d[i].job)
			c[j++] = d[i].index;//将排过序的数组d，取其中作业序号属于N1的从前面进入
		else    c[k--] = d[i].index;//属于N2的从后面进入，从而实现N1的非减序排序，N2的非增序排序
	}

	j = a[c[0]];
	k = j+b[c[0]];
	for(int i = 1 ; i < n ; i++){
		j += a[c[i]];//M1在执行c[i]作业的同时，M2在执行c[i-1]号作业，最短执行时间取决于M1与M2谁后执行完
		k = j < k ? k+b[c[i]] : j+b[c[i]];//计算最优加工时间
	}

	return k;
}

/*--------main()*/
int main()
{
	int n;
//	cout<<"请输入作业数："<<endl;
	cin>>n;
	int a[n] , b[n] , c[n];
//	cout<<"请输入作业在 M1 M2 上的作业时间："<<endl;
	for(int i = 0 ; i < n ; i++)
		cin>>a[i]>>b[i];
	int mintime = FlowShop(n , a , b , c);
	cout<<mintime<<endl;
//	cout<<"作业调度顺序是："<<endl;
//	for(int i = 0 ; i < n ;i++)
//		cout<<c[i]<<" ";
	cout<<endl;
	return 0;
}