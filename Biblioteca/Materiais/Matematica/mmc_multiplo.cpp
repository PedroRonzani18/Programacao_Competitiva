int mmc(vector<int> arr) {
   int result = arr[0];
   for(size_t i = 1; i < arr.size(); i++)
       result = (arr[i] * result / mmc_util(arr[i], result ));
   return ans;
}
