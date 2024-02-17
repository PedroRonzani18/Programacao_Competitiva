#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)  for(auto x : a) cout << x.F << " " << x.S << endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b   // Arredonda para cima
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n) // Trunca n casas
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n) // Arreddonda n c 

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f; // 0x7f com 3 3f's (10^9)
const int LINF = 0x3f3f3f3f3f3f3f3f; // 0x com 7 3f's (10^18)
const int MAX = 1e6+10; // 10^6 + 10

vector<string> split(string s, string del = " ") {
   vector<string> retorno;
   int start, end = -1*del.size();
   do {
       start = end + del.size();
       end = s.find(del, start);
       retorno.push_back(s.substr(start, end - start));
   } while (end != -1);
   return retorno;
}

unordered_map<string, int> m;

int binary_to_decimal(string binary) {
    int dec = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        int bit = binary[i] - '0';
        dec += bit * pow(2, power);
        power++;
    }
    return dec;
}

string decimal_to_binary(int dec, int casas) {
    string binary = "";
    while (dec > 0) {
        int bit = dec % 2;
        binary = to_string(bit) + binary;
        dec /= 2;
    }

	while(binary.size() < casas) {
		binary = "0" + binary;
	}

	reverse(all(binary));
	m[binary] = dec;

	return binary;
}

bool cmp(string s1, string s2) {
	int c1 = count(all(s1), '1');
	int c2 = count(all(s2), '1');
	if(c1 != c2) return c1 < c2;
	return m[s1] < m[s2];
}

void solve() {

	string s; getline(cin, s);
	vector<string> v = split(s,",");
	vector<string> binarios(pow(2,v.size())-1);

	for(int i=1; i<=binarios.size(); i++) {
		binarios[i-1] = decimal_to_binary(i, v.size());
	}

	sort(all(binarios), cmp);

	for(string bin : binarios) {
		string aux = "";
		for(int i=0; i<bin.size(); i++) {
			if(bin[i] == '1') {
				aux += v[i] + ",";
			}
		}
		if(aux.size() > 0) {
			aux.pop_back();
			cout << aux << endl;
		}
	}
}

int32_t main() { _
	
	solve();

	return 0;
}
