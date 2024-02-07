// Descricao: Conta quantos subarrays de um vetor tem soma igual a k
// Complexidade: O(n)
int contarSomaSubarray(vector<int>& v, int k) {
    unordered_map<int, int> prevSum; // map to store the previous sum
 
    int ret = 0, currentSum = 0;
 
	for(int& num : v) {
        currentSum += num;
 
        if (currentSum == k) ret++; /// Se a soma atual for igual a k, encontramos um subarray
 
        if (prevSum.find(currentSum - k) != prevSum.end()) // se subarray com soma (currentSum - k) existir, sabe que [0:n] eh um subarray com soma k
            ret += (prevSum[currentSum - k]);
 
        prevSum[currentSum]++;
    }
 
    return ret;
}