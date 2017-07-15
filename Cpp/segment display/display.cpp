#include <Windows.h> //for sleep
#include <iostream> //for cout
#include <vector> //to store each line of output file into 
#include "rlutil.h" //changes colors to my specifications
#include <map> //to pair the set of binary values with the set of outputs from truth table
#include <string> //stored in vector
#include <fstream> //read file

using namespace std;

#define SLEEPTIME 1000 //amount of time passed to sleep

class display
{
private:
	map<int, string> m;
	vector<string> vas;
	
public:
	map<int, string> getmap() { return m; }
	vector<string> getvector() { return vas; }

	void populate();
	void printm();

	long to_bin(long);
	void segments();
};

/*
TASK: given a number x, convert it to binary
ARGUMENTS: long x
RETURN: long binary_representation
*/
long display::to_bin(long x)
{
	if (x < 0) return -1;
	else
	{
		int dignum = log2(x);
		int newnum = 0;

		while (dignum >= 0)
		{
			if (x - pow(2, dignum) > 0)
			{
				newnum += pow(10, dignum);
				x -= pow(2, dignum);
			}

			else if (x - pow(2, dignum) == 0)
			{
				newnum += pow(10, dignum);
				break;
			}

			dignum--;
		}

		return newnum;
	}
}

/* 
TASK: populate the map and vector defined in the class
		- vector
			- read a file containing the output part of the truth table
			- push_back each line as a string into the vector
		- map
			- set key as the binary values for the numbers 0-127
			- set the value as the value of the corresponding element of the vector
ARGUMENTS: none
RETURN: void

*/
void display::populate()
{
	vector<string> ivs;
	vector<string> vs;

	ifstream f("16seg.txt");
	string line;
	
	while (getline(f, line))
		ivs.push_back(line);

	for (int i = 0; i < 128; i++)
	{
		string s;
		s += ivs.at(i).at(0); s += ivs.at(i).at(1); s += ivs.at(i).at(7); s += ivs.at(i).at(10);
		s += ivs.at(i).at(11); s += ivs.at(i).at(12); s += ivs.at(i).at(2); s += ivs.at(i).at(8);
		s += ivs.at(i).at(9); s += ivs.at(i).at(6); s += ivs.at(i).at(15); s += ivs.at(i).at(14);
		s += ivs.at(i).at(13); s += ivs.at(i).at(3); s += ivs.at(i).at(5); s += ivs.at(i).at(4);

		vs.push_back(s);
	}
	
	for (int i = 0; i < 128; i++)
		m.insert(make_pair(to_bin(i), vs.at(i)));

	string a1 = "   -   "; //A1 0
	string a2 = "-"; //A2 1

	string a3 = " | "; //E 6
	string a4 = "\\ "; //H 10
	string a5 = "| "; //J 11
	string a6 = "/ "; //K 12
	string a7 = "| "; //B 2

	string a8 = "   -   "; //G1 8
	string a9 = "-"; //G2 9

	string a10 = " | "; //F 7
	string a11 = "/ "; //N 13
	string a12 = "| "; //M 14
	string a13 = "\\ "; //L 15
	string a14 = "| "; //C 3

	string a15 = "   -   "; //D1 5
	string a16 = "-"; //D2 4

	vas.push_back(a1); vas.push_back(a2); vas.push_back(a3); vas.push_back(a4);
	vas.push_back(a5); vas.push_back(a6); vas.push_back(a7); vas.push_back(a8);
	vas.push_back(a9); vas.push_back(a10); vas.push_back(a11); vas.push_back(a12);
	vas.push_back(a13); vas.push_back(a14); vas.push_back(a15); vas.push_back(a16);
}

/*
TASK: for each of the 128 minterms of the truth table, print out the appropriate segments that make up the character
ARGUMENTS: none
RETURN: void
*/
void display::segments()
{
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (m.at(to_bin(i)).at(j) == '0')
			{
				rlutil::setColor(rlutil::RED);

				if (j != 1 && j != 6 && j != 8 && j != 13)
					cout << vas.at(j);

				else				
					cout << vas.at(j) << endl;
			}

			else
			{
				rlutil::setColor(rlutil::BLACK);
				if (j != 1 && j != 6 && j != 8 && j != 13)
					cout << vas.at(j);

				else
					cout << vas.at(j) << endl;
			}
		}

		Sleep(SLEEPTIME);
		system("cls");
	}

	
}

/*
TASK: print "[key] [value]" for map defined in class
ARGUMENTS: none
RETURN: void
*/
void display::printm()
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
		cout << it->first << " " << it->second << endl;
}

int main()
{
	display d;
	d.populate();
	
	d.segments();

	system("pause");
	return 0;
}
