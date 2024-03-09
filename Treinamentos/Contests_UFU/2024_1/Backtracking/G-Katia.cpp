/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>

using namespace std;
#define int long long int

vector<pair<int,int>> mov = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int32_t main(){

    int linhas,colunas;
    cin>>linhas>>colunas;
    pair<int,int>start;
    vector<vector<int>> matriz(linhas+1,vector<int>(colunas+1,0));
    vector<vector<bool>> visitados(linhas+1,vector<bool>(colunas+1));

    for(int x=0;x<linhas;x++){

        for(int y=0;y<colunas;y++){
            cin>>matriz[x][y];
            if(matriz[x][y]==2){
                start.first=x;
                start.second=y;
                matriz[x][y]=1;
            }
        }
    }

    stack<tuple<int,int,int>> pilha;
    pilha.push({start.first,start.second,1});

    int resp;
    
    int chegou=0;
    while(!pilha.empty()){
        tuple<int,int,int> atual = pilha.top();
        pilha.pop();
        // cout<<"atual.x ="<<get<0>(atual)<<" | atual.y = "<< get<1>(atual)<<"\n";
        if(matriz[get<0>(atual)][get<1>(atual)] ==3){
            chegou =get<2>(atual);
            break;
        }
        for(auto passo : mov){
            if(get<0>(atual )+passo.first >= 0 && get<0>(atual )+passo.first < colunas &&
             get<1>(atual)+ passo.second >= 0 && get<1>(atual)+ passo.second < colunas &&
              visitados[get<0>(atual )+passo.first][get<1>(atual)+ passo.second] == 0 &&
               matriz[get<0>(atual)+passo.first][get<1>(atual) + passo.second] !=0 ){

                visitados[get<0>(atual )+passo.first][get<1>(atual)+ passo.second] =1;
                pilha.push({get<0>(atual)+passo.first,get<1>(atual)+ passo.second,get<2>(atual)+1});
            }   
        }

    }

    cout<<chegou<<" \n";

 

    return 0;
}

