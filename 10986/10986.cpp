#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__
#define MAX 20002
#define INF 1 << 30

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
	bool operator()(const Node &a, const Node &b)
	{
		return a.second > b.second;
	}
};

typedef priority_queue<Node, vector<Node>, cmp> MinHeap;
vector<Node> ady[MAX];
bool visited[MAX];
int range[MAX];

void reset()
{
	for (int i = 0; i < MAX; ++i)
		ady[i].clear();
}

void init(MinHeap &H, int start)
{
	memset(visited, false, sizeof(visited));
    fill(range, range + MAX, INF);    
    range[start] = 0;
    H.push(Node(start, 0));
}

bool dijkstra(int start, int goal)
{
	MinHeap H;
	init(H, start);    
	while(not H.empty())
	{
	    int node = H.top().first;
        H.pop();
        if(node == goal)
            return true;
        visited[node] = true;
        for(const auto &child : ady[node])
        {
            int n = child.first;
            int d = child.second;
            if(not visited[n] and range[n] > range[node] + d)
            {
                range[n] = range[node] + d;                
                H.push(Node(n, range[n]));
            }
        }
	}
    return false;
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
        #define endl '\n'
    #endif
    
    int T, cs = 0, n, m, s, t, w, start, goal;

    cin >> T;
    while(T--)
    {
    	cin >> n >> m >> start >> goal;
    	for (int i = 0; i < m; ++i)
    	{
    		cin >> s >> t >> w;
    		ady[s].push_back(Node(t, w));
    		ady[t].push_back(Node(s, w));
    	}
        cout << "Case #" << ++cs << ": ";
    	if(dijkstra(start, goal))       
            cout << range[goal] << endl;
        else 
            cout << "unreachable" << endl;
        reset();
    }

    return 0;
}
