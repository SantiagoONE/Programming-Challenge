/*
  5515 - Maya Calendar
  ACM-ICPC Live Archive
*/
#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__

using namespace std;

typedef long long ll;

//{ 19 meses, los 18 primeros tiene 20 dias y el último tiene solo 5. 
//  Todos los dias son nombrados con números de 0 ... 19 o 0 ... 4 dependiendo del mes
string haab[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", 
				   "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
//}
//{ 20 días, cada dia tiene un nombre más un número 1 ... 13. Estos se repiten ciclicamente 
string tzolkin[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
					  "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
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
	
	int test, day, year;
	char month[7];
	 
	cin >> test;
	cout << test << '\n';
	while(test--)
	{
		scanf("%d. %s %d", &day, month, &year);
		int i = day + year * 365 + 20 * (find(haab, haab + 19, month) - haab), // i-ésimo día que representa el input
		y = i / 260, // y-ésimo año 
		d = i % 260; // d-ésimo día dentro del y-ésimo año
		cout << d % 13 + 1 << ' ' << tzolkin[d % 20] << ' ' << y << '\n';
	}
}
