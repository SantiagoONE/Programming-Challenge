/*

Dadas ciertas cantidades de dinero, tenemos que obtener la parte que necesitamos extraer e incluir, para que 
de esta manera todas las cantidades sean semejantes.

Obtener el promedio nos dará la cantidad objetivo para cada monto. Si la cantidad-i es mayor que el promedio
entonces cantidad-i - promedio es parte del exceso (not_need). Si la cantidad-i es menor que el promedio
entoces promedio - cantidad-i es parte de lo que falta para balancear los montos (need).

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
    cout << fixed << setprecision(2);
    int n, i;
    double avg, need, not_need, t;
    double students[1001];
    while(cin >> n and n!=0) 
    {    	
    	avg = need = not_need = 0.0;
    	for (i = 0; i < n; avg += students[i++])
    		cin >> students[i];
    	avg /= n;
    	for (i = 0; i < n; ++i)
    	{    		
    		if(students[i] < avg){    			    			
    			//se gana precision convirtiendo los centavos en dolares y luego almacenarlos como centavos.
    			t = (long) ((avg - students[i]) * 100.0) / 100.0;    			
    			need += t;
    		}
    		else if(students[i] > avg){
    			t = (long) ((students[i] - avg) * 100.0) / 100.0; 			
    			not_need += t;
    		}
    	}
    	cout << '$' << max(need, not_need) << '\n';   	
    }
    return 0;
}
