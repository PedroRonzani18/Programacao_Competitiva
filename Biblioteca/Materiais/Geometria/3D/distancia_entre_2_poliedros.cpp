// Description: Calcula a menor distancia entre dois poliedros convexos
// Complexidade: O(n^2 * m^2), onde n e m sao o numero de vertices dos poliedros
// OBS: apenas testado para tetraedros

const double EPS = 1e-9;
const double INF = 1e50;

int cmpD(double a, double b = 0.0) { return a+EPS < b ? -1 : a-EPS > b; }

struct Point {
	double x, y, z;
	Point(double a=0.0,double b=0.0,double c=0.0){x=a,y=b,z=c;}
	Point operator+(const Point &P) const {return Point(x+P.x,y+P.y,z+P.z);}
	Point operator-(const Point &P) const {return Point(x-P.x,y-P.y,z-P.z);}
	Point operator*(double c) const {return Point(x*c,y*c,z*c);}
	Point operator/(double c) const {return Point(x/c,y/c,z/c);}
	double operator!() const {return sqrt(x*x+y*y+z*z);} // modulo
};

double produtoEscalar(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }

Point produtoVetorial(Point A, Point B) { return Point(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x); }

Point projWEmV(Point W, Point V) { return V * produtoEscalar(W,V) / produtoEscalar(V,V); }

// check if segments AB and CD have an intersection
bool checkIfSegmentsIntercept(Point A, Point B, Point C, Point D) {
	return cmpD(produtoEscalar(produtoVetorial(A-B,C-B),produtoVetorial(A-B,D-B))) <= 0 &&
	cmpD(produtoEscalar(produtoVetorial(C-D,A-D),produtoVetorial(C-D,B-D))) <= 0;
}

// distance between point P and segment AB
double dist_Point_seg(Point P, Point A, Point B) {
	Point PP = A + projWEmV(P-A,B-A);
	if (cmpD(!(A-PP)+!(PP-B),!(A-B)) == 0) return !(P-PP);//distance Point-line!
	return min(!(P-A),!(P-B));
}

// distance between segments AB and CD
double dist_seg_seg(Point A, Point B, Point C, Point D) {
	Point E = projWEmV(A-D,produtoVetorial(B-A,D-C)); 
	if (checkIfSegmentsIntercept(A,B,C+E,D+E)) return !E;
	return min( min( dist_Point_seg(A,C,D), dist_Point_seg(B,C,D) ),
	min( dist_Point_seg(C,A,B), dist_Point_seg(D,A,B) ) );
}

// distance between point P and triangle ABC
double dist_Point_tri(Point P, Point A, Point B, Point C) {
	Point N = produtoVetorial(A-C,B-C);
	Point PP = P + projWEmV(C-P,N);
	Point V1 = produtoVetorial(PP-A,B-A);
	Point V2 = produtoVetorial(PP-B,C-B);
	Point V3 = produtoVetorial(PP-C,A-C);
	if (cmpD(produtoEscalar(V1,V2)) >= 0 && cmpD(produtoEscalar(V1,V3)) >= 0 && cmpD(produtoEscalar(V2,V3)) >= 0)
	return !(PP-P); // distance Point-plane!
	return min(dist_Point_seg(P,A,B),min(dist_Point_seg(P,A,C),dist_Point_seg(P,B,C)));
}

// Calcula a menor distancia entre dois poliedros
// Complexidade: O(sz1^2 * sz2^2), onde sz1 e sz2 sao o numero de vertices dos poliedros
double distanciaPoliedroPoliedro(Point T1[], int sz1, Point T2[], int sz2) {
	
	double ans = INF;

	// itera por todos os pares de arestas dos dois tetraedros, e calcula a distancia entre os segmentos gerados por estes pares
	for (int i=0; i < sz1; i++) // arestas -> arestas
		for (int j=i+1; j < sz1; j++)
			for (int ii=0; ii < sz2; ii++)
				for (int jj=ii+1; jj < sz2; jj++)
					ans = min( ans, dist_seg_seg(T1[i],T1[j],T2[ii],T2[jj]) );

	// itera por todos os pontos de um tetraedro e calcula a distancia entre estes pontos e as faces triangulares do outro tetraedro
	for (int i=0; i < sz1; i++)
		for (int j=i+1; j < sz1; j++)
			for (int k=j+1; k < sz1; k++)
				for (int x=0; x < sz2; x++)
					ans = min( ans, dist_Point_tri(T1[x],T2[i],T2[j],T2[k]) ),
					ans = min( ans, dist_Point_tri(T2[x],T1[i],T1[j],T1[k]) );
	return ans;
}

void solve() {
	Point poliedro1[5], poliedro2[5];

	f(i,0,4) { auto& [x,y,z] = poliedro1[i]; scanf("%lf %lf %lf", &x, &y, &z); }
	f(i,0,4) { auto& [x,y,z] = poliedro2[i]; scanf("%lf %lf %lf", &x, &y, &z); }

	printf("%.2lf\n",distanciaPoliedroPoliedro(poliedro1, 4, poliedro2, 4));
}
