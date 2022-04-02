#include"MyString.h"

void test() {
	MyString s1("I am a student");
	MyString s2("meimei");
	MyString s3(s1);
	s3 = s2;
}


int main() {
	test();
	return 0;
}