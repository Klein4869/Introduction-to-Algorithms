#include <iostream>
#include <cstring>
#include <cmath>

#define forUp(i, s, e) for(int i = s; i <= e; ++i)

using namespace std;

struct pos{
	double x;
	double y;

	pos &operator - (const pos &a) const{//定义向量减法
		double x_tmp = x - a.x;
		double y_tmp = y - a.y;
		pos p;p.x = x_tmp;p.y=y_tmp;
		return p;
	}

	double mod(){//获得向量长度
		return sqrt(x*x+y*y);
	}
};

double dot(pos a, pos b){//点乘
	return a.x * b.x + a.y * b.y;
}

int n, m, min_yA, min_yB;
pos friends[10004], enemy[10004];
int flagA[10004], flagB[10004];//记录凸包中的点
pos now, before;

bool search(pos *point, int *f){
	double max_cos = -0x3f3f3f3f;
	int max_cos_index;
	forUp(i, 0, n-1){
		pos p1 = now - before;
		pos p2 = point[i] - now;
		if(p2.x == 0 && p2.y == 0)
			continue;
		double _cos = dot(p1, p2)/(p1.mod()*p2.mod());
		if(_cos > max_cos){
			max_cos = _cos;
			max_cos_index = i;
		}
	}
	if(f[max_cos_index] == 0){
		f[max_cos_index] = 1;
		before = now;
		now = point[max_cos_index];
		return true;
	}else{
		return false;
	}
}

int main(){
	cout << "Start:" << endl;
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m){
		int y_minA = 0x3f3f3f3f, y_minB = 0x3f3f3f3f;
		memset(flagA, 0, sizeof(flagA));
		memset(flagB, 0, sizeof(flagB));
		forUp(i, 0, n-1){
			cin >> friends[i].x >> friends[i].y;
			if (y_minA > friends[i].y){
				min_yA = i;
				y_minA = friends[i].y;
			}
		}
		flag[min_y] = 1;
		forUp(i, 0, m-1){
			cin >> enemy[i].x >> enemy[i].y;
			if (y_minB > enemy[i].y){
				min_yB = i;
				y_minB = enemy[i].y;
			}
		}
		now = friends[min_y];
		before.x = now.x-1; before.y = now.y;
		while(search(friends, flagA));
		while(search(enemy, flagB));
		forUp(i, 0, n-1){
			if(flagA[i]){
				cout << i << " ";
			}
		}
		forUp()
		cout << endl;
	}

}