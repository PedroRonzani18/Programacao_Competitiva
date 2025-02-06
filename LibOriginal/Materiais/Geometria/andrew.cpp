// Nome: Convex Hull - Andrew's Monotone Chain
// Description: Calcula o perimetro do menor poligono convexo que contem todos os pontos
// Complexidade: O(n logn)

int produto_vetoril(pair<int,int> a,pair<int,int> b,pair<int,int> novo){
    return (b.first - a.first)*(novo.second-b.second) -(b.second - a.second)*(novo.first - b.first);
}
double distancia(pair<int,int> a,pair<int,int> b){
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

double andrew(pair<int,int> pontos[], int n) {

	vector<pair<int,int>> hull;

	pair<int,int> ponto;
	int k=0;
	f(i,0,n) {

		while(k>=2 and produto_vetoril(hull[k-2],hull[k-1],pontos[i]) <= 0) {
			hull.pop_back();
			k--;
		}
		hull.push_back(pontos[i]);
		k++;
	}

	for(int i=n-1, tam = k+1 ; i>=0 ; i--) {
		while(k>=tam && produto_vetoril(hull[k-2],hull[k-1],pontos[i])<=0){
			hull.pop_back();
			k--;
		}   
		hull.push_back(pontos[i]);
		k++;
	}

	double perimetro = 0;

	f(i,1,hull.size()) {
		perimetro += distancia(hull[i-1],hull[i]);
	}

	return perimetro;
}

void solve() {

    int n; scanf("%lld",&n);
	pair<int,int> pontos[n];

	for(auto& [x, y] : pontos) 
		scanf("%lld %lld",&x,&y);

	sort(pontos,pontos+n); 
 
	double perimetro = andrew(pontos,n);
}