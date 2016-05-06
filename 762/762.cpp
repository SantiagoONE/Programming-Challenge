#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__
#define MAX 800

using namespace std;
typedef map<string, vector<string> > Graph;

Graph myGraph;
bool visited[MAX];
int before[MAX];

void init()
{
    memset(visited, false, sizeof(visited));
    fill(before, before + MAX, -1);
}

void print_path(int goal)
{
    if(before[goal] == -1)  return;
    else
    {
        print_path(before[goal]);
        auto it = myGraph.begin();
        cout << next(it, before[goal])->first << ' ' << next(it, goal)->first << endl;
    }
}
int toId(const string &node)
{
    auto it = myGraph.find(node);
    return distance(myGraph.begin(), it);
}

bool bfs(const string &start, const string &goal)
{
    init();
    queue<string> Q;
    Q.push(start);
    visited[toId(start)] = true;
    while(!Q.empty())
    {
        string node = Q.front();
        if(node == goal)
            return true;
        Q.pop();
        for(auto child : myGraph[node])
        {
            int idChild = toId(child);
            if(not visited[idChild])
            {
                visited[idChild] = true;
                before[idChild] = toId(node);                
                Q.push(child);
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

    int n;
    char a[3], b[3];
    bool first = true;

    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s %s", a, b);
            myGraph[string(a)].push_back(string(b));
            myGraph[string(b)].push_back(string(a));
        }
        if(not first) printf("\n");
        scanf("%s %s", a, b);
        if(bfs(string(a), string(b)))        
            print_path(toId(b));        
        else        
            printf("No route\n");
        myGraph.clear();
        first = false;
    }

    return 0;
}
