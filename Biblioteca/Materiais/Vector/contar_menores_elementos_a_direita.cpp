// Description: Conta quantos elementos menores que o elemento atual existem a direita do mesmo.
// Complexity: O(nlogn)

const int MAX = 100010; // Tamanho maximo do array de entrada

int ansArr[MAX]; // Array que armazena a resposta

void merge(pair<int, int> a[], int start, int mid, int end) {
	pair<int, int> f[mid - start + 1], s[end - mid];
					
	int n = mid - start + 1;
	int m = end - mid;
	
	for(int i = start; i <= mid; i++)
		f[i - start] = a[i];
	for(int i = mid + 1; i <= end; i++)
		s[i - mid - 1] = a[i];
		
	int i = 0, j = 0, k = start;
	int cnt = 0;

	while(i < n and j < m) {
		if (f[i].second <= s[j].second) {
			ansArr[f[i].first] += cnt;
			a[k++] = f[i++];
		} else {
			cnt++;
			a[k++] = s[j++];
		}
	}

	while(i < n) {
		ansArr[f[i].first] += cnt;
		a[k++] = f[i++];
	}

	while(j < m) {
		a[k++] = s[j++];
	}
}

void mergesort(pair<int, int> item[], int low, int high) {
	if (low >= high) return;
		
	int mid = (low + high) / 2;
	mergesort(item, low, mid);
	mergesort(item, mid + 1, high);
	merge(item, low, mid, high);
}

void solve() {
	int n; cin >> n;
	int arr[n];
	f(i,0,n) { cin >> arr[i]; }
					
	pair<int, int> a[n];
	memset(ansArr, 0, sizeof(ansArr));
	
	f(i,0,n) {
		a[i].second = arr[i];
		a[i].first = i;
	}
	
	mergesort(a, 0, n - 1);

	int ans = 0; 
	f(i,0,n) { ans += ansArr[i]; }
	cout << ans << endl;
}