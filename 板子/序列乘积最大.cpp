#include <iostream>
using namespace std;
 
int main() {
	int num[1005]={2,3,-2,4};
	int negMax = num[0], posMax = num[0], ans = num[0];
	for (int i= 1;i < 4;++i) {
		int tempPosMax = posMax, tempNegMax = negMax;
		posMax = max(num[i], max(num[i]*tempPosMax, num[i]*tempNegMax));//记录前面最大值
		negMax = min(num[i], min(num[i]*tempPosMax, num[i]*tempNegMax));//记录前面最小值
		ans = max(ans, posMax);
	}
	cout << ans << endl;
}
