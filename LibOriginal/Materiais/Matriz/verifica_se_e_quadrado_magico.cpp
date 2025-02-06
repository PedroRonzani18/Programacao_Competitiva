// Description: Verifica se uma matriz é um quadrado mágico.
// Complexidade: O(n^2)

int isMagicSquare(vector<vi> mat, int n) {
    int i=0,j=0;
    int sumd1 = 0, sumd2=0;
	f(i,0,n) {
        sumd1 += mat[i][i];
        sumd2 += mat[i][n-1-i];
    }
    if(sumd1!=sumd2) return 0;

	int ans = 0;
 
	f(i,0,n) {
        int rowSum = 0, colSum = 0;    
		f(j,0,n) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        if (rowSum != colSum || colSum != sumd1) return 0;
		ans = rowSum;
    }
	return ans;
}