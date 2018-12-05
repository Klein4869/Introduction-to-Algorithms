#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <map>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

set<string> all_lcs;

int LCS_length(string str1, string str2, vector<vector<int> > &veca, vector<vector<int> > &vecb){//veca记录两个字符串Xi和Yj的LCS长度,最后返回最长子串长度
		int i, j;
		int biggest = 0;
		if (str1 == "" || str2 == "") {//如果任意串为空，则最长公共子序列长度为0
				return 0;
		}
		for (i = 0;i <= str1.length();++i) {
				veca[i][0] = 0;
		}
		for (j = 0;j <= str2.length();++j) {
				veca[0][j] = 0;
		}
		for (i = 1;i <= str1.length();++i) {
				for (j = 1; j <= str2.length();++j) {
						if (str1[i-1] == str2[j-1]) {
								veca[i][j] = veca[i-1][j-1] + 1;
								vecb[i][j] = 1;
						}
						else{
								if (veca[i-1][j] >= veca[i][j-1]) {
										veca[i][j] = veca[i-1][j];
										vecb[i][j] = 2;
								}
								else
								{
										veca[i][j] = veca[i][j-1];
										vecb[i][j] = 3;
								}

						}
				}
		}
		return veca[str1.length()][str2.length()];
}

int LCS_length(const string &str1, const string &str2, vector<vector<int> > &veca) {//和最大公共子序列类似，但是在str1[i] != str2[j]的时候，需要把veca[i][j]归零，而不是等于max{veca[i - 1][j], veca[i][j - 1]}
		int i, j;
		int biggest = 0;
		if (str1 == "" || str2 == "")
				return 0;
		for (i = 0; i <= str1.length(); i++) {
				veca[i].resize(str2.length() + 1, 0);
		}
		for (j = 0; j <= str2.length(); j++) {
				veca[0][j] = 0;
		}
		for (i = 1; i <= str1.length(); i++) {
				for (j = 1; j <= str2.length(); j++) {
						if (str1[i - 1] == str2[j - 1]) {
								veca[i][j] = veca[i - 1][j - 1] + 1;
								if (veca[i][j] > biggest)
										biggest = veca[i][j];//更新最大值
						}
						else
								//可以看出，求最长子串和求最长子序列差别仅仅在这里
								veca[i][j] = 0;

				}
		}
		return biggest;
}

void PrintOneLCS(vector<vector<int> > &vecb, string str1, int i, int j){
		if (i == 0 || j == 0)
				return;
		if (vecb[i][j] == 1){
				PrintOneLCS(vecb, str1, i-1, j-1);
				cout << str1[i-1];
		}
		else if(vecb[i][j] == 2){
				PrintOneLCS(vecb, str1, i-1, j);
		}
		else{
				PrintOneLCS(vecb, str1, i, j-1);
		}
}

void PrintAllLCS(string &str1, string &str2, int i, int j, vector<vector<int> > &veca, string lcs_str){
		while(i > 0 && j > 0){
				if (str1[i-1] == str2[j-1]){
						lcs_str = str1[i-1] + lcs_str;//逆向存放
						--i;--j;
				} else{
						if(veca[i-1][j] > veca[i][j-1]){
								--i;
						} else if(veca[i-1][j] < veca[i][j-1]){
								--j;
						} else{
								PrintAllLCS(str1, str2, i - 1, j, veca, lcs_str);
								PrintAllLCS(str1, str2, i, j - 1, veca, lcs_str);
								return;
						}
				}
		}
		cout << "   " << lcs_str << endl;
		all_lcs.insert(lcs_str);
}

//PS：最长递增子序列也可以转化为求最长公共子序列问题，方法为把序列排序，之后求两个序列的最长公共子序列即可，这里附上非转化的解法其复杂度为nlogn
/*
#include <iostream>
#include <vector>
#define fir(i, start, end) for(int i = start; i <= end; ++i)

using namespace std;
int num[500005];
int lis[500005];

int main(){
	int K, len = 0;
	scanf("%d", &K);
	int i = 0;
	while(K--){
		scanf("%d", &num[i++]);
	}
	int n = i;
	lis[0] = num[0];
	for (i = 0;i < n;++i) {
		if(num[i] > lis[len])
			lis[++len] = num[i];
		else {
			int pos = lower_bound(lis, lis+len, num[i]) - lis;
			lis[pos] = num[i];
		}
	}
	printf("%d\n", len+1);
}
*/

/*o(n^2)解法
 * int getLISLength(int A[], int len) {
	 //定义一维数组并初始化为1
	 int* lis = new int[len];
	 for (int i = 0; i < len; ++i)
			lis[i] = 1;

	 // 计算每个i对应的lis最大值，即打表的过程
	 for (int i = 1; i < len; ++i)
			for (int j = 0; j < i; ++j)     // 0到i-1
				 if ( A[i] > A[j] && lis[i] < lis[j] + 1)
						lis[i] = lis[j] + 1;  // 更新

	 // 数组中最大的那个，就是最长递增子序列的长度
	 int maxlis = 0;
	 for (int i = 0; i < len; ++i)
			if ( maxlis < lis[i] )
				 maxlis = lis[i];

	 delete [] lis;
	 return maxlis;
}

*/
//


int main(int argc, char *argv[]) {
		string str1, str2;
		cin >> str1;
		cin >> str2;
		//将veca初始化为一个二维数组,其行列值分别为str1和str2的长度加1
		//二维数组veca记录的是两个字符串Xi和Yj的LCS长度
		vector<vector<int> > veca(str1.length() + 1, vector<int>(str2.length() + 1));
		vector<vector<int> > vecb(str1.length() + 1, vector<int>(str2.length() + 1));
	cout << LCS_length(str1, str2, veca, vecb) << endl;
		PrintOneLCS(vecb, str1, str1.length(), str2.length());
		cout << endl;
		string lcs_str;
		PrintAllLCS(str1,str2,str1.length(), str2.length(),veca, lcs_str);
		return 0;
}