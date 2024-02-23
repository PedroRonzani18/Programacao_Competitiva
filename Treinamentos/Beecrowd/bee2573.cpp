#include<bits/stdc++.h>

using namespace std;

int main(){
    int luan, lari, l, a, xa, ya, xb, yb, tot, distLuan, distLari;

	cin >> l >> a >> xa >> ya >> xb >> yb;	

    luan = lari = tot = 0;

    if(xa == xb && ya == yb){
		cout << "0.500000 0.500000" << endl;
        return 0;
    }

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= l; j++){
            distLuan = ((j - xa) * (j - xa)) + ((i - ya) * (i - ya));
            distLari = ((j - xb) * (j - xb)) + ((i - yb) * (i - yb));

            if(distLuan < distLari){
                luan++; tot++;
            }else if(distLuan > distLari){
                lari++; tot++;
            }
        }
    }

	cout << fixed << setprecision(6);
	cout << (double)luan / tot << " " << (double)lari / tot << endl;

    return 0;
}