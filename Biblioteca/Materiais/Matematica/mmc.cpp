int mmc(int x, int y) { 
   return (x && y ? (return abs(x) / mdc(x, y) * abs(y)) : abs(x | y));
}
