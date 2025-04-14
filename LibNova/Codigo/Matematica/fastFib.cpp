// Fast Fib
//
// O(log n)

string decimal_to_bin(int n) {
	string bin = bitset<sizeof(int) * 8>(n).to_string();
	auto loc = bin.find('1');
	// remove leading zeros
	if (loc != string::npos)
		return bin.substr(loc);
	return "0";
}

int fastfib(int n) {
	string bin_of_n = decimal_to_bin(n);

	int f[] = { 0, 1 };

	for (auto b : bin_of_n) {
		int f2i1 = f[1] * f[1] + f[0] * f[0];
		int f2i = f[0] * (2 * f[1] - f[0]);

		if (b == '0') {
			f[0] = f2i;
			f[1] = f2i1;
		} else {
			f[0] = f2i1;
			f[1] = f2i1 + f2i;
		}
	}

	return f[0];
}
