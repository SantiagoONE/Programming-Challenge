#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

typedef pair<string, short> psi;
string dict[205];
bool available[205];
short N;

bool distOne(const string &a, const string &b)
{
	short count = 0, len = a.length();
	if(len == (short)b.length())
	{
		for (short i = len - 1; i >= 0; --i)
			if(a[i] != b[i])
				count++;
	}
	return (count == 1);
}

int bfs(const string &start, const string &goal)
{
	queue<psi> Q;
	Q.push(make_pair(start, 0));
	available[find(dict, dict + N, start) - dict] = false;

	while(not Q.empty()) 
	{
	    psi current = Q.front();
	    Q.pop();
	    if(current.first == goal)
	    	return current.second;
	    for (int i = 0; i < N; ++i)
	    {
	    	if(available[i] and distOne(dict[i], current.first))
	    	{
	    		Q.push(make_pair(dict[i], current.second + 1));
	    		available[i] = false;
	    	}
	    }
	}

	return -1;
}

int main()
{
    #ifdef __test__
        freopen ("in.txt", "r", stdin);
        //freopen ("out.txt", "w", stdout);
    #endif 
    #ifdef __unlinkcout__
        #define endl '\n'
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    #endif
        
    string line, start, goal;
    bool first = true;
    int T;

    cin >> T;
    getchar(); getchar();

    while(T--)
    {
    	N = 0;
    	while(getline(cin, dict[N]) and dict[N++] != "*");
    	N--;    	
    	if(!first) cout << endl;
    	while(getline(cin, line) and line != "")
    	{
    		istringstream iss(line);
    		iss >> start;
    		iss >> goal;
    		memset(available, true, sizeof(available));
        	cout << start << ' ' << goal << ' ' << bfs(start , goal) << endl;
    	}	
    	first = false;
    }
    return 0;
}
