#include <bits/stdc++.h>
#include "ponto.cpp"
using namespace std;

// Retorna se o ponto p esta dentro, fora ou na circunferencia de centro c e raio r
int insideCircle(const point_i &p, const point_i &c, int r) {
    int dx = p.x-c.x, dy = p.y-c.y;
    int Euc = dx*dx + dy*dy, rSq = r*r; // all integer
    return Euc < rSq ? 1 : (Euc == rSq ? 0 : -1); // in/border/out
}

// Determina o centro e raio de um circulo que passa por 3 pontos
bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x-p2.x) * (p1.x-p2.x) + 
              (p1.y-p2.y) * (p1.y-p2.y);
  double det = r*r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x+p2.x) * 0.5 + (p1.y-p2.y) * h;
  c.y = (p1.y+p2.y) * 0.5 + (p2.x-p1.x) * h;
  return true;
}