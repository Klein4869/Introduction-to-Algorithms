/*
判断点是否在凸多边形内
*/

#include <iostream>
#include <vector>

using namespace std;


struct Point{
    int x;
    int y;
};

double cross_product(Point p0, Point p1, Point p2){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

bool checkInRect(Point p[], Point *pt, vector<int> p_vector){//对于顺序排列的点集
    vector<int>::iterator ele;
    for(ele = p_vector.begin()+1; ele != p_vector.end(); ++ele){
        if (cross_product(*pt, p[*ele], p[*ele-1]) > 0){
            return false;
        }
    }
    return true;
}

vector<int> adjustThePoint( Point p[], int pnum){//将点排序（逆时针），给一个基准向量，然后依次插入即可
    vector<int> p_vector;
    
    if (pnum < 3) {//只有两个点的时候维持原状
        return p_vector;
    }
    
    p_vector.push_back(0);
    p_vector.push_back(1);
    
    for (int i = 2; i < pnum; i++) {
        unsigned long int ii = p_vector.size()-1;
        while (ii > 0) {
            if (cross_product(p[0], p[i], p[ii]) < 0) {
                p_vector.insert(p_vector.begin()+ii+1, i);
                break;
            }
            ii--;
        }
        if(!ii){
            p_vector.insert(p_vector.begin()+1, i);
        }
    }
    
   /* vector<int>::iterator ele;
    for (ele = p_vector.begin(); ele != p_vector.end(); ele++) {
        cout << *ele << ' ';
    }*/
    
    return p_vector;
}

int main(){
    return 0;
}