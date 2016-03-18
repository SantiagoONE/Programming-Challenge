#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__
//#define __debug__

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

typedef long long ll;
typedef list<ll> li;
typedef map<ll, li> Graph;

Graph G;
set<ll> all;
bool available[30];
int n;

int findNode(int value)
{
	int index = 0;
	for (set<ll>::iterator it = all.begin(); it != all.end(); ++it, ++index)
		if(*it == value) return index;		
	return -1;
}

int bfs(ll origen, int ttl)
{
	/*
		Calcula la "cantidad de nodos que puede visitar" 
		desde un origen y con un ttl (tiempo de vida) dado.
	*/
	int children, index, count = 0,
	elementsInCurrentLevel = 1,
	nextElementsInCurrentLevel = 0;

	/*
		# Si el nodo no esta dentro del grafo (index == -1) 
		la cantidad de nodos visitados es 0 (return 0)
		# Si el nodo esta dentro del grafo, marcarlo
		como no disponible (available[index] = false)
		para no repetir nodos en la	busqueda.
		# Si el ttl es 0, solo podra visitarse a si mismo,
		siempre que este dentro del grafo. (index != -1)
	*/

	index = findNode(origen);
	if(index == -1) return 0;
	else available[index] = false;
	if(ttl == 0) return (index != -1);

	queue<ll> Q;
	Q.push(origen);

	while(!Q.empty())
	{
		int current = Q.front();		
		Q.pop();
		Graph::iterator node = G.find(current);
		if(node == G.end())
			continue;
		li::iterator ady = node->second.begin();
		li::iterator end = node->second.end();
		children = 0;
		while(ady != end)
		{			
			index = findNode(*ady);
			if(available[index])
			{				
				Q.push(*ady);
				available[index] = false;
				count++;
				children++;
			}
			ady++;
		} 
		nextElementsInCurrentLevel += children;
		if(--elementsInCurrentLevel == 0)
		{
			if (--ttl == 0)		
				return count + 1;			
      		elementsInCurrentLevel = nextElementsInCurrentLevel;
      		nextElementsInCurrentLevel = 0;
		}
	}	
	return count + 1;
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
    
    int nc, ttl, cs = 0, r;
    ll test;

    while(cin >> nc and nc)
    {
    	for (ll u, v, i = 0; i < nc; ++i)
    	{
    		cin >> u >> v;
    		G[u].push_back(v);
    		G[v].push_back(u);    		
    		all.insert(u);
    		all.insert(v);
    	}    	
    	n = all.size();
    	while(cin >> test >> ttl)
    	{
    		if(!test and !ttl)
    			break;
    		memset(available, true, sizeof(available));
    		r = n - bfs(test, ttl);
    		cout << "Case " << ++cs << ": " << r << " nodes not reachable from node " << test << " with TTL = " << ttl << "." << endl;
    	}
    	G.clear();
    	all.clear();
    }
    return 0;
}
