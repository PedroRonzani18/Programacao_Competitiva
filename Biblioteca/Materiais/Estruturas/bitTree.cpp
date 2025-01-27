#include <bits/stdc++.h>
using namespace std;

/*		 n --> No. of elements present in input array. 
	BITree[0..n] --> Array that represents Binary Indexed Tree. 
	arr[0..n-1] --> Input array for which prefix sum is evaluated. */

// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
int getSum(vector<int>& BITree, int index) { 
	int sum = 0;
	index = index + 1; 
	while (index>0) { 
		sum += BITree[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateBIT(vector<int>& BITree, int n, int index, int val) { 
	index = index + 1; 

	while (index <= n) { 
		BITree[index] += val; 
		index += index & (-index); 
	} 
} 

vector<int> constructBITree(vector<int>& arr, int n) { 
	vector<int> BITree(n+1, 0); 

	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 

	return BITree; 
} 

void solve() { 
	vector<int> freq = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = freq.size(); 
	vector<int> BITree = constructBITree(freq, n); 
	cout << "Sum of elements in arr[0..5] is"<< getSum(BITree, 5); 
	// Let use test the update operation 
	freq[3] += 6; 
	updateBIT(BITree, n, 3, 6); // BIT[4] = 6

	cout << "\nSum of elements in arr[0..5] after update is "
		<< getSum(BITree, 5); 
}

int main() {
	solve();
	return 0;
}
