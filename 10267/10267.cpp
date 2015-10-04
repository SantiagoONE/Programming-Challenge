/*

  Consiste en crear un editor gráfico por LCI, los inputs serán comandos y estos tendrán parametros
  que dictarán la ejecución del comando.
  
  Los enunciados son engañosos porque:
  
    X -> columnas
    Y -> filas
    
  "...entre las lineas Y1 Y2...", no quiere decir que Y1 siempre sea menor que Y2, lo mismo pasa para las columnas.

*/

#include <bits/stdc++.h>
//#define __test__
#define __unlinkcout__

using namespace std;

template <class T, class U> inline T max (T &a, U &b) {  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b) {  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a;  a = b; b = tmp; }

//{ 4 Direction
const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

char grid[255][255];
short N, M;

void fill(short f, short c, char color, char old_color)
{		
	grid[f][c] = color;
	for(short i = 0; i < 4; i++)
	{
		short _f = f + dx[i];
		short _c = c + dy[i];				
		if((_f >= 1 and _f <= N) and (_c >= 1 and _c <= M) and grid[_f][_c] == old_color)
			fill(_f, _c, color, old_color);
	}
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
    string input, name;
    short X, Y, Y1, Y2, X1, X2;
    char comand, color;

    while(true)
    {
    	getline(cin, input);
        istringstream iss(input);
        iss >> comand;

    	if(comand == 'X')
    		break;
    	
        switch(comand)
        {
            case 'I':   iss >> M >> N;
                        for (short i = 1; i <= N; ++i)          
                            for (short j = 1; j <= M; ++j) grid[i][j] = 'O';
                        break;

            case 'C':   for (short i = 1; i <= N; ++i)          
                            for (short j = 1; j <= M; ++j) grid[i][j] = 'O';
                        break;

            case 'L':   iss >> X >> Y >> color;
                        grid[Y][X] = color;
                        break;

            case 'V':   iss >> X >> Y1 >> Y2 >> color;
                        if(Y1 > Y2) 
                            swap(Y1, Y2);
                        for(short i = Y1; i <= Y2; i++)
                            grid[i][X] = color;
                        break;

            case 'H':   iss >> X1 >> X2 >> Y >> color;
                        if(X1 > X2)
                            swap(X1, X2);
                        for(short j = X1; j <= X2; j++)
                            grid[Y][j] = color;
                        break;

            case 'K':   iss >> X1 >> Y1 >> X2 >> Y2 >> color;
                        if(Y1 > Y2)
                            swap(Y1, Y2);
                        if(X1 > X2)
                            swap(X1, X2);
                        for(short i = Y1; i <= Y2; i++)
                            for(short j = X1; j <= X2; j++)
                                grid[i][j] = color;
                        break;

            case 'F':   iss >> X >> Y >> color;
                        if(color != grid[Y][X]) //si son iguales la funcion fill entraria en recurrecia infinita
                            fill(Y, X, color, grid[Y][X]);
                        break;

            case 'S':   iss >> name;
                        cout << name << '\n';
                        for (short i = 1; i <= N; ++i){
                            for (short j = 1; j <= M; ++j) 
                                cout<<grid[i][j];
                            cout << '\n';
                        }
                        break;
        }
    }    
    return 0;
}
