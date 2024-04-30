// Calcula area do maior retangulo em um histograma
// Complexidade: O(n)
int maxHistogramRect(const vector<int>& hist) { 
	stack<int> s; 
    int n = hist.size();

	int ans = 0, tp, area_with_top; 
	
	int i = 0; 
	while (i < n) { 
		
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 

		else { 
			tp = s.top(); s.pop(); 
			
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
			
			if (ans < area_with_top) 
				ans = area_with_top; 
		} 
	} 
	
	while (!s.empty()) { 
		tp = s.top();  s.pop(); 
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 

		if (ans < area_with_top) 
			ans = area_with_top; 
	} 

	return ans; 
} 

void solve() { 
	vector<int> hist = { 6, 2, 5, 4, 5, 1, 6 }; 
    cout << maxHistogramRect(hist) << endl;
}
