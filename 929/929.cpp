#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__
#define MAX 1000
#define INF 1 << 30

using namespace std;

//{ 4 Direction
const int dx[]={1,0,-1,0}; 
const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

int maze[MAX][MAX], range[MAX][MAX], N, M;
bool visited[MAX][MAX];

struct Node
{
	int f, c, d;
	Node(int f, int c, int d) : f(f), c(c), d(d) {}
};

struct cmp
{
	bool operator()(const Node &a, const Node &b)
	{
		return a.d > b.d;
	}
};

typedef priority_queue<Node, vector<Node>, cmp> MinHeap;

void init(MinHeap &H)
{
	H.push(Node(0, 0, maze[0][0]));	
	for (int i = 0; i < MAX; ++i)
	{
		memset(visited[i], false, sizeof(visited[i]));
		fill(range[i], range[i] + MAX, INF);
	}
	range[0][0] = maze[0][0];
}

void dijkstra(int gf, int gc)
{
	MinHeap H;
	init(H);	
	while(not H.empty()) 
	{
	    Node current = H.top();	    
	    H.pop();	    	    
	    if(current.f == gf and current.c == gc)
	    	return;
	    visited[current.f][current.c] = true;
	    for (int i = 0; i < 4; ++i)
	    {
	    	int nf = current.f + dx[i];
	    	int nc = current.c + dy[i];	    	
	    	if ((nf >= 0 and nf < N) and (nc >= 0 and nc < M) and not visited[nf][nc])
	    	{
	    		if(range[nf][nc] > maze[nf][nc] + range[current.f][current.c])
	    		{
	    			range[nf][nc] = maze[nf][nc] + range[current.f][current.c];
	    			H.push(Node(nf, nc, range[nf][nc]));
	    		}	    		
	    	}
	    }
	}
}

int main()
{
    #ifdef __test__
        freopen ("in929.txt", "r", stdin);
        freopen ("out929.txt", "w", stdout);        
    #endif 
    #ifdef __unlinkcout__
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        #define endl '\n'
    #endif
    
    int T;

    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for (int i = 0; i < N; ++i)        
        	for (int j = 0; j < M; ++j)        	
        		cin >> maze[i][j];
        dijkstra(N - 1, M - 1);
        cout << range[N - 1][M - 1] << endl;
    }

    return 0;
}
