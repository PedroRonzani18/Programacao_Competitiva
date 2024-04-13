/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int quant,carry,carry2;
    cin>>quant;
    vector<int> vec(quant);
    for(int x=0;x<quant;x++)
        cin>>vec[x];

    for(int x=0;x<quant-1;x++){
        cout<<vec[x]<<" ";
    }
    cout<<vec[quant-1]<<"\n";

    while(cin>>carry){
        if(carry == -1) break;
        cin>>carry2;
        vec[carry]=carry2;
        for(int x=0;x<quant-1;x++){
            cout<<vec[x]<<" ";
        }
        cout<<vec[quant-1]<<"\n";
    }

    return 0;
}

