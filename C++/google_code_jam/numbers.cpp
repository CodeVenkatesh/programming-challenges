/*
PROBLEM:
	find last three digits of the integer part of (3 + sqrt(5))^n

METHOD:
	get required input
	do (3 + sqrt(5))^n
	take modf() of each of those values
	return a map<case#, answer>, and display it
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//to make life easier
typedef vector<double> vd;
typedef map<int, int> mii;

/*
TASK: cin however many inputs are required, take (3 + sqrt(5))^([user input]), and store in a vd
ARGUMENTS: none
RETURN: vd
*/
vd init()
{
	int num_lines;
	cin >> num_lines;

	vd v;
	double reg = 3 + sqrt(5);

	for (int i = 0; i < num_lines; i++)
	{
		int power;
		cin >> power;
		v.push_back(pow(reg, power));
	}

	return v;
}

/*
TASK: take the vd from init, find intpart (mod 1000), and map test case # to intpart
ARGUMENTS: vd
RETURN: mii
*/
map<int, int> ans(vd x)
{
	mii m;
	
	for (int i = 0; i < x.size(); i++)
	{
		double fractpart, intpart;
		fractpart = modf(x.at(i), &intpart);

		int it = static_cast<int>(intpart);

		m.insert(make_pair(i + 1, it % 1000));
	}

	return m;
}

int main()
{
	mii m = ans(init());

	for (mii::iterator it = m.begin(); it != m.end(); it++)
		cout << "case " << it->first << ": " << it->second << endl;

	system("pause");
	return 0;
}
