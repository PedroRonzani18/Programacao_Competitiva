/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define PI 3.14159265358979323846

int32_t main(){

    double lado,raio;
    cin>>lado;
    raio = lado/2.0;
    
    printf("%0.2lf\n",lado*lado - PI*raio*raio);

    return 0;
}

