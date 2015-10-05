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

struct Fraction{
    int n, d;
    
    Fraction(int _n, int _d): n(_n), d(_d) { }
    
    bool operator!=(Fraction x)
    {
    	return !(x.n == n and x.d == d);
    }
    
    bool operator>(Fraction x)
    {
    	int at_n = n * x.d;
    	int bt_n = x.n * d;
    	return at_n > bt_n;
    }
    
    Fraction operator+(Fraction x)
    {
    	return Fraction(n + x.n, d + x.d);
    }
};

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
    int n, d;	
    while(cin >> n >> d and !(n == 1 and d == 1))  
    {
    	Fraction _new = Fraction(n, d),
    	left = Fraction(0, 1),
    	father = Fraction(1, 1),
    	right = Fraction(1, 0);
    
    	while(_new != father)
    	{
            if(_new > father) // como es mayor va hacia la derecha
            {
            	left = father;
            	father = right + father;				
            	cout << 'R';				
            }
            else //como es menor va hacia la izquierda
            {
            	right = father;
            	father = left + father;				
            	cout << 'L';
            }
    	}
    	cout << '\n';
    }
    return 0;
}
