#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__

using namespace std;

template <class T, class U> inline T max (T &a, U &b) {  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b) {  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a;  a = b; b = tmp; }

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

struct Cnt // Contestant
{	
	int time;
	int errors[10];
	bitset<10> problems; // era solo un arreglo de booleanos :P
};

typedef map<int, Cnt*> contest_map;
typedef pair<int, Cnt*> k_v;
typedef vector<k_v> contest_vector;

bool cmp(const k_v &a, const k_v &b)
{
	if (a.second->problems.count() != b.second->problems.count())
		return a.second->problems.count() > b.second->problems.count();
	else if(a.second->time != b.second->time)
		return a.second->time < b.second->time;
	else 
		return a.first < b.first;	
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
    
    int k, c, p, t;    
    char r;
    string line;        
    contest_map data;  
    contest_vector arr_data;

    //esta vez no pude usar el __unlinkcout__ por errores extraños
    cin >> k;
    getchar(); getchar();
    while(k--)
    {    	    	    	
    	while(getline(cin, line))
    	{     		
	    	if(line.empty())
	    		break;
	    	istringstream iss(line);
	    	iss >> c >> p >> t >> r;
	
	    	if(data.find(c) == data.end())
			data[c] = new Cnt();
	
		if(r == 'C')
		{
			if(data[c]->problems.test(p) == false)
			{
				data[c]->time += t + data[c]->errors[p] * 20;
				data[c]->problems.set(p);
			}
		}
		else if(r == 'I')
		{				
			// si el concursante logra resolver el problema, al momento de 
			// sumar el tiempo que le tomo llegar a la primera solucion, 
			// se le añadirá 20 min por cada envio erroneo.
			if(data[c]->problems.test(p) == false)
				data[c]->errors[p]++;
		}
    	}

    	arr_data = contest_vector(data.begin(), data.end());
    	sort(arr_data.begin(), arr_data.end(), cmp);
    	
    	for (vector<k_v>::iterator i = arr_data.begin(); i != arr_data.end(); ++i)    	
    		cout << i -> first << ' ' << i -> second->problems.count() << " " << i->second->time << '\n';    	    	
    	if(k)
    		cout << '\n';
    	data.clear();
    }
    return 0;
}
