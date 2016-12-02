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

The input consists of an arbitrary number of test cases, where each test case represents
one day.
The first line of each case contains a positive integer s ≤ 100, representing the number
of scheduled appointments for that day. The next s lines contain the appointments
in the format time1 time2 appointment, where time1 represents the time which the
appointment starts and time2 the time it ends. All times will be in the hh:mm format;
the ending time will always be strictly after the starting time, and separated by a single
space.
All times will be greater than or equal to 10:00 and less than or equal to 18:00. Thus
your response must be in this interval as well; i.e., no nap can start before 10:00 and
last after 18:00.
The appointment can be any sequence of characters, but will always be on the same
line. You can assume that no line is be longer than 255 characters, that 10 ≤ hh ≤ 18
and that 0 ≤ mm < 60. You cannot assume, however, that the input will be in any
specific order, and must read the input until you reach the end of file.


For each test case, you must print the following line:
Day #d: the longest nap starts at hh : mm and will last for [H hours and] M minutes.
where d stands for the number of the test case (starting from 1) and hh : mm is the
time when the nap can start. To display the length of the nap, follow these rules:
1. If the total time X is less than 60 minutes, just print “X minutes.”
2. If the total duration X is at least 60 minutes, print “H hours and M minutes,”
where
H = X ÷ 60 (integer division, of course) and M = X mod 60.
You don’t have to worry about correct pluralization; i.e., you must print “1 minutes”
or “1 hours” if that is the case.
The duration of the nap is calculated by the difference between the ending time and
the beginning time. That is, if an appointment ends at 14:00 and the next one starts
at 14:47, then you have 14:47 – 14:00 = 47 minutes of possible napping.
If there is more than one longest nap with the same duration, print the earliest one.
You can assume the professor won’t be busy all day, so there is always time for at least
one possible nap.
*/


#define MIN 600 //in mins
#define MAX 1080 //in mins

class prof_nap
{
public:
	vector<string> parse(string); 
	int stringint_to_int(string); 
	string min_arithmetic(int);

	vector<pair<string, string>> input();
	vector<pair<int, int>> transform_input_to_mins(vector<pair<string, string>>);
	vector<pair<string, int>> time_differences(vector<pair<int, int>>);

	string output(vector<pair<string, int>>);
};

/*
TASK: split string up by whitespaces, and store each piece into a vector
ARGUMENTS: string
RETURN: vector<string>
*/
vector<string> prof_nap::parse(string s)
{
	istringstream iss(s);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(tokens));

	return tokens;
}

/*
TASK: transform a string made up of integers into an integer
ARGUMENTS: string
RETURN: int
*/
int prof_nap::stringint_to_int(string x)
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
TASK: take an integer number of minutes and transform it into a string saying x hours : y mins
ARGUMENTS: int
RETURN: string
*/
string prof_nap::min_arithmetic(int i)
{
	int hours = i / 60;
	int mins = i % 60;

	string s = hours + " hours and " + mins; s += " minutes.";

	if (hours == 0) return mins + " minutes.";
	else			return s;
}

/*
TASK: create input that resembles sample input, tokenize the input, and get a vector with pairs of start/stop times
ARGUMENTS: NONE
RETURN: vector<pair<string, string>>
*/
vector<pair<string, string>> prof_nap::input()
{
	vector<string> schedule;
	vector<pair<string, string>> times;

	int how_many;
	cin >> how_many;

	while (true)
	{
		cin.ignore();
		for (int i = 0; i < how_many; i++)
		{
			string k;
			getline(cin, k);
			schedule.push_back(k);
		}

		schedule.push_back("blank");
		cin >> how_many;

		if (how_many == 0) break;
	}


	for (int i = 0; i < schedule.size(); i++)
	{
		if (schedule.at(i) != "blank")
		{
			vector<string> tokenized = parse(schedule.at(i));
			times.push_back(make_pair(tokenized.at(0), tokenized.at(1)));
		}

		else
			times.push_back(make_pair("blank", "blank"));
	}

	return times;
}

/*
TASK: given the start/stop time pairs, transform their string versions to integers in minutes
ARGUMENTS: vector<pair<string, string>>
RETURN: vector<pair<int, int>>
*/
vector<pair<int, int>> prof_nap::transform_input_to_mins(vector<pair<string, string>> vpss)
{
	vector<pair<int, int>> times;
	
	for (int i = 0; i < vpss.size(); i++)
	{
		if (vpss.at(i).first != "blank")
		{
			string hours1, mins1, hours2, mins2;
			int hours_i1, mins_i1, hours_i2, mins_i2;

			for (int j = 0; j < vpss.at(i).first.size(); j++)
			{
				if (vpss.at(i).first.at(j) != ':')		hours1.push_back(vpss.at(i).first.at(j));
				else if (vpss.at(i).first.at(j) == ':') continue;
				else									mins1.push_back(vpss.at(i).first.at(j));
			}

			hours_i1 = stringint_to_int(hours1) * 60;
			mins_i1 = stringint_to_int(mins1);

			for (int j = 0; j < vpss.at(i).second.size(); j++)
			{
				if (vpss.at(i).second.at(j) != ':')		 hours2.push_back(vpss.at(i).second.at(j));
				else if (vpss.at(i).second.at(j) == ':') continue;
				else									 mins2.push_back(vpss.at(i).second.at(j));
			}

			hours_i2 = stringint_to_int(hours2) * 60;
			mins_i2 = stringint_to_int(mins2);

			times.push_back(make_pair(hours_i1 + mins_i1, hours_i2 + mins_i2));
		}

		else
			times.push_back(make_pair(-1, -1));
	}


	return times;
}

/*
TASK: calculate the time differences between the stop time of an item and start time, and pair it with the (day # and stop time)
ARGUMENTS: vector<pair<int, int>>
RETURN: vector<pair<string, int>>
*/
vector<pair<string, int>> prof_nap::time_differences(vector<pair<int, int>> vpii)
{
	vector<pair<string, int>> timesort;
	int day = 1;

	vector<pair<int, int>> vpii_new;

	vpii_new.push_back(make_pair(MIN, MIN));
	for (int i = 0; i < vpii.size(); i++)
	{
		if (vpii.at(i).first != -1)
			vpii_new.push_back(vpii.at(i));
		else
		{
			vpii_new.push_back(make_pair(MAX, MAX));
			vpii_new.push_back(make_pair(-1, -1));
		}
	}


	for (int i = 1; i < vpii_new.size(); i++)
	{
		if (vpii_new.at(i).first != -1)
		{
			string s = "day #" + day; s += " " + vpii_new.at(i - 1).second;
			timesort.push_back(make_pair(s, vpii_new.at(i).first - vpii_new.at(i - 1).second));
		}

		else if (vpii_new.at(i).first == -1)
			day++;
	}
	

	return timesort;
}

/*
lambda function passed to the vector::sort() function, in order to compare the pairs passed to prof_nap::output()
*/
auto compare = [](const pair<string, int>& a, const pair<string, int>& b)
{
	return (a.second > b.second);
};

/*
TASK: create the necessary output for the program (output follows the form of the sample outputs given in problem)
ARGUMENTS: vector<pair<string, int>>
RETURN: string
*/
string prof_nap::output(vector<pair<string, int>> vpsi)
{
	sort(vpsi.begin(), vpsi.end(), compare);

	vector<string> token = parse(vpsi.at(0).first);
	
	string s = token.at(0) + token.at(1) + ": ";
	s += "the longest nap starts at " + token.at(2) + " and will last for " + min_arithmetic(vpsi.at(0).second);

	return s;
}

/*int main()
{
	prof_nap pn;
	cout << pn.output(pn.time_differences(pn.transform_input_to_mins(pn.input))) << endl;

	system("pause");
	return 0;
}*/