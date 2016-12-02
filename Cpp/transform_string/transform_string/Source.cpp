/*
TASK: take a string s1 and find the least number of "moves" it takes to transform it into s2
METHOD: 
	- get a representation of the string (vector<pair<char, int>>)
		- example: magician magical
		[['m', 1], ['a', 1], ..., ['n', 1]]
		[['m', 1], ['a', 2], ..., ['l', 1]]

		if pair.first's match then keep it
		(we essentially want this such that all pair.first's match and pair.second's match)

		for the ones that don't match, remove as many as them as possible until s1.size() = s2.size()
		then do a comparison on pair.seconds, and remove as many as needed until they match up
		result = match
*/

/*#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <typeinfo>
#include <unordered_map>

using namespace std;

typedef unordered_multimap<char, int> umm;

/*
TASK: see if a character is contained within a string
ARGUMENTS: char, string
RETURN: bool


template<typename W, typename T, typename C>

int contains(W check, unordered_multimap<T, C> mtc)
{
	if (!(typeid(W) == typeid(T) || typeid(W) != typeid(C))) return 0;

	else
	{
		int count = 0;
		for (unordered_multimap<T, C>::iterator it = mtc.begin(); it != mtc.end(); it++)
		{
			if (mtc.find(it->first)->first == check) count++;
			else if (mtc.find(it->first)->second == check) count++;
		}

		return count;
	}
}

/*
TASK: determine if the specified data is within a unordered_multimap<T, C>
ARGUMENTS: W, unordered_multimap<T, C>
RETURN: bool


template<typename W, typename T, typename C>

bool exists(W check, unordered_multimap<T, C> mtc)
{
	if (!(typeid(W) == typeid(T) || typeid(W) != typeid(C))) return false;
	
	else return mtc.count(check) > 0;
}

/*
TASK: generate a representation like the one described above
ARGUMENTS: string
RETURN: umm


umm gen_rep(string s)
{
	umm mci;

	int count = 0;
	for (string::iterator it = s.begin(); it != s.end(); it++)
			mci.emplace(make_pair(*it, 1));

	return mci;
}

/*
TASK: determine all unique letters in a string
ARGUMENTS: string
RETURN: string


string remains(string s)
{
	umm mci = gen_rep(s);
	string k;

	for (umm::iterator it = mci.begin(); it != mci.end(); it++)
		k += mci.find(it->first)->first;

	return k;
}

/*
TASK: separate the representations into the part that is shared by both and the part that isn't shared by both
ARGUMENTS: umm, umm
RETURN:	unordered_multimap<char, vector<int>>


unordered_multimap<char, vector<int>> separate(umm mci1, umm mci2)
{	
	if (mci1.size() < mci2.size())
	{
		unordered_multimap<char, vector<int>> _mci1;

		for (umm::iterator it = mci1.begin(); it != mci1.end(); it++)
		{
			vector<int> vi;
			vi.push_back(it->second);

			_mci1.emplace(make_pair(it->first, vi));
		}

		for (umm::iterator it = mci2.begin(); it != mci2.end(); it++)
		{
			vector<int> vi;

			if (_mci1.find(it->first) == _mci1.end())
			{
				vi.push_back(it->second);
				_mci1.emplace(make_pair(it->first, vi));
			}

			else _mci1.find(it->first)->second.push_back(it->second);
		}

		return _mci1;	
	}

	else
	{
		unordered_multimap<char, vector<int>> _mci2;

		for (umm::iterator it = mci2.begin(); it != mci2.end(); it++)
		{
			vector<int> vi;
			vi.push_back(it->second);

			_mci2.emplace(make_pair(it->first, vi));
		}

		for (umm::iterator it = mci1.begin(); it != mci1.end(); it++)
		{
			vector<int> vi;

			if (_mci2.find(it->first) == _mci2.end())
			{
				vi.push_back(it->second);
				_mci2.emplace(make_pair(it->first, vi));
			}

			else _mci2.find(it->first)->second.push_back(it->second);
		}

		return _mci2;
	}
}

int moves(string s1, string s2)
{
	umm mci1 = gen_rep(s1);
	umm mci2 = gen_rep(s2);

	unordered_multimap<char, vector<int>> mcvi = separate(mci1, mci2);

	int count = 0;
	for (unordered_multimap<char, vector<int>>::iterator it = mcvi.begin(); it != mcvi.end(); it++)
	{
		if (it->second.size() == 1) count += 2;

		else
		{
			for (int i = 0; i < 2; i++)
			{
				int x = abs(it->second.at(0) - it->second.at(1));
				count += x;
			}
		}

		cout << "count: " << count << endl;
	}

	return count;
}

int main()
{
	string a, b;
	cin >> a >> b;

	cout << moves(a, b) << endl;
	system("pause");
	return 0;
}
*/