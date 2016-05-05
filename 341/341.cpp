#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__
#define MAX 10
#define INF (1 << 30)

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

typedef pair<int, int> Node;

struct cmp
{   
	bool operator ()(const Node &a, const Node &b)
	{
		return a.second > b.second;
	}
};

typedef priority_queue<Node, vector<Node>, cmp> MinHeap;
vector<Node> ady[MAX + 2];
int range[MAX + 2], before[MAX + 2];
bool visited[MAX + 2];

void reset()
{
	for (int i = 0; i < MAX + 2; ++i)	
		ady[i].clear();	
}

void init()
{
    memset(visited, false, sizeof(visited));
    fill(range, range + MAX + 2, INF);
    fill(before, before + MAX + 2, -1);
}

string print(int goal)
{
    if(before[goal] == -1)   
        return to_string(goal);
    return print(before[goal]) + " " + to_string(goal);
}

void dijkstra(int origen)
{
    init();
	MinHeap Q;
    range[origen] = 0;
	Q.push(Node(origen, range[origen]));
    while(not Q.empty())
    {
        int nodoActual = Q.top().first;
        Q.pop();
        if(visited[nodoActual])
            continue;
        visited[nodoActual] = true;
        for(const auto &node : ady[nodoActual])
        {
            int nodoAdyacente = node.first;
            int costoAlAdyacente = node.second;
            if(not visited[nodoAdyacente] and range[nodoActual] + costoAlAdyacente < range[nodoAdyacente])
            {
                range[nodoAdyacente] = range[nodoActual] + costoAlAdyacente;
                before[nodoAdyacente] = nodoActual;
                Q.push(Node(nodoAdyacente, range[nodoAdyacente]));
            }
        }
    }
}

int main()
{
    #ifdef __test__
        freopen ("in341.txt", "r", stdin);
        freopen ("out341.txt", "w", stdout);        
    #endif 
    #ifdef __unlinkcout__
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        #define endl '\n'
    #endif
   	
   	int NI, m, id, coste, origen, goal, cs = 1;;

   	while(cin >> NI and NI)
   	{
   		for (int i = 1; i <= NI ; ++i)
   		{
   			cin >> m;
	   	    while(m--)
	   	    {
	   	        cin >> id >> coste;
	   	        ady[i].push_back(Node(id, coste));
	   	    }
   		}
   		cin >> origen >> goal;
   		dijkstra(origen);
   		cout << "Case " << cs++ << ": Path = " 
   			 << print(goal) << "; " << range[goal] 
   			 << " second delay" << endl;
   		reset();
   	}
    return 0;
}
