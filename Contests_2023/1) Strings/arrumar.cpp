#include <bits/stdc++.h>

using namespace std;


int main(){

ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string frase;
    bool palindromo = true;

    cin >> frase;


    int size = frase.length();

    for(int i = 0; i < size / 2; i++) {
        if(frase[i] != frase[size - 1 - i]) {
            palindromo = false;
            break;
        }
    }

    if(palindromo) {
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }

}