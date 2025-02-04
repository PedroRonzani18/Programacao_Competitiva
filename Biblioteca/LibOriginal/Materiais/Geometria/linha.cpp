#include <bits/stdc++.h>
#include "ponto.cpp"
using namespace std;

// const int EPS = 1e-9;

struct line { double a, b, c; }; // ax + by + c = 0

// Gera a equacao da reta que passa por 2 pontos
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x-p2.x) < EPS)
        l = {1.0, 0.0, -p1.x};
    else {
        double a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
        l = {a, 1.0, -(double)(a*p1.x) - p1.y};
    }
}

// Gera a equacao da reta que passa por um ponto e tem inclinacao m
void pointSlopeToLine(point p, double m, line &l) { // m < Inf
    l = {m, 1.0, -((m * p.x) + p.y)};
}

// Checa se 2 retas sao paralelas
bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) and (fabs(l1.b-l2.b) < EPS);
}

// Checa se 2 retas sao iguais
bool areSame(line l1, line l2) { 
    return areParallel(l1, l2) and (fabs(l1.c-l2.c) < EPS);
}

// Retorna se 2 retas se intersectam e o ponto de interseccao (referencia)
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else                  p.y = -(l2.a*p.x + l2.c);
    return true;
}