#include <bits/stdc++.h>
#include "ponto.cpp"
using namespace std;

struct vec { 
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

    double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); } 
    double norm_sq(vec v) { return v.x*v.x + v.y*v.y; } 
    double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

// Converte 2 pontos em um vetor
vec toVec(const point &a, const point &b) { 
    return vec(b.x-a.x, b.y-a.y); 
}

// Soma 2 vetores
vec scale(const vec &v, double s) { 
    return vec(v.x*s, v.y*s);
} 
// Resultado do ponto p + vetor v
point translate(const point &p, const vec &v) { 
    return point(p.x+v.x, p.y+v.y);
}

// Angulo entre 2 vetores (produto escalar) em radianos
double angle(const point &a, const point &o, const point &b) {
    vec oa = toVec(o, a), ob = toVec(o, b); 
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// Retorna se o ponto r esta a esquerda da linha pq (counter-clockwise)
bool ccw(point p, point q, point r) {
return cross(toVec(p, q), toVec(p, r)) > EPS;
}

// Retorna se sao colineares
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// Distancia ponto-linha
double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); 
    return dist(p, c); 
}

// Distancia ponto p - segmento ab
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { // closer to a
        c = point(a.x, a.y);
        return dist(p, a); // dist p to a
    }
    if (u > 1.0) { // closer to b
        c = point(b.x, b.y);
        return dist(p, b); // dist p to b
    }
    return distToLine(p, a, b, c); // use distToLine
}