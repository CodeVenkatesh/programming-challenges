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

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <typeinfo>
#include <unordered_map>

using namespace std;

/*
TASK: determine if the specified data is within a unordered_multimap<T, C>
ARGUMENTS: W, vector<T>
RETURN: bool
*/

template<typename W, typename T, typename C>

bool exists(W check, vector<pair<T, C>> vt)
{
	if (!(typeid(W) == typeid(T) || typeid(W) == typeid(C)) return false;

	else
	{
		for (vector<T>::iterator it = vt.begin(); it != vt.end(); it++)
			if (it->first == check) return true;

		return false;
	}
}

/*
TASK: generate a representation like the one described above
ARGUMENTS: string
RETURN: vector<int>
*/

umm gen_rep(string s)
{
umm mci;

int count = 0;
for (string::iterator it = s.begin(); it != s.end(); it++)
mci.emplace(make_pair(*it, 1));

return mci;
}


