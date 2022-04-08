#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string GetMax(string&s) {
	if (s.find("joker JOKER") != string::npos)return "joker JOKER";
	int ret = s.find('-');
	string s1 = s.substr(0, ret);
	string s2 = s.substr(ret + 1);

	int s1Count = count(s1.begin(), s1.end(), ' ') + 1;
	int s2Count = count(s2.begin(), s2.end(), ' ') + 1;

	string s1First = s1.substr(0, s1.find(' '));
	string s2First = s2.substr(0, s2.find(' '));

	if (s1Count == s2Count) {
		string tmp = "345678910JQKA2jokerJOKER";
		if (tmp.find(s1First) > tmp.find(s2First))return s1;
		else return s2;
	}
	if (s1Count == 4)return s1;
	else if (s2Count == 4)return s2;
	return "ERROR";
}
int main() {
	string s;
	getline(cin, s);
	cout << GetMax(s) << endl;
	return 0;
}