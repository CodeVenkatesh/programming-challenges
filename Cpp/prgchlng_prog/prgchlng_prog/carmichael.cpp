#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

class carmichael
{
public:
	bool is_prime(int);
	bool passes_fermat(int);
	bool is_carmichael(int);
};

bool carmichael::is_prime(int x)
{
	int count = 0;
	for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) count++;
	
	return(count == 0);
}

bool carmichael::passes_fermat(int n)
{
	int count = 0;
	for (int i = 2; i < n; i++)
	{
		int x = pow(i, n);
		if ((is_prime(n)) && (x % n == i)) count++;
	}

	int primes = 0;
	for (int i = 2; i < n; i++) if (is_prime(n)) primes++;

	return (count == primes && n != 1);
}

bool carmichael::is_carmichael(int x)
{
	return (!(is_prime(x)) && passes_fermat(x));
}

/*
int main()
{
	carmichael c;
	
	int x;
	cin >> x;

	while (x != 0)
	{
		if (c.is_carmichael(x)) cout << x << " is carmichael" << endl;
		else					cout << x << " is normal" << endl;

		cin >> x;
	}
}*/