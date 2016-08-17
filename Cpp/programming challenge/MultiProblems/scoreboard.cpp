#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

/*

The task is to rank the contestants in the contest based on following criteria

Contestants are ranked first by the number of problems solved (the more the better)
then by decreasing amounts of penalty time
If two or more contestants are tied in both problems solved and penalty time, they are displayed in order of increasing team numbers.

Penalty time is computed as the number of minutes it took for the first correct submission for a problem to be received plus 20 minutes for each incorrect submission received prior to the correct solution.

The penalty time will be considered only if the problem is solved. There will not be any penalty if the problem is not solved even if the several Incorrect submissions were made. A problem is solved if any of the submissions for that problem is judged correct.

*/

struct board
{
	int contestant;
	int nproblem;
	int problem[10];
	int penalty[10];
	int time;
	board(int c): contestant(c), nproblem(0)
	{
		time = 0;
		for(int i = 0; i < 10; i++)
		{
			problem[i] = 0;
			penalty[i] = 0;
		}
	}
	void calc_time()
	{
		for(int i = 1; i < 10; i++)
		{
			if(problem[i] == 1) { time += penalty[i]; }
		}
	}
};

inline void init(int index[])
{
	for(int i = 0; i < 101; i++)
	{
		index[i] = -1;
	}
}

void judge(board &b, const int &problem, const int &time, const char &L)
{
	if(b.problem[problem] == 1) { return ; }
	if(L == 'C')
	{
		b.nproblem++;
		b.problem[problem] = 1;
		b.penalty[problem] += time;
	}
	else if (L == 'I')	{ b.penalty[problem] += 20; }
}

bool operator<(const board &b1, const board &b2)
{
	if(b1.nproblem > b2.nproblem) 														   { return true; }
	if(b1.nproblem == b2.nproblem && b1.time < b2.time) 								   { return true; }
	if(b1.nproblem == b2.nproblem && b1.time == b2.time && b1.contestant == b2.contestant) { return true; }

	return false;
}

int main()
{
	int T;
	string s;
	int contestant, problem, time;
	char L;

	cin >> T;
	getline(cin, s);
	getline(cin, s);

	for(int t = 1; t <= T; t++)
	{
		int index[101];
		fill(index, index + 101, -1);
		vector<board> v;

		while (getline(cin, s))
		{
			if(s == "") { break; }
			istringstream iss(s);
			iss >> contestant >> problem >> time >> L;

			if(index[contestant] == -1)
			{
				v.push_back(*new board(contestant));
				index[contestant] = (int) v.size() - 1;
			}

			judge(v[index[contestant]], problem, time, L)
		}

		for (vector<board>::iterator it = v.begin(); it != v.end(); it++) { it -> calc_time(); }

		sort(v.begin(), v.end());
		
		for (vector<board>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << it->contestant << " " << it->nproblem << " " << it->time << endl;		
		}

		if(t < T) { cout << endl; }
	}
}