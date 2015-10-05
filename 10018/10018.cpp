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

typedef unsigned int usint;

usint revert(usint n)
{
    usint result = 0;
    while(n)
    {
    	result = result * 10 + n % 10;
    	n /= 10;
    }
    return result;
}

bool isPalindrome(usint n)
{
    usint rn = revert(n);
    while(n)
    {
    	if((n % 10 - rn % 10) != 0)
    		return false;
    	n /= 10;
    	rn /= 10;
    }
    return true;
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
    usint k, n, acum, test;
    cin >> k;
    while(k--)
    {
        cin >> n;
        acum = 0;
        while(true)
        {		
            test = n + revert(n);
            acum++;
            if(isPalindrome(test))
               break;			
            n = test;		
        }
        cout << acum << ' ' << test << '\n';
    }
    return 0;    
}
