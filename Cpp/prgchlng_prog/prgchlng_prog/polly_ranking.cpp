#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

/*
PROBLEM STATEMENT:

Pretty Polly has no shortage of gentlemen suitors who come a’ courting. Indeed, her
biggest problem is keeping track of who the best ones are. She is smart enough to realize
that a program which ranks the men from most to least desirable would simplify her
life. She is also persuasive enough to have talked you into writing the program.
Polly really likes to dance, and has determined the optimal partner height is 180
centimeters tall. Her first criteria is finding someone who is as close as possible to this
height; whether they are a little taller or shorter doesn’t matter. Among all candidates
of the same height, she wants someone as close as possible to 75 kilograms without
going over. If all equal-height candidates are over this limit, she will take the lightest
of the bunch. If two or more people are identical by all these characteristics, sort them
by last name, then by first name if it is necessary to break the tie.
Polly is only interested in seeing the candidates ranked by name
*/

struct data
{
	int height;
	int weight;
};

class polly_ranking
{
public:
	void printv(vector<string>);
	bool is_digit(char);
	int stringint_to_int_pr(string);
	void printm(map<string, data>);

	vector<string> parse(string);

	vector<string> input();
	map<string, data> person(vector<string>);

	vector<string> ranking(map<string, data>);
};

/*
TASK: determine whether or not a character is a digit
ARGUMENTS: char
RETURN: bool
*/
bool polly_ranking::is_digit(char c)
{
	char dig[] = "1234567890";
	for (int i = 0; i < 10; i++)
		if (c == dig[i]) return true;

	return false;
}

/*
TASK: transform a string made up of integers into an integer
ARGUMENTS: string
RETURN: int
*/
int polly_ranking::stringint_to_int_pr(string x)
{
	int num = 0;
	for (int i = 0; i < x.size(); i++)
	{
		double j = pow(10, i);
		int a = x.at(x.length() - 1 - i) - 48;

		num += a * j;
	}

	return num;
}

/*
TASK: print the contents of a vector<string>
ARGUMENTS: vector<string>
RETURN: void
*/
void polly_ranking::printv(vector<string> path)
{
	for (int i = 0; i < path.size(); i++) cout << path[i] << endl;
	cout << endl;
}

/*
TASK: print the contents of a map<string, data>
ARGUMENTS: map<string, data>
RETURN: void
*/
void polly_ranking::printm(map<string, data> msd)
{
	for (map<string, data>::iterator it = msd.begin(); it != msd.end(); it++)
	{
		cout << it->first << " " << it->second.height << " " << it->second.weight << endl;
	}

	cout << endl;
}

/*
TASK: create input that resembles sample input
ARGUMENTS: NONE
RETURN: vector<string>
*/
vector<string> polly_ranking::input()
{
	vector<string> storage;

	string a; getline(cin, a); storage.push_back(a);
	string b; getline(cin, b); storage.push_back(b);

	while (storage.at(storage.size() - 1) != "" && storage.at(storage.size() - 2) != "")
	{
		string x; 
		getline(cin, x); 
		storage.push_back(x);
	}

	storage.erase(storage.end() - 1);
	return storage;
}

/*
TASK: split string up by whitespaces, and store each piece into a vector
ARGUMENTS: string
RETURN: vector<string>
*/
vector<string> polly_ranking::parse(string s)
{
	istringstream iss(s);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(tokens));

	return tokens;
}

/*
TASK: create a map of all people entered
ARGUMENTS: vector<string>
RETURN: map<string, data>
*/
map<string, data> polly_ranking::person(vector<string> vs)
{
	map<string, data> msd;
	
	for (int i = 0; i < vs.size(); i++)
	{
		data d;
		vector<string> tokens = parse(vs.at(i));

		string name = tokens.at(0) + " " + tokens.at(1);
		d.height = stringint_to_int_pr(tokens.at(2));
		d.weight = stringint_to_int_pr(tokens.at(3));

		msd.insert(pair<string, data>(name, d));
	}
	
	return msd;
}

/*
lambda function passed to the vector::sort() function, in order to compare the pairs passed to polly_ranking::ranking()
*/
auto compare_pr = [](const pair<string, data>& a, const pair<string, data>& b)
{
	if (abs(a.second.height - 180) < abs(b.second.height - 180))
	{
		if (abs(a.second.weight - 75) < abs(b.second.weight - 75))
		{
			return a.first.at(a.first.find(" ") + 1) < b.first.at(b.first.find(" ") + 1);
		}
		else return abs(a.second.weight - 75) < abs(b.second.weight - 75);
	}
	else return abs(a.second.height - 180) < abs(b.second.height - 180);
};

/*
TASK: rank the problem in the fashion described by the problem
ARGUMENTS: map<string, data>
RETURN: vector<string>
*/
vector<string> polly_ranking::ranking(map<string, data> msd)
{
	vector<pair<string, data>> items;
	copy(msd.begin(), msd.end(), back_inserter(items));
	sort(items.begin(), items.end(), compare_pr);

	vector<string> vs;
	for (vector<pair<string, data>>::iterator it = items.begin(); it != items.end(); it++)
		vs.push_back(it->first);

	return vs;
}

/*int main()
{
	polly_ranking pr;
	
	map<string, data> msd = pr.person(pr.input());
	pr.printv(pr.ranking(msd));

	system("pause");
	return 0;
}*/