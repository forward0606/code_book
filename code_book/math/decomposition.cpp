// Pollard-Rho algorithm
// O(N^(1/4))
// https://iter01.com/550538.html
// do factorize decomposition

vector<long long> ans;// mutiply all number in ans is n and all number in ans is prime
// remeber to initialize ans

long long mul(long long a, long long b, long long mod){// fast mutiply
    // try not to overflow when doing: long long * long long % long long
	long long sum = 0;
	a %= mod, b %= mod;
	while(b > 0){
		if(b & 1){
			sum = (sum + a) % mod;
		}
		a = (a + a) % mod;
		b /= 2;
	}
	return sum;
}

long long f(long long x, long long c, long long mod){
	return (mul(x, x, mod) + c) % mod;
}

void factor(long long n){
	if(is_prime(n)){
		ans.push_back(n);
		return;
	}
	long long c, x, y, d = 1;
	y = x = rand() % n;
	while(d == 1 or d == n){
		c = rand() % n;
		d = __gcd(c, n);
		if(d != 1 and d != n){break;}
		bool first = true;
		while(x != y or first){
			x = f(x, c, n);
			y = f(f(y, c, n), c, n);
			d = __gcd(abs(x - y), n);
			if(d != 1 and d != n){
				break;
			}
			if(x == y){d = __gcd(x, n);}
			first = false;
		}
	}
	factor(d), factor(n/d);
}
