/*

  Consiste en leer la configuración de un tablero de ajedrez y decir cual de los reyes esta en jaque,
  siempre solo uno lo estará o por defecto ninguno.  

  La funcion br hace un recorrido por el arreglo que se le pasa como argumento, este arreglo es 
  enviado como un puntero al inicio y otro al final. Esto para que dentro de un solo arreglo se pueda
  almacenar los movimientos del alfil y torre. Y por defecto todo el arreglo serian los movimientos de la reina.

  En este algoritmo el enfoque es que apartir de la posición de un rey se pueda saber si es amenazado.

*/

#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__

using namespace std;

template <class T, class U> inline T max (T &a, U &b) {  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b) {  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a;  a = b; b = tmp; }

struct Coord
{
    short f, c;
};

//{ Directions
const Coord b_r[]  = {{1,1},{-1,-1},{1,-1},{-1,1},{1,0},{0,1},{-1,0},{0,-1}};
const short nx[] = {2,1,-1,-2,-2,-1,1,2};
const short ny[] = {1,2,2,1,-1,-2,-2,-1};
//}

char Table[12][12] = {};

bool br(short i, short j, const Coord *dir, const Coord *end, char piece)
{
    short f, c;
    char queen = islower(piece)? 'q' : 'Q';
    while(dir < end)
    {
        for(f = i + dir->f, c = j + dir->c; Table[f][c] == '.'; f+=dir->f, c+=dir->c);
        if(Table[f][c] == piece or Table[f][c] == queen)
            return true;
        dir++;
    }
    return false;
}

bool n(short i, short j, char piece)
{
    for (short ii = 0; ii < 8; ++ii)    
        if(Table[i + nx[ii]][j + ny[ii]] == piece)           
            return true;    
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
    #endif        
    
    bool game;    
    Coord k, K;
    for (int cs = 1;; ++cs)
    {
    	game = false;    	
        k.c = k.f = K.c = K.f = 0;
    	for(short i = 2; i < 10; i++)
    		for(short j = 2; j < 10; j++)
    		{
    			cin >> Table[i][j];
    			if(Table[i][j] == 'k'){
    				k.f = i;	
    				k.c = j;		
    			}
    			if(Table[i][j] == 'K'){
    				K.f = i;	
    				K.c = j;
    			}
    			if(Table[i][j] != '.')
    				game = true;
    		}

    	if(!game)
    		break;
        
        //{ Peon or Caballo or Alfil or Torre
        if((Table[k.f + 1][k.c + 1] == 'P' or Table[k.f + 1][k.c - 1] == 'P')
            or n(k.f, k.c, 'N') or br(k.f, k.c, b_r, b_r + 4, 'B') or br(k.f, k.c, b_r + 4, b_r + 8, 'R'))
            cout << "Game #" << cs << ": black king is in check." <<'\n';
        else if((Table[K.f - 1][K.c + 1] == 'p' or Table[K.f - 1][K.c - 1] == 'p')
            or n(K.f, K.c, 'n') or br(K.f, K.c, b_r, b_r + 4, 'b') or br(K.f, K.c, b_r + 4, b_r + 8, 'r'))
            cout << "Game #" << cs << ": white king is in check." <<'\n';
        else
            cout << "Game #" << cs << ": no king is in check." <<'\n';
        //}
    }
    return 0;
}
