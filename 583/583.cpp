#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__

using namespace std;

template <class T, class U> inline T max (T &a, U &b) {  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b) {  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a;  a = b; b = tmp; }

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

typedef long long ll;
typedef map<int, int> Dict;

Dict factorization(ll n)
{
    int c = 2;
    Dict res;		
    while(c <= sqrt(n) + 1)
    {
    	if(!(n % c))
    	{
            n /= c; 
            res[c]++;
    	}
    	else  
    	     c++;
    }
    if(n > 1)
     	res[n]++;
    return res;
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
    
    ll n;
    Dict factores;
    while(cin >> n and n)
    {		
        factores = factorization(abs(n));
        if(n < 0) 
        	factores[-1] = 1;
        
        //{ output
        cout << n << " = " << factores.begin() -> first;
        factores.begin() -> second--;
        for (Dict::iterator it = factores.begin(); it != factores.end(); it++)
        {
            int t = it -> second;
            while(t--)
              cout << " x " << it->first;
        }		
        cout << '\n';
        //}
    }
    return 0;
}
