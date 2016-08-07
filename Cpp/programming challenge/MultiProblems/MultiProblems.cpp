#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printvector(vector<int> path)
{
	for (int i = 0; i < path.size(); i++) { cout << path[i] << " "; }
	cout << endl;
}

/*
@BEGIN_SOURCE_CODE
program is a solution to the 3n + 1 problem:
	start at int n
	if n is even, then divide by 2
	if n is odd, multiply by 3 and add 1
	it's conjectured that at least to 1000000 that the program terminates at n = 1
		the program takes 2 inputs (start and endpoint) and 
		returns the maximum length of a cycle for n between 
		and including those endpoints
*/

vector<int> generate_sequence(int start_num) //generates sequence mentioned above
{
	int t = start_num; //avoid changing the given parameter
	vector<int> holder; //holds the numbers generated in the sequence
	holder.push_back(t); 

	while (t != 1) //terminate at t = 1
	{
		if (t % 2 == 0) //even case
		{ 
			t /= 2; 
			holder.push_back(t);
		}
		else //odd case
		{ 
			t = 3 * t + 1; 
			holder.push_back(t);
		}
	}

	return holder;
}

int max_cycle(int start, int end)
{
	int max = 0;

	for (int i = start; i <= end; i++)
	{
		if (generate_sequence(i).size() > max) { max = generate_sequence(i).size(); }
	}

	return max;
}

/*@END_SOURCE_CODE*/

/*
@BEGIN_SOURCE_CODE
program prints the representation of a minesweeper board
	if mine, print *
	else, print the number of mines near the square
		near means all directions (n, s, e, w, ne, nw, se, sw) 
		by 1 unit
*/

class direction
{
public:
	char arr[100][100] = {}; //minesweeper board
	char left(int, int); //returns character to the left
	char right(int, int); //returns character to the right
	char up(int, int); //returns character above
	char down(int, int); //returns character below
	char dl(int, int); //return character to the down+left
	char dr(int, int); //returns character to the down+right
	char ul(int, int); //returns character to the up+left
	char ur(int, int); //returns character to the up+right
};

char direction::left(int i, int j) { return arr[i][j - 1]; }
char direction::right(int i, int j) { return arr[i][j + 1]; }
char direction::up(int i, int j) { return arr[i - 1][j]; }
char direction::down(int i, int j) { return arr[i + 1][j]; }
char direction::dl(int i, int j) { return arr[i + 1][j - 1]; }
char direction::dr(int i, int j) { return arr[i + 1][j + 1]; }
char direction::ul(int i, int j) { return arr[i - 1][j - 1]; }
char direction::ur(int i, int j) { return arr[i - 1][j + 1]; }

void representation(int x, int y)
{
	direction d;
	int rep_arr[100][100] = {0}; //array that is the representation of the minesweeper board

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> d.arr[i][j]; //minesweeper board
		}
	}

	/*
	casework for a couple cases: 
	first row, middle rows, and last row
	last row essentially the same conditions as first row but inverted (instead of down, go up, etc)
	middle row contains more cases
	each row has a first element, middle elements, and last element
	casework on each of these three types of elements	
	*/
	int t1 = clock();

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					if (d.arr[i][j] == '.' && d.right(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.down(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dr(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}

				else if (j == y - 1)
				{
					if (d.arr[i][j] == '.' && d.left(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.down(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dl(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}

				else if (j > 0 && j < y - 1)
				{
					if (d.arr[i][j] == '.' && d.right(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.left(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.down(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dr(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dl(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}
			}

			else if (i > 0 && i < x - 1)
			{
				if (j == 0)
				{
					if (d.arr[i][j] == '.' && d.right(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.up(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.down(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dr(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ur(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}

				else if (j == y - 1)
				{
					if (d.arr[i][j] == '.' && d.left(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.up(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.down(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dl(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ul(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}

				else if (j > 0 && j < y - 1)
				{
					if (d.arr[i][j] == '.' && d.right(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.left(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.down(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dr(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.dl(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.up(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ur(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ul(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}
			}

			else if (i == x - 1)
			{
				if (j == 0)
				{
					if (d.arr[i][j] == '.' && d.right(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.up(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ur(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}

				else if (j == y - 1)
				{
					if (d.arr[i][j] == '.' && d.left(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.up(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ul(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}

				else if (j > 0 && j < y - 1)
				{
					if (d.arr[i][j] == '.' && d.right(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.left(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.up(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ur(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '.' && d.ul(i, j) == '*') { rep_arr[i][j] += 1; }
					if (d.arr[i][j] == '*') { rep_arr[i][j] = -1; }
				}
			}

			
		}
	}

	/*print the final representation*/
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (rep_arr[i][j] == -1) { cout << "* "; }
			else					 { cout << rep_arr[i][j] << " "; }
		}
		cout << endl;
	}
	cout << endl;

	int t2 = clock();

	cout << endl << (t2 - t1) / double(CLOCKS_PER_SEC) << endl;
}

/*@END_SOURCE_CODE*/

/*
@BEGIN_SOURCE_CODE
chess: check if king is in check
	white: lowercase
	black: uppercase
*/

class board_pieces
{
public:
	char board[8][8];
	vector<char> rook(int, int); //returns all positions that rook can move to
	vector<char> pawn(int, int); //returns all positions that pawn can move to
	vector<char> queen(int, int); //returns all positions that queen can move to
	vector<char> bishop(int, int); //returns all positions that bishop can move to
	vector<char> knight(int, int); //returns all positions that knight can move to
	vector<char> king(int, int); //returns all positions that king can move to
};

vector<char> board_pieces::rook(int x, int y)
{
	vector<char> positions; //holds the positions that the rook can move to
	for (int i = 0; i < 8; i++) 
	{
		if (i != x) { positions.push_back(board[i][y]); }
	}

	for (int j = 0; j < 8; j++)
	{
		if (j != y) { positions.push_back(board[x][j]); }
	}

	return positions;
}
vector<char> board_pieces::pawn(int x, int y)
{
	vector<char> positions;
	
	positions.push_back(board[x + 1][y - 1]);
	positions.push_back(board[x + 1][y + 1]);

	return positions;
}
vector<char> board_pieces::bishop(int x, int y)
{
	vector<char> positions;
	int a = x - 1;
	int b = y - 1;

	int c = x + 1;
	int d = y + 1;

	while (a >= 0 && b >= 0)
	{
		positions.push_back(board[a][b]);
		a--;
		b--;
	}

	while (a >= 0 && d < 8)
	{
		positions.push_back(board[a][d]);
		a--;
		d++;
	}

	while (c < 8 && b >= 0)
	{
		positions.push_back(board[c][b]);
		c++;
		b--;
	}

	while (c < 8 && d < 8)
	{
		positions.push_back(board[c][d]);
		c++;
		d++;
	}

	return positions;

}
vector<char> board_pieces::queen(int x, int y)
{
	vector<char> positions;

	for (int i = 0; i < rook(x, y).size(); i++) { positions.push_back(rook(x, y)[i]); }
	for (int j = 0; j < bishop(x, y).size(); j++) { positions.push_back(bishop(x, y)[j]); }

	return positions;
}


/*@END_SOURCE_CODE*/

int main()
{
	board_pieces b;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> b.board[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < b.queen(4, 3).size(); k++)
			{
				if (b.queen(4,3)[k] == b.board[i][j]) { b.board[i][j] = '*'; }
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << b.board[i][j] << " "
				;
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}