#include <bits/stdc++.h>
#define MAX 32
#define check(x, y, z) ((x >= 0 and x < R) and (y >= 0 and y < C) and (z >= 0 and z < L))
//#define __test__
#define __unlinkcout__

using namespace std;

//{ 4 Direction
const int dx[]={0,0,1,0,-1,0}; 
const int dy[]={0,0,0,1,0,-1}; 
const int dz[]={-1,1,0,0,0,0};
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

struct Node
{
	int l, f, c, d;
	Node(int l, int f, int c, int d) : l(l), f(f), c(c), d(d){}
	Node(): l(-1), f(-1), c(-1), d(-1){}
};

char dungeon[MAX][MAX][MAX];
bool available[MAX][MAX][MAX];
int L, R, C;

int bfs(const Node &initial)
{
	queue<Node> Q;
	Q.push(initial);
	available[initial.l][initial.f][initial.c] = false;
	while(not Q.empty()) 
	{
	    Node current = Q.front();
	    Q.pop();
	    if(dungeon[current.l][current.f][current.c] == 'E')	    
	    	return current.d;	    
	    for (int x, y, z, i = 0; i < 6; ++i)
	    {
	    	z =	dz[i] + current.l;
	    	x = dx[i] + current.f;
	    	y =	dy[i] + current.c;
	    	if(check(x, y, z) and available[z][x][y] and dungeon[z][x][y] != '#')
	    	{
	    		Q.push(Node(z, x, y, current.d + 1));	    		
	    		available[z][x][y] = false;    		
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

    Node initial;    

    while(cin >> L >> R >> C)
    {
    	if(!L and !R and !C)
    		break;    	
    	for (int k = 0; k < L; ++k)
    		for (int i = 0; i < R; ++i)    		
    			memset(available[k][i], true, sizeof(available[k][i]));
    	for (int k = 0; k < L; ++k)    	
    		for (int i = 0; i < R; ++i)        
        		for (int j = 0; j < C; ++j)
        		{
        			cin >> dungeon[k][i][j];
        			if(dungeon[k][i][j] == 'S')       			
        				initial = Node(k, i, j, 0);        			
        		}
    	int r = bfs(initial);
    	if(r != -1)	cout << "Escaped in " << r << " minute(s).";
    	else cout << "Trapped!";
		cout << endl;
    }
    return 0;
}
