// calcula mmc de varios numeros passados em um array, recomendado para n > 2

int mmc_many(vector<int> arr) {
   int result = arr[0];
   
   for(int& num : arr)
       result = (num * result / mmc(num, result ));
   return ans;
}
