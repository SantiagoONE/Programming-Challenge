/*
  2120 - The Spiral of Primes
  ACM-ICPC Live Archive
*/
#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__
#define LIM 10000
#define MAXPRIMES 1129

using namespace std;

bool isprime[LIM];
int primes[MAXPRIMES];
typedef pair<int, int> Coord;

void criba()
{
	int i, j;
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for(i = 2; i < LIM; ++i)
	{
		if(isprime[i])		
			for(j = 2*i; j < LIM; j += i)			
				isprime[j] = false;
	}	
	for(i = 2, j = 0; i < LIM; ++i)
		if(isprime[i])
			primes[j++] = i;
}

int main()
{
    #ifdef __test__
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif 
    #ifdef __unlinkcout__
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    #endif

	bool primero = true;
	int x, y, cs = 1;
	short lado, anillo, r, count;
	Coord a, b, c, d, objetivo;
	criba();	
	while(cin >> x)	
	{
		if(x == -999)
			break;
		cin >> y;
		if(x == 0 and y == 0) r = 0;
		else
		{			
			anillo = max(abs(x), abs(y));			
			lado = 2 * anillo + 1;
			count = 0;			
			
			objetivo = make_pair(x, y);
			a = make_pair(anillo, 1 - anillo);
			b = make_pair(anillo - 1, a.second + (lado - 2)); 
			c = make_pair(b.first - (lado - 2), b.second - 1); 
			d = make_pair(c.first + 1, c.second - (lado - 2));	
											
			if(x == anillo and y != d.second) //derecha
				count = abs(y - a.second);
			else if(y == anillo) //arriba			
				count = abs(b.first - x) + (lado - 1);		
			else if(-x == anillo ) //izquierda			
				count = abs(c.second - y) + (lado - 1) * 2;						
			else //abajo			
				count = abs(x - d.first) + (lado - 1) * 3;
			r = (4 * (anillo - 1) * anillo) + count + 1;
		}		
		if(!primero) cout << '\n';		
		cout << "Case " << cs++ << ": The prime at location (" << x << "," << y << ") is " << primes[r] << ".\n";
		primero = false;
	}	
	return 0;
}


