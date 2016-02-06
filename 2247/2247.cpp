/*
  2247 - Prime Digital Roots 
  ACM-ICPC Live Archive
*/

#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

bool primes[MAXN];

void criba()
{
	memset(primes, true, sizeof(primes));
	primes[0] = primes[1] = false;
	for(int i = 2; i < MAXN; ++i)
	{
		if(primes[i])		
			for(int j = 2*i; j < MAXN; j += i)			
				primes[j] = false;
	}
}

int adds(int n)
{
	int r = 0;
	while(n)
	{
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main()
{
	int n;
	criba();
	while(cin >> n and n != 0)
	{
		int aux = n;
		while(primes[n] == false)
		{
			n = adds(n); 
			if(n % 10 == n)
				break;
		}
		cout << setw(7) << aux << ' ' << setw(7);
		if(primes[n])
			cout << n;
		else
			cout << "none";
		cout << endl;
	}
	return 0;
}
