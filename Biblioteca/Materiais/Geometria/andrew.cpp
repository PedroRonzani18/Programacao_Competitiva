#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl           "\n"
/*
    algoritmo de andrew...
    pegar primeiramente os dois pontos mais a esquerda e mais a direita, sorteando eles em um vetor
    e construir a forma geometrica em 2 partes, a parte superior e a parte inferior
    parte de cima: filtrar os pontos pelo eixo x e depois y.
    adicionamos os pontos dentro do HULL, garantindo que a ultim linha não vire a esquerda.
    se virar a esquerda removemos o ponto anterior do vetor HULL..
    sendo k a quantia de pontos enseridos no poligno, na ida estabelecemos um minimo de 2 pontos
    na volta tem q ser no minimo a quantia de pontos inseridos no poligno na ida +1.
    parte de baixo:
    adicionamos os pontos dentro do hull e continuamos garantido q a ultima linha não vire a esquerda.
    se virar a esquerda removemos o ultimo ponto do hull.
*/
int produto_vetoril(pair<int,int> a,pair<int,int> b,pair<int,int> novo){
    // tenho 3 pontos, a, b e o novo // logo vetor de a->b,e b->novo;
    return (b.first - a.first)*(novo.second-b.second) -(b.second - a.second)*(novo.first - b.first);
}
double distancia(pair<int,int> a,pair<int,int> b){
    return sqrt(pow((a.first - b.first),2) + pow((a.second - b.second),2));
}

int main(){

    int entrada,c1,c2; scanf("%d",&entrada);

    while(entrada){
        int leftmost= __INT32_MAX__,righmost = 1-__INT32_MAX__ ;
        vector<pair<int,int>> pontos,hull;
        for(int x=0;x<entrada;x++){

            cin>>c1>>c2;
            pontos.push_back(make_pair(c1,c2));
            if(righmost<c1){
                righmost=c1;
            }
            if(leftmost>c1){
                leftmost=c1;
            }
        }
        //parte superior do poligno convexo
        sort(pontos.begin(),pontos.end());//sorteando by X

        pair<int,int> ponto;
        int k=0;
        for(int x=0;x<entrada;x++){
            while(k>=2 && produto_vetoril(hull[k-2],hull[k-1],pontos[x])<=0){
                hull.pop_back();
                k--;
            }
            hull.push_back(pontos[x]);
            k++;
        }
        //parte inferior do poligno convexo
        for(int x=entrada-1,tam = k+1;x>=0;x--){
            while(k>=tam && produto_vetoril(hull[k-2],hull[k-1],pontos[x])<=0){
                hull.pop_back();
                k--;
            }   
            hull.push_back(pontos[x]);
            k++;
        }

        double resposta =0;
        for(int x=1;x<hull.size();x++){
            resposta+= distancia(hull[x-1],hull[x]);
        }
        printf("Tera que comprar uma fita de tamanho %0.2lf.\n",resposta);
        scanf("%d",&entrada);
    }


    return 0;
}