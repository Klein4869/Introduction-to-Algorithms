//思路
/*
1.把所有点放在坐标系中（二维），纵坐标最小的点一定是凸包上的点
2.把所有点坐标平移，使P0作为原点。
3.计算各个点与P0连线与x正方向的夹角，并排序，且第一个点和最后一个点必定是凸包上的点
4.连接栈顶第二个点和栈顶上的点，得到直线L。当前点在L右侧则弹出栈顶，重复步骤，如在左侧则加入栈中，并将下个点作为当前点，如果当前点为最后一个元素，则结束
*/
//

#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

struct Point {
	double x;
	double y;
}p[40000];

double cross_product(Point p0, Point p1, Point p2){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

double dis(Point p1, Point p2){
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool cmp(const Point &p1, const Point &p2){
	double temp = cross_product(p[0], p1, p2);
	if(fabs(temp) < 1e-6){
		return dis(p[0], p1) < dis(p[0], p2);
	}
	else{
		return temp > 0;
	}
}

vector<Point> graham_scan(int n){
	vector<Point> ch;
	int top = 2;
	int index = 0;
	for (int i = 1;i < n; ++i){
		if (p[i].y < p[index].y || (p[i].y == p[index].y && p[i].x < p[index].x)){
			index = i;
		}
	}
	swap(p[0], p[index]);
	ch.push_back(p[0]);

	sort(p+1, p+n, cmp);//按极角排序
	
	ch.push_back(p[1]);
	ch.push_back(p[2]);
	for (int i = 3; i < n; ++i){
		while (top > 0 && cross_product(ch[top-1], p[i], ch[top]) >= 0){
			--top;
			ch.pop_back();
		}
		ch.push_back(p[i]);
		++top;
	}
	return ch;
}

int main(){
	int x, y;
	return 0;
}