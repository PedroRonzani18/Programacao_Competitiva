#include <bits/stdc++.h>
using namespace std;

const int MAX_gm = 30; // up to 20 garments at most and 20 models/garment
const int MAX_M = 210; // maximum budget is 200

int M, C, price[MAX_gm][MAX_gm]; // price[g (<= 20)][k (<= 20)]
int memo[MAX_gm][MAX_M];         // TOP-DOWN: dp table [g (< 20)][money (<= 200)]

int dp(int g, int money) {
    
    if (money < 0) return -1e9;
    if (g == C) return M - money;
    if (memo[g][money] != -1)
        return memo[g][money]; // avaliar linha g com dinheiro money (cada caso pensavel)
    int ans = -1;
    for (int k = 1; k <= price[g][0]; ++k)
        ans = max(ans, dp(g + 1, money - price[g][k]));
    return memo[g][money] = ans;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &M, &C);
        for (int g = 0; g < C; ++g)
        {
            scanf("%d", &price[g][0]); // store k in price[g][0]
            for (int k = 1; k <= price[g][0]; ++k)
                scanf("%d", &price[g][k]);
        }
        memset(memo, -1, sizeof memo); // TOP-DOWN: init memo
        if (dp(0, M) < 0)
            printf("no solution\n"); // start the top-down DP
        else
            printf("%d\n", dp(0, M));
    }
    return 0;
}