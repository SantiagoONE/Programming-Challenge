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

typedef unsigned long long ull;

ull fastmodexp(ull b, ull e, ull m)
{
    ull result = 1;
    while(e > 0)
    {
        if(e & 1)
         result = (b * result) % m;
        e >>= 1;
        b = ((b % m) * (b % m)) % m;
    }
    return result;
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
    ull b, e, m;
    while(cin >> b >> e >> m)
        cout << fastmodexp(b, e, m) << '\n';      
    return 0;
}
