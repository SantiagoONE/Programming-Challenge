/*

  La secuencia saltarina es aquella secuencia de N números enteros tales que:
  
  - Las diferencias absolutas entre cada elemento y su predecesor (xi - xi-1) toman
  todos los posibles valores entre 1 y N-1
  
  OJO:
  
    Diferecia absoluta entre cada elemento y su predecesor -> abs(x1 - x0) | abs(x2 - x1) | ...
    Se tiene que comprobar de alguna forma que TODOS los valores entre 1 y n-1 han 
    aparecido.
    
 */

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
    short n, i;
    int arr[3001];
    set<int> dis;
    while(cin >> n)
    {
    	dis.clear();
    	for (i = 0; i < n; ++i)
    		cin >> arr[i];
    	for (i = 1; i < n; ++i){
    		short t = abs(arr[i] - arr[i - 1]);
    		if(!t or t >= n)
    			break;
    		dis.insert(t);
    	}
    	cout << ((dis.size() == (unsigned) n - 1)? "Jolly" : "Not jolly") << '\n';
    }
    return 0;
}
