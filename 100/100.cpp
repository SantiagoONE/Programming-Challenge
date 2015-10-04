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


int long_max(int n)
{
	int cont = 0;
	while((++cont) and n > 1)	
		n = (n & 1)? n*3 + 1 : n / 2;					
	return cont;
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
    
    int i, j, _max, a, b;
    while(cin >> i >> j) {    	
    	a = i;
    	b = j;
    	_max = 0;
    	if(i > j)    	
    		swap(i, j);    		    	       	
        while(i <= j)
        	_max = max(_max, long_max(i++));        	        
        cout << a << ' ' << b << ' ' << _max << '\n';
    }
    return 0;
}
