// Maximum Sum
// O(n^3) 1D DP + greedy (Kadane's) solution, 0.000s in UVa

#include <bits/stdc++.h>
using namespace std;

#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define MAX_n 110

int A[MAX_n][MAX_n];

int maxMatrixSum(vector<vector<int>> mat) {

    int n = mat.size();
    int m = mat[0].size();

    f(i,0,n) {
        f(j,0,m) {
            if (j > 0)
                mat[i][j] += mat[i][j - 1]; 
        }
    }

    int maxSum = INT_MIN;
    f(l,0,m)  {
        f(r,l,m) {
            vector<int> sum(n, 0);
            f(row,0,n) {
                sum[row] = mat[row][r] - (l > 0 ? mat[row][l - 1] : 0);
            }
            int maxSubRect = sum[0];
            f(i,1,n) {
                if (sum[i - 1] > 0)
                    sum[i] += sum[i - 1];
                maxSubRect = max(maxSubRect, sum[i]);
            }
            maxSum = max(maxSum, maxSubRect);
        }
    }

    return maxSum;
}


