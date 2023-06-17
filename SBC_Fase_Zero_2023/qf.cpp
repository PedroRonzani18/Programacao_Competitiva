#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl

int32_t main() { _



    int t1,t2;

    vector<char> vecMain, vecbusca;

    cin >> t1 >> t2;

    for (int i=0;i<t1;i++){

        char aux;
        scanf("%c",&aux);
        vecMain.push_back(aux);
    }

    for (int i=0;i<t2;i++){

        char aux;
        scanf("%c",&aux);
        vecbusca.push_back(aux);
    }


    int qnt;
    cin >> qnt;

    for (int k=0;k<qnt;k++){

        int f, s,comb=0;

        cin >> f >> s;

        int qntCasas = (s-f)+1;


        for (int j=0;j<t1;j++){

            bool ver = false;    

            if (vecMain[j] == vecbusca[s-1]){

                for (int i=1,x=j+1 ; i<qntCasas;i++,x++){
                    if (vecMain[x] != vecbusca[i]) {
                        ver = true;
                        break;
                    }
                }
                if (ver) comb++;
            }


        }

        cout << comb << endl; 
    }


	return 0;
}

