/*
  Realizado con C++11
*/
#include <bits/stdc++.h>
#define MAX 305
//#define __test__
#define __unlinkcout__

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

list<int> adys[MAX];
int before[MAX];
bool available[MAX];

void reset()
{
	memset(available, true, sizeof(available));	
	memset(before, 0, sizeof(before));    
}

void bfs(int start, int goal)
{
	queue<int> Q;
	Q.push(start);
	available[start] = false;
	before[start] = -1;
	while(not Q.empty()) 
	{
		int current = Q.front();
		Q.pop();
		if(current == goal)	
		{
			list<int> path;
			for(; before[current] != -1; current = before[current])				
				path.push_front(current);
			cout << start;
			for(auto e : path)
				cout << ' ' << e;		
			return;
		}				
		for(auto e : adys[current])
		{
			if(available[e])
			{
				Q.push(e);
				available[e] = false;
				before[e] = before[e]? min(before[e], current) : current;
			}
		}
	}
	cout << "connection impossible";
}

int main()
{
    #ifdef __test__
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif 
    #ifdef __unlinkcout__
        #define endl '\n'
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    #endif

    string line;
    regex pattern("-|,");
    int R, N, id, from, to;

    while(cin >> N)
    {
    	for (int i = 0; i < N; ++i)
    	{
    		cin >> line;
    		istringstream iss(regex_replace(line, pattern, " "));
    		iss >> id;
    		adys[id] = list<int>((istream_iterator<int>(iss)), istream_iterator<int>());    		
    	}    	
    	cout << "-----" << endl;
    	cin >> R;
    	while(R--)
    	{
    		cin >> from >> to;
    		reset();
    		bfs(from, to);
    		cout << endl;
    	}
    }
    return 0;
}
