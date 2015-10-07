#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__

using namespace std;

template <class T, class U> inline T max (T &a, U &b) {  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b) {  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a;  a = b; b = tmp; }

//{ 4 Direction
const int dx[]={0,-1,0,1}; const int dy[]={1,0,-1,0}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

inline short cast(char c)
{
    return (c == 'R' or c == 'N')? 0 :
           (c == 'L' or c == 'W')? 1 : 
           (c == 'S')? 2 : 3;
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
    
    short limx, limy; //limites del plano de coordenadas    
    short x, y; //coordenadas de inicio del robot
    char cdir;  //current direction
	
	
    //fila    0, 1, 2, 3 = N, W, S, E
    //columna 0, 1 = R, L
    //la funcion cast hace esto, dado un char que representa una direccion
    //u orientacion, devolver un index usando en los array changes, dx y dy
    char changes[4][2] = {{'E','W'},{'N','S'},{'W','E'},{'S','N'}};
    
    list<pair<short, short> > bordes;
    list<pair<short, short> >::iterator it;
    string line;
    bool perdido;

    cin >> limx >> limy;
    while(cin >> x >> y >> cdir)
    {    	    	
    	cin >> line;
    	perdido = false;
    	for(size_t i = 0; i < line.size(); i++)
    	{
    		if(line[i] == 'R' or line[i] == 'L')
    			cdir = changes[cast(cdir)][cast(line[i])];
    		else
    		{
    			short tx = x + dx[cast(cdir)];
    			short ty = y + dy[cast(cdir)];
    			if((tx < 0 or tx > limx) or (ty < 0 or ty > limy))
    			{
    				it = find(bordes.begin(), bordes.end(), make_pair(x, y));
    				if(it == bordes.end())
    				{
    					bordes.push_back(make_pair(x, y));
    					perdido = true;
    					break;		
    				}
    			}
    			else    				
    			{
    				x = tx;
    				y = ty;
    			}
    		}    		
    	}
    	cout << x << ' ' << y << ' ' << cdir << ((perdido)? " LOST\n": "\n");
    }

    return 0;
}
