#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

/*
FIX: ACCOUNT FOR POSSIBILITY OF NON-OVERLAP
*/

class paint
{
public:
	map<int, int> input();
	int total(map<int, int>);
};

auto compare1 = [](const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
};

auto compare2 = [](const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
};

map<int, int> paint::input()
{
	int a, b;
	cin >> a >> b;
	map<int, int> mii;

	while (a != -1 && b != -1)
	{
		mii.insert(pair<int, int>(a, b));
		cin >> a >> b;
	}

	return mii;
}

int paint::total(map<int, int> mii)
{
	vector<pair<int, int>> items;
	copy(mii.begin(), mii.end(), back_inserter(items));

	sort(items.begin(), items.end(), compare1);
	int min = items.at(0).first;

	sort(items.begin(), items.end(), compare2);
	int max = items.at(0).second;

	return max - min;
}

int main()
{
	paint p;

	cout << p.total(p.input()) << endl;

	system("pause");
	return 0;
}

