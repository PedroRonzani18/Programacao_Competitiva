int mdc_many(vector<int> arr) {
   int result = arr[0];
   for (size_t i = 1; i < arr.size(); i++) {
       result = mdc(arr[i], result);
  
       if(result == 1)
           return 1;
   }
   return result;
}
