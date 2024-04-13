#include <bits/stdc++.h>
using namespace std;
const int EPS = 1e-9;
// Ponto 2D
struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

// Ponto 2D com precisao
struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (const point &other) const { 
        return (fabs(x-other.x) < EPS) and (fabs(y-other.y) < EPS); 
    }
};

// Distancia entre 2 pontos
double dist(const point &p1, const point &p2) { 
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

double DEG_to_RAD(double d) { return d*M_PI / 180.0; }
double RAD_to_DEG(double r) { return r*180.0 / M_PI; }

// Rotaciona o ponto p em theta graus em sentido anti-horario em relacao a origem (0, 0)
point rotate(const point &p, double theta) { 
    double rad = DEG_to_RAD(theta); 
    return point(p.x*cos(rad) - p.y*sin(rad),
                 p.x*sin(rad) + p.y*cos(rad));
}