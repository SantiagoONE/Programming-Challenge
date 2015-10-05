#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__

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

void to_roman(short n, short &i, short &v, short &x, short &l, short &c)
{
    if(n >= 100){
    	c++;	
    	to_roman(n - 100, i, v, x, l, c);		
    } 
    else if(n >= 90){
    	c++;
    	x++;
    	to_roman(n - 90, i, v, x, l, c);
    } 
    else if(n >= 50){
    	l++;
    	to_roman(n - 50, i, v, x, l, c);
    }	
    else if(n >= 40){
    	x++;
    	l++;
    	to_roman(n - 40, i, v, x, l, c);
    }	
    else if(n >= 10){
    	x++;
    	to_roman(n - 10, i, v, x, l, c);
    }
    else if(n >= 9){
    	i++;
    	x++;
    	to_roman(n - 9, i, v, x, l, c);
    }
    else if(n >= 5){
    	v++;
    	to_roman(n - 5, i, v, x, l, c);
    }	
    else if(n >= 4){
    	i++;
    	v++;
    	to_roman(n - 4, i, v, x, l, c);
    }
    else if(n >= 1){
    	i++;
    	to_roman(n - 1, i, v, x, l, c);
    } 
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
    short N, i, v, x, l, c;
    while(cin>>N and N)	
    {		
    	i = v = x = l = c = 0;
    	for (short it = 1; it <= N; ++it)	
    		to_roman(it, i, v, x, l, c);		
    	printf("%d: %d i, %d v, %d x, %d l, %d c\n", N, i, v, x, l, c);		
    }
    return 0;
}
