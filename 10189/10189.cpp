/*

Dado un tablero que representa el juego buscaminas, devolver otro tablero que represente
las minas alrededor de un punto seguro del tablero.

. -> punto seguro
* -> mina

Ej:

in:			out:
	*...		 *100
	....		 2210
	..*.		 1*10
	....		 1110
	
*/

#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__

using namespace std;

template <class T, class U> inline T max (T &a, U &b) {  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b) {  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a;  a = b; b = tmp; }

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

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
    
    int n, m, f, c, i, j, k, cont, cs = 0;
    string matriz[101];

    while(cin >> n >> m and !(n == 0 and m == 0)) 
    {    	
    	//{ input
    	for (i = 0; i < n; ++i)
    		cin >> matriz[i];
    	//}

    	//{ algorithm
    	for (i = 0; i < n; ++i) 
    		for (j = 0; j < m; ++j)    		
    			if(matriz[i][j] == '.')
    			{    				
    				for (cont = k = 0; k < 8; ++k)
    				{
    					f = i + dx[k];  c = j + dy[k];
    					if ((f >= 0 and f < n) and (c >= 0 and c < m) and (matriz[f][c] == '*'))    					
    						cont++;
    				}
    				matriz[i][j] = '0' + cont;
    			}	    			
    	//}
    	
	//} output
 	if(cs != 0) cout << '\n';
    	cout << "Field #" << ++cs << ":\n";
    	for (i = 0; i < n; ++i)
    		cout << matriz[i] << '\n';
    	//}
    }
    return 0;
}
