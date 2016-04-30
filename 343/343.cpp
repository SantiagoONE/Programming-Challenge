#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

typedef unsigned long long ull;

const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int minBase(const string &n)
{
	auto mx = max_element(n.begin(), n.end());
	return (*mx > '9')? *mx - 'A' + 11 : *mx - '0' + 1 + (*mx == '0');
}

ull toTen(const string &n, short base)
{
	short len = n.size();
	ull r = 0;
	for (int i = 0; i < len; ++i)
	{
		int dd = digits.find(n[i]) * pow(base, len - i - 1);
		r += dd;			
	}
	return r;
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
        #define endl '\n'
    #endif
    
    string a, b;    
    short base_a, base_b, i, j;
    bool goal;

    while(cin >> a >> b)
    {
    	goal = false;
        base_a = minBase(a);
        base_b = minBase(b);
        for(i = base_a; !goal and i <= 36; ++i)
        	for(j = base_b; !goal and j <= 36; ++j)        	
        		if(toTen(a, i) == toTen(b, j))
	        		goal = true;        	
        if(goal)
        	cout << a << " (base " << i - 1 << ") = " << b << " (base " << j - 1 << ")" << endl;
        else
        	cout << a << " is not equal to " << b << " in any base 2..36" << endl;
    }

    return 0;
}

