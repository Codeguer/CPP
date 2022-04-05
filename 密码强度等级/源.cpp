#include<iostream>
#include<string>
using namespace std;

int PasswordLength(const string&s) {
	int size = s.size();
	if (size <= 4)return 5;
	if (size <= 7)return 10;
	return 25;
}

int Alpha(const string&s) {
	bool is_have_alpha = false;
	bool is_both_lower = true;
	bool is_both_capital = true;
	for (auto &e : s) {
		if ((e >= 65 && e <= 90) || (e >= 97 && e <= 122)) {
			is_have_alpha = true;
			if (e >= 65 && e <= 90)is_both_lower = false;
			else is_both_capital = false;
		}
	}
	if (is_have_alpha == false)return 0;
	if (is_both_lower == true || is_both_capital == true)return 10;
	return 20;
}

int Digit(const string&s) {
	int num = 0;
	for (auto &e : s) {
		if (e >= '1'&&e <= '9')++num;
	}
	if (num == 0)return 0;
	if (num == 1)return 10;
	return 20;
}
int Symbol(const string&s) {
	int num = 0;
	for (auto &e : s) {
		if ((e >= 0x21 && e <= 0x2F) ||
			(e >= 0x3A && e <= 0x40) ||
			(e >= 0x5B && e <= 0x60) ||
			(e >= 0x7B && e <= 0x7E))
			++num;
	}
	if (num == 0)return 0;
	if (num == 1)return 10;
	return 25;
}

int Reward(int alpha, int digit, int symbol) {
	if (alpha == 0 || digit == 0)return 0;
	if (alpha == 20 && symbol != 0)return 5;
	if (symbol != 0)return 3;
	return 2;
}

void GiveMark(int sum) {
	if (sum >= 90)cout << "VERY_SECURE" << endl;
	else if (sum >= 80)cout << "SECURE" << endl;
	else if (sum >= 70)cout << "VERY_STRONG" << endl;
	else if (sum >= 60)cout << "STRONG" << endl;
	else if (sum >= 50)cout << "AVERAGE" << endl;
	else if (sum >= 25)cout << "WEAK" << endl;
	else if (sum >= 0)cout << "VERY_WEAK" << endl;
}
int main() {
	string s;
	getline(cin, s);
	int password_length = PasswordLength(s);
	int alpha = Alpha(s);
	int digit = Digit(s);
	int symbol = Symbol(s);
	int reward = Reward(alpha, digit, symbol);
	int sum = password_length + alpha + digit + symbol + reward;
	GiveMark(sum);
	return 0;
}