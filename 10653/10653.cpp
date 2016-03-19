#include <bits/stdc++.h>
#define MAX 1005
#define check(x, y) (x >= 0 and x < R) and (y >= 0 and y < C)
//#define __test__
#define __unlinkcout__

using namespace std;

//{ 4 Direction
const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

int R, C;
char table[MAX][MAX];
bool visited[MAX][MAX];

struct Node
{
	int f, c, d;
	Node(int f, int c, int d) : f(f), c(c), d(d){}
	Node(): f(-1), c(-1), d(-1){}
	bool operator ==(const Node &other)
	{
		return f == other.f and c == other.c;
	}
};

Node goal;

void reset()
{
	for (int i = 0; i < MAX; ++i)	
		for (int j = 0; j < MAX; ++j)		
			table[i][j] = '.';
	for (int i = 0; i < MAX; ++i)
		memset(visited, false, sizeof(visited));
}

int bfs(const Node &initial)
{
	queue<Node> Q;
	visited[initial.f][initial.c] = true;
	Q.push(initial);
	while(not Q.empty())
	{
	    Node current = Q.front();
	    Q.pop();
	    if (current == goal)
	    	return current.d;
	    for (int x, y, i = 0; i < 4; ++i)
	    {
	       	x = current.f + dx[i];
	       	y = current.c + dy[i];
	       	if (check(x, y) and not visited[x][y] and table[x][y] != '*')
	       	{
	       		Q.push(Node(x, y, current.d + 1));
	       		visited[x][y] = true;
	       	}
	    }	    
	}
	return -1;
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
    
    int lines, bombs, row, col;
    Node initial;

    while(cin >> R >> C) 
    {
        if(!R and !C)
        	break;
        reset();
        cin >> lines;
        while(lines--)
        {
            cin >> row >> bombs;
            while(bombs-- and cin >> col)            
                table[row][col] = '*';
        }        
        cin >> initial.f >> initial.c;
        cin >> goal.f >> goal.c;
        initial.d = 0;
        cout << bfs(initial) << endl;
    }
    return 0;
}