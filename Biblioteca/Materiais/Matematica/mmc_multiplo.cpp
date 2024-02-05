// Description: Calcula o mmc de um vetor de inteiros.
// Complexidade: O(nlogn) onde n eh o tamanho do vetor
int mmc_many(vector<int> arr) {
   int result = arr[0];
   
   for(int& num : arr)
       result = (num * result / mmc(num, result ));
   return ans;
}
