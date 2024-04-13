#include <bits/stdc++.h>
#include "vetor.cpp"
#include "linha.cpp"

using namespace std;

// Condicao Existencia
bool existeTriangulo(double a, double b, double c) {
  return (a+b > c) && (a+c > b) && (b+c > a);
}

// Area de um triangulo de lados a, b e c
int area(int a, int b, int c) {
    if (!existeTriangulo(a, b, c)) return 0;
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca;
}

double perimeter(point a, point b, point c) {
    return dist(a, b) + dist(b, c) + dist(c, a);
}

// ====== CIRCULO INSCRITO ======

// Retorna raio de um circulo inscrito em um triangulo de lados a, b e c
double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}
double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// Calcula o centro e o raio do circulo inscrito em um triangulo dados seus pontos
bool inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return false; 
    line l1, l2; 
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1+ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1+ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr);
    return true;
}

// ====== CIRCULO CIRCUNSCRITO ======

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}