#include"my_vector.h"

int main()
{
	my_std::my_vector<int>vec_arr;
	vec_arr.push_back(1);
	vec_arr.push_back(2);
	vec_arr.push_back(3);
	vec_arr.push_back(4);
	vec_arr.push_back(5);
	vec_arr.push_back(6);


	my_std::my_vector<int>vec_srr;
	vec_srr.push_back(11);
	vec_srr.push_back(12);
	vec_srr.push_back(13);
	vec_srr.push_back(14);
	vec_srr.push_back(15);
	vec_srr.push_back(16);
	vec_arr.swap(vec_srr);
	vec_arr.insert(vec_arr.begin() + 2, 3, 9);
	for (auto e : vec_arr)
	{
		cout << e << endl;
	}


	my_std::my_vector<int>v = vec_arr;
	cout << "*********"<<endl;
	for (auto e : v)
	{
		cout << e << endl;
	}
	cout << "*********" << endl;

	v = vec_srr;
	for (auto e : v)
	{
		cout << e << endl;
	}

	return 0;
}