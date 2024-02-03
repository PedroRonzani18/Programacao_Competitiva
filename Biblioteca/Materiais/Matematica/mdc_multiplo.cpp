// Calcula o mdc de varios numeros, ideal ser utilizado para n > 2

int mdc_many(vector<int> arr) {
   int result = arr[0];

   for (int& num : arr) {
       result = mdc(num, result);
  
       if(result == 1) return 1;
   }
   return result;
}
