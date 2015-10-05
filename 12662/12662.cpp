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
    short n, q, p, index_l, index_r;
	string L, R;
	bool left, right;
	vector<string> student(101);

	cin >> n;
	for (short i = 0; i < n; ++i)
		cin >> student[i];
	cin >> q;
	while(q--)			
	{
		cin >> p;
		p--;
		if(student[p] != "?") cout << student[p];
		else
		{
			left = right = false;
			index_l = index_r = p;	
			L = R = "";
			while(!left or !right)
			{				
				if(index_r + 1 < n and !right)
				{
					index_r++;
					if (student[index_r] != "?") 
						right = true;				
					R += "left of ";
				}  
				if(index_l - 1 >= 0 and !left)
				{
					index_l--;
					if (student[index_l] != "?") 
						left = true;
					L += "right of ";
				}				
				if(index_l == 0) 
					left = true;
				if(index_r == n - 1)
					right = true;
			}
			if ((p - index_l) == (index_r - p) and student[index_r]!="?" and student[index_l]!="?")
			{
				cout << "middle of " << student[index_l] << " and " << student[index_r];
			}
			else if ((p - index_l >= index_r - p and student[index_r]!="?") or !index_l)
			{
				cout << R << student[index_r];
			}
			else 
			{				
				cout << L << student[index_l];
			}			
		}
		cout << '\n';
	}		
	return 0;
}
