/*
PROBLEM:
	given two n dimensional vectors:
		ex/ <1,2,3,4,5,6> & <-1,5,4,2,3,1>
	find the minimum scalar product

METHOD:
	sort first vector from least to greatest and other from greatest to least
	sum up the products of each element from the new vectors
	return map<case #, answer>, and print out the appropriate output
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
TASK: fill up a vector<vector<int>> with vectors described above
ARGUMENTS: none
RETURN: vector<vector<int>>
*/
vector<vector<int>> init()
{
	vector<vector<int>> holder;

	int line_num;
	cin >> line_num;

	for (int i = 0; i < line_num; i++)
	{
		int x; 
		cin >> x;
		
		for (int c = 0; c < 2; c++)
		{
			vector<int> inside;
			for (int j = 0; j < x; j++)
			{
				int f;
				cin >> f;

				inside.push_back(f);
			}

			holder.push_back(inside);
		}
	}

	return holder;
}

//lambda function used to pass to vector::sort when sorting from greatest to least
auto cmp_l = [](const int& a, const int& b)
{
	return a > b;
};

//lambda function used to pass to vector::sort when sorting from least to greatest
auto cmp_s = [](const int& a, const int& b)
{
	return a < b;
};

/*
TASK: find the minimum scalar product given two vectors
ARGUMENTS: vector<int>, vector<int>
RETURN: int
*/
int min_scalar(vector<int> a, vector<int> b)
{
	int sum = 0;

	for (int i = 0; i < a.size(); i++)
		sum += a.at(i) * b.at(i);

	return sum;
}

/*
TASK: perform the minimum scalar product on each pair of vector<vector<int>> elements (sort them first)
ARGUMENTS: vector<vector<int>>
RETURN: map<int, int>
*/
map<int, int> perform(vector<vector<int>> vvi)
{
	for (int i = 0; i < vvi.size(); i++)
	{
		if (i % 2 == 0) sort(vvi.at(i).begin(), vvi.at(i).end(), cmp_s);
		else			sort(vvi.at(i).begin(), vvi.at(i).end(), cmp_l);
	}

	map<int, int> mii;
	for (int i = 0; i < vvi.size() - 1; i += 2)
	{
		if (i == 0)
			mii.insert(make_pair(i + 1, min_scalar(vvi.at(i), vvi.at(i + 1))));

		else if (i == 2)
			mii.insert(make_pair(i, min_scalar(vvi.at(i), vvi.at(i + 1))));
		else
			mii.insert(make_pair(i - 1, min_scalar(vvi.at(i), vvi.at(i + 1))));
	}

	return mii;
}

int main()
{
	map<int, int> mii = perform(init());

	for (map<int, int>::iterator it = mii.begin(); it != mii.end(); it++)
		cout << "case " << it->first << ": " << it->second << endl;

	system("pause");
	return 0;
}
