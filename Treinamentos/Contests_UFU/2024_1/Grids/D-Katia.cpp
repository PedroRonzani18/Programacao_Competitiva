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

    int diag1=0,diag2=0,tamanho;
    cin>>tamanho;
    vector<vector<int>> matriz(tamanho,vector<int>(tamanho));
    for(int x=0;x<tamanho;x++){
        for(int y=0;y<tamanho;y++){
            cin>>matriz[x][y];
        }
    }
    for(int x=0,y=0;x<tamanho;x++,y++){
        diag1+=matriz[x][y];
    }
    for(int x=0,y=tamanho-1;x<tamanho;x++,y--){
        diag2+=matriz[x][y];
    }
    cout<<abs(diag1-diag2)<<"\n";

    return 0;
}

