#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi 			   vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)
#define CEIL(a, b)     ((a) + (b - 1))/b
#define TRUNC(x) 	   floor(x * 100) / 100

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6+10; // 10^6 + 10

void solve(int& p, int& a, int& r) {

    unordered_set<string> perolas;

    set<string> ans;
    int maximum = -1;

    f(i,0,p) {

        string per; getline(cin, per); perolas.insert(per);
    }

    f(i,0,a) {

        string aluno; getline(cin, aluno);

        int curr = 0;

        f(j,0,r) {

            string resposta; getline(cin, resposta);

            int respostaIn = perolas.count(resposta);
            
            curr += respostaIn;
        }

        if(curr > maximum) {

            ans = set<string>();
            ans.insert(aluno);
            maximum = curr;

        } else if (curr == maximum) {

            ans.insert(aluno);

        }
    }

    if(!ans.empty()) {
        cout << *ans.begin();

        ans.erase(*ans.begin());

        for(string s : ans) {
        	cout << ", " << s;
        }
    }
    
    // Remove the extra endl
    // cout << endl;
    
}

int32_t main() { _
    
    int p, a, r;

    while (cin >> p >> a >> r) {
        cin.ignore();
        if(p == a and a == r and r == 0) break;
        solve(p,a,r);
        cout << endl;
    } 
    //while(cin >> a >> b)

    return 0;
}
