#include <iostream>
#include <stack>

using namespace std;

int flag_zero;
int flag_pos;

int judge(string str){
	flag_zero = 0;
	flag_pos = -1;
	if (str.length() == 0) {
		return 1;
	}
	stack<int> x;
	int i = 0;
	while(i < str.length()){
		if (str[i] == '(') {
			x.push(1);
		}
		else if (str[i] == ')'){
			if (!x.empty()) {
				x.pop();
			}else {
				return 0;
			}
			if (x.empty()){
				flag_zero++;
				if (flag_zero == 1) {
					flag_pos = i;
				}else if(flag_zero != 1 && flag_zero != 2){
					return 0;
				}
			}
		}
		i++;
	}
	if (flag_zero == 1) {
		string s = str.substr(1, str.length()-2);
		return judge(s);
	}else if (flag_zero == 2) {
		string s1 = str.substr(1, flag_pos-1);
		string s2 = str.substr(flag_pos+2, str.length()-flag_pos-3);
		return judge(s1) && judge(s2);
	}else {
		return 0;
	}
}

int main(int argc, char *argv[]) {
	int n;
//    stack <int> x;
//    x.push(1);
//    return 0;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (judge(str)){
			cout << "Yes" << endl;
		} else{
			cout << "No" << endl;
		}
	}
}