#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string tmp("");
	vector<string>v;
	bool flag = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '"')flag = !flag;
		else if (s[i] == ' '&&flag == false) {
			v.push_back(tmp);
			tmp.clear();
		}
		else {
			tmp.push_back(s[i]);
		}
	}
	v.push_back(tmp);
	cout << v.size() << endl;
	for (auto &e : v) {
		cout << e << endl;
	}
	return 0;
}