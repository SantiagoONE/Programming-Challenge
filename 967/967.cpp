/*

  Realizado con C++11
  
  Genero los primos circulares en un .txt luego, los guardo en un vector<int>
  para poder usar lower_bound y upper_bound. La diferencia entre los dos iteradores
  entregados será la cantidad de primos circulares desde un punto i hasta j, inclusive.	
  
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

void criba(int n)
{
    bitset<1000001> primes;
    int t = sqrt(n) + 1;
    for(int i = 4; i < n; i+=2)
        primes.set(i);
    for(int i = 3; i < t; i+=2)
        if(!primes.test(i))
            for(long long j = i * i; j < n; j += 2*i)
            	primes.set(j);
    
    //cout << "vector<int> circle_primes {";
    for(int i = 100; i <= n; i++)
    {
        if(!primes.test(i))
        {
            t = i;
            long long mult = pow(10, (int)log10(t));
            while(true)
            {			
            	//12[3] -> [3]12
            	//31[2] -> [2]31
            	//23[1] -> [1]23
            	t = ((t % 10) * mult) + t / 10;
            	if(primes.test(t) or t == i)
            		break;
            }
            if(t == i){
            	//este es un número primo circular el cual puede ser marcado 
            	//dentro de otro bitset o array de booleanos
            	//cout << t << ", ";
            }
        }
    }	
    //cout << "}" << endl;	
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
    
    //} para generar los primos circulares
    //criba(1000000); 
    //}
    vector<int>::iterator low, up;
    vector<int> circle_primes { 113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991,
                                1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391,
                                19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 
                                199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 	
                                939391, 993319, 999331 };
    int a, b;
    while(cin >> a)
    {			
        if(a == -1) 
            break;
        cin >> b;
        
        low = lower_bound(circle_primes.begin(), circle_primes.end(), a); 
        up = upper_bound(circle_primes.begin(), circle_primes.end(), b);
        
        if(up - low == 0)
          cout << "No Circular Primes.";
        else if(up - low == 1) 
          cout << "1 Circular Prime.";
        else 
          cout << up - low << " Circular Primes.";
        cout << '\n';
    }
    return 0;
}
