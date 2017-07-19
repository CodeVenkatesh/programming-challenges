#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>

T digital_root(T x)
{
	string s = to_string(x);

	T sum = 0;
	for (string::iterator it = s.begin(); it != s.end(); it++)
		sum += *it - 48;

	if (s.size() == 1) return sum;
	else return digital_root(sum);
}

template<typename T>
bool isprime(T x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return false;

	return true;
}

template<typename T>
vector<T> p_seq(T exit)
{
	T count = 2;
	vector<T> vt;

	do
	{
		if (isprime(count)) vt.push_back(count);

	} while (count != exit);

	return vt;
}

template<typename T>
vector<T> c_seq(T exit)
{
	T count = 2;
	vector<T> vt;

	do
	{
		if (!(isprime(count))) vt.push_back(count);

	} while (count != exit);

	return vt;
}

int main()
{
	cout << digital_root(258) << endl;
	system("pause");
	return 0;
}

