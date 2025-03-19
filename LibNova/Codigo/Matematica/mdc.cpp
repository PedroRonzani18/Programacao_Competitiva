// MDC e MMC
//
// O(log n)

// MDC entre 2 numeros
int mdc(int a, int b) {
    for (int r = a % b; r; a = b, b = r, r = a % b);
    return b;
}

// MDC entre N numeros
int mdc_many(vector<int> arr) {
   int result = arr[0];

   for (int& num : arr) {
       result = mdc(num, result);

       if(result == 1) return 1;
   }
   return result;
}

// MMC entre 2 numeros
int mmc(int a, int b) {
    return a / mdc(a, b) * b;
}

// MMC entre N numeros
int mmc_many(vector<int> arr) {
    int result = arr[0];

    for (int &num : arr)
        result = (num * result / mdc(num, result));
    return result;
}
