/*

  Consiste en simular el comportamiento del problema: 

      1 2 3 4 5 6 7 8 9 10 11 12 13 14
      D L M X J V S D L M  X  J  V  S     Media
  P1      x     x     x       x           3
  P2        x       x         x           4
  P3                x                     8

  Dp      x x       x x       x       =>  8 Dp (Días perdidos)

  Pi = Partido politico i-ésimo
  Media = Cantidad de días promedio de huelgas

  El problema se reduce a realizar OR en P conjunto de bits
  y hacer un conteo de los bits en true. No se marcarán aquellos
  días perdidos en viernes o sábado. 

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
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
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
    
    int k, n, p, h[100];
    bitset<3651> days[101];
    cin >> k;
    while(k--) 
    {
        cin >> n >> p;
        for (int i = 0; i < p; ++i)
            cin >> h[i];

        for (int i = 0; i < p; ++i)
        {
            for (int s = h[i];  s <= n; s += h[i])
            {
                if(s % 7 and s % 7 != 6)  // no ser multiplo de 7 y no se debe cumplir que 6 + 7*x = s, x >= 0
                    days[i + 1].set(s);                
            }
        }

        for (int i = 1; i <= p; ++i)
            days[0] |= days[i];

        cout << days[0].count() << '\n';

        for (int i = 0; i <= p; ++i)
            days[i].reset();
    }
    return 0;
}
