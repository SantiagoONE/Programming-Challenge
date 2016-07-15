#include <bits/stdc++.h>
#define __test__
#define __unlinkcout__

using namespace std;

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

struct Node
{
	bool isOver;
	Node* alpha[27];

	Node() : isOver(false)
	{
		for (int i = 0; i < 27; ++i)
			alpha[i] = NULL;	
	}

	~Node()
	{
		for (int i = 0; i < 27; ++i)		
			if(alpha[i] != NULL)
				delete alpha[i];		
	}
};

struct MyTrie
{
	Node* root;

	MyTrie()
	{
		root = new Node();
	}

	~MyTrie()
	{
		delete root;	
	}

	void insert(string::iterator it, string::iterator end)
	{
		Node* p = root;
		while(it != end)
		{
			if(p->alpha[*it - 'a'] == NULL)
				p->alpha[*it - 'a'] = new Node();				
			p = p->alpha[*it - 'a'];
			it++;
		}
		p->isOver = true;
	}

	short keystrokes(string::iterator it, string::iterator end)
	{
		bool found;
		short counter = 1;
		Node* prev = root->alpha[*it - 'a'];
		Node** alpha = root->alpha[*it - 'a']->alpha;	
		for (it++; it != end; prev = alpha[*it - 'a'], alpha = alpha[*it - 'a']->alpha, it++)
		{
			found = false;
			for (short j = 0; j < 27; ++j)			
				if(alpha[j] != NULL and j != *it - 'a')
				{
					found = true;					
					break;		
				}				
			if(not found and not prev->isOver) 
				continue;
			else 
				counter++;
		}
		return counter;
	}
};

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
    double sum;
    vector<string> dict(100000);
    while(cin >> n) 
    {
    	cin.ignore();
    	MyTrie myTrie;
    	for (int i = 0; i < n; ++i)
    	{
    		getline(cin, dict[i]);
    		myTrie.insert(dict[i].begin(), dict[i].end());
    	}
    	sum = 0;
    	for (int i = 0; i < n; ++i)
    		sum += myTrie.keystrokes(dict[i].begin(), dict[i].end());
    	cout << setprecision (2) << fixed << sum / n << endl;
    }
    return 0;
}