#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
const int dx[]={1,1,0,-1,-1,-1,0,1}; 
const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

string Table[26];
int N, M;

int bt(int f, int c)
{
	int r = 1;
	Table[f][c] = '0';	
	for (int i = 0; i < 8; ++i)
	{
		int nf = f + dx[i];
		int nc = c + dy[i];
		if((nf >= 0 and nf < N) and (nc >= 0 and nc < M) and Table[nf][nc] == '1')
		{
			r += bt(nf, nc);
		}
	}
	return r;
}

int main()
{
    #ifdef __test__
        freopen ("in871.txt", "r", stdin);
        freopen ("out871.txt", "w", stdout);  
    #endif 
    #ifdef __unlinkcout__
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        #define endl '\n'
    #endif
    
    int T, mx;
    bool first = true;
    cin >> T;
    getchar();
    getchar();
    while(T--)
    {
    	mx = N = 0;
        while(getline(cin, Table[N++]) and Table[N - 1] != "");
        N--;
        M = Table[0].size();
        for (int i = 0; i < N; ++i)        
        	for (int j = 0; j < M; ++j)
        		if(Table[i][j] == '1')		        		
        			mx = max(bt(i, j), mx);
        if(!first)       	
       		cout << endl;     		
        cout << mx << endl;	
        first = false;
    }

    return 0;
}
