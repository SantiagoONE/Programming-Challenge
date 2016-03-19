#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__
#define make_coord(str, d) Node((str[1])-'1', (str[0])-'a', d)

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}
//{ Knight Direction
const int dx[]={2,1,-1,-2,-2,-1,1,2}; const int dy[]={1,2,2,1,-1,-2,-2,-1};
//}

struct Node
{
	int f, c, d;
	Node(int f, int c, int d) : f(f), c(c), d(d){}	
	Node(): f(-1), c(-1), d(-1){}
};

Node goal;
bool chessboard[8][8];

int bfs(const Node start)
{
	queue<Node> Q;
	Q.push(start);
	chessboard[start.f][start.c] = true;
	while(not Q.empty()) 
	{
		Node current = Q.front();
		Q.pop();
		if(current.f == goal.f and current.c == goal.c)
			return current.d;
		for (int i = 0; i < 8; ++i)
		{
			int x = current.f + dx[i];
			int y = current.c + dy[i];
			if((x >= 0 and x < 8) and (y >= 0 and y < 8) and !chessboard[x][y])
			{
				Q.push(Node(x, y, current.d + 1));
				chessboard[x][y] = true;
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
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    #endif
    
    string line, from, to;
    while(getline(cin, line) and line != "")
    {
    	istringstream iss(line);
    	iss >> from >> to;
    	goal = make_coord(to, -1);
    	for (int i = 0; i < 8; ++i)   	
 			memset(chessboard[i], false, sizeof(chessboard[i]));
    	printf("To get from %s to %s takes %d knight moves.\n", from.c_str(), to.c_str(), bfs(make_coord(from, 0)));
    }
    return 0;
}
