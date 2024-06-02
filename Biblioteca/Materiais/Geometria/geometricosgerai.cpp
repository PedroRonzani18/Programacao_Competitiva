#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};
//checa se dado ponto esta dentro de um poligno.
//tempo O(NxM) sendo N=numero de pontos do poligno, M= a quantia de pontos que vc quer checar
bool point_in_polygon(Point point, vector<Point> polygon){
    int num_vertices = polygon.size();
    double x = point.x, y = point.y;
    bool inside = false;
    Point p1 = polygon[0], p2;
    for (int i = 1; i <= num_vertices; i++) {
        p2 = polygon[i % num_vertices];
        if (y > min(p1.y, p2.y)) {
            if (y <= max(p1.y, p2.y)) {
                if (x <= max(p1.x, p2.x)) {
                    double x_intersection
                        = (y - p1.y) * (p2.x - p1.x)
                              / (p2.y - p1.y)
                          + p1.x;
                    if (p1.x == p2.x
                        || x <= x_intersection) {
                        inside = !inside;
                    }
                }
            }
        }
        p1 = p2;
    }
    return inside;
}
//dado N pontos ordenados, encontre a area do poligno
double polygonArea(vector<pair<double,double>> vec )
{
    // Initialize area
    double area = 0.0;
    // Calculate value of shoelace formula
    int j = vec.size() - 1;
    for (int i = 0; i < vec.size(); i++)
    {
        area += (vec[j].first + vec[i].first) * (vec[j].second - vec[i].second);
        j = i;  // j is previous vertex to i
    }
    // Return absolute value
    return abs(area / 2.0);
}

//encontrar area de intersecao entre dois circulos
//(x,y)posicao do centro + raio
long long int intersectionArea(long double X1, long double Y1,
                                long double R1, long double X2,
                                long double Y2, long double R2){
    long double Pi = 3.14;
    long double d, alpha, beta, a1, a2;
    long long int ans;
 
    // Calculate the euclidean distance
    // between the two points
    d = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
 
    if (d > R1 + R2)
        ans = 0;
 
    else if (d <= (R1 - R2) && R1 >= R2)
        ans = floor(Pi * R2 * R2);
 
    else if (d <= (R2 - R1) && R2 >= R1)
        ans = floor(Pi * R1 * R1);
 
    else {
        alpha = acos((R1 * R1 + d * d - R2 * R2)
                     / (2 * R1 * d))
                * 2;
        beta = acos((R2 * R2 + d * d - R1 * R1)
                    / (2 * R2 * d))
               * 2;
        a1 = 0.5 * beta * R2 * R2
             - 0.5 * R2 * R2 * sin(beta);
        a2 = 0.5 * alpha * R1 * R1
             - 0.5 * R1 * R1 * sin(alpha);
        ans = floor(a1 + a2);
    }
 
    return ans;
}
