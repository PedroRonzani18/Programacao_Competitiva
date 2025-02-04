// Description: Gera todos os primos do intervalo [1,lim]
// Complexidade: O(n log log n)

int _sieve_size;
bitset<10000010> bs;
vi p;

void sieve(int lim) {
    _sieve_size = lim+1;
    bs.set();
    bs[0] = bs[1] = 0;
    f(i,2,_sieve_size) { 
        if (bs[i]) {
            for (int j = i*i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);
        }
    }
}