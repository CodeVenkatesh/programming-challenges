/*
PROBLEM:
	given directory paths that are existing and paths that you want to add
		ex/ "/home/gcj/finals"

	find the total number of "mkdir" commands you need to add all of the directories that you wanted to add

METHOD:
	generate tree(s)
		for example, we're given "/home", and we want to add "/home/gcj/finals" and "/home/gcj/quals"
		tree out of what we want to add:
										 home
										 /  \ 
								( parent )  < gcj >
									          / \
									 ( parent )  < finals, quals >
												   / \      / \   
										( parent )   < >   /   \
										                  /     \
												  ( parent )    < >
		
		existing = [["home"]], and to_add = [["home", "gcj", "finals"], ["home", "gcj", "quals"]]
		see if stuff exists in that order, and when one specific one doesn't exist, total_mkdir++

		so, what happens:
			home exists
			gcj doesn't exist --> total_mkdir = 1, existing = [["home"], ["home", "gcj"]]
			finals doesn't exist --> total_mkdir = 2, existing = [["home"], ["home", "gcj"], ["home", "gcj", "finals"]]
			quals doesn't exist --> total_mkdir = 3, existing = [["home"], ["home", "gcj"], ["home", "gcj", "finals"], ...]

		if there's a different root, add it to a separate vector, and do the same thing except with that as the root

		return total_mkdir
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "tree.h"

using namespace std;

/*
class for file_fix_it program

private variables:
	existing (vector<vector<string>>)

private methods:
	none

public variables:
	to_add (vector<vector<string>>)
	total_mkdir (int)

public methods:
	init: 
		TASK: tokenize path name by the delimiter '/'
		ARGUMENTS: string (path name)
		RETURN: vector<string> (with first element deleted because /asdf/as/ad --> ["", "asdf", "as", "ad"]

	find_f:
		TASK: populate existing and to_add like described above
		ARGUMENTS: NONE
		RETURN: void

	tokenize_path:
		TASK: see if a string is in a vector<vector<string>>
		ARGUMENTS: vector<vector<string>>, int, int, string
		RETURN: bool

	tree_count:
		TASK: count the number of mkdir's needed
		ARGUMENTS: vector<vector<string>>
		RETURN: void

*/

class file_fix_it
{
private:
	vector<vector<string>> existing;

public:
	vector<vector<string>> to_add;
	int total_mkdir = 0;

	void init();
	bool find_f(vector<vector<string>>, int, int, string);

	vector<string> tokenize_path(string);
	void tree_count(vector<vector<string>>);
};

vector<string> file_fix_it::tokenize_path(string s)
{
	vector<string> vs;
	istringstream iss(s);
	string token;

	while (getline(iss, token, '/'))
		vs.push_back(token);

	if (vs.size() > 0)
		vs.erase(vs.begin());

	return vs;
}

void file_fix_it::init()
{
	int exists, add;
	cin >> exists >> add;

	for (int i = 0; i < exists; i++)
	{
		string s;
		cin >> s;

		vector<string> vs = tokenize_path(s);
		existing.push_back(vs);
	}

	for (int i = 0; i < add; i++)
	{
		string s;
		cin >> s;

		vector<string> vs = tokenize_path(s);
		to_add.push_back(vs);
	}
}

bool file_fix_it::find_f(vector<vector<string>> vvs, int start, int end, string str)
{
	for (int i = start; i < end; i++)
		if (find(vvs.at(i).begin(), vvs.at(i).end(), str) != vvs.at(i).end())
			return true;

	return false;
}

void file_fix_it::tree_count(vector<vector<string>> vvs)
{
	vector<vector<string>> remaining;

	string root_directory = vvs.at(0).at(0);
	tree<string> ts(root_directory);
	
	for (int i = 0; i < vvs.size(); i++)
	{
		if (vvs.at(i).at(0) == root_directory)
		{
			ts.insert(vvs.at(i).at(1));

			for (int j = 2; j < vvs.at(i).size(); j++)
			{
				node<string>* n = ts.search(vvs.at(i).at(j - 1));
				node<string>* ns = new node<string>(vvs.at(i).at(j), n);

				ts.insert(ns);
			}
		}

		else
		{
			vector<string> inside = vvs.at(i);
			remaining.push_back(inside);
			break;
		}
	}

	if (existing.size() > 0)
	{
		for (int i = 0; i < existing.size(); i++)
		{
			for (int j = 0; j < ts.size(); j++)
			{
				for (int k = 0; k < existing.at(i).size(); k++)
				{
					node<string>* ns = ts.search(existing.at(i).at(k));
					string str;
					if (ns != NULL)
						str = ns->data;

					if (find_f(existing, 0, existing.size(), str) == false)
					{
						total_mkdir++;
						vector<string> vs;
						while (ns != NULL)
						{
							vs.push_back(ns->data);
							ns = ns->parent;
						}

						reverse(vs.begin(), vs.end());

						existing.push_back(vs);
					}
				}
			}
		}
	}

	else
	{
		total_mkdir = ts.count_nodes();
	}

	while (remaining.size() > 0)
		tree_count(remaining);
}

int main()
{
	file_fix_it ffi;

	ffi.init();
	ffi.tree_count(ffi.to_add);

	cout << ffi.total_mkdir << endl;
	
	system("pause");
	return 0;
}