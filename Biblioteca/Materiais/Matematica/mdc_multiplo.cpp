// Description: Calcula o MDC de um vetor de inteiros.
// Complexidade: O(nlogn) onde n eh o tamanho do vetor
int mdc_many(vector<int> arr) {
   int result = arr[0];

   for (int& num : arr) {
       result = mdc(num, result);
  
       if(result == 1) return 1;
   }
   return result;
}
