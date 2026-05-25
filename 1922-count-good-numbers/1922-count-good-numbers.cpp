class Solution {
public:
    // a ^ b % p
    long long power(long long a, long long b, int p) {
        long long res = 1;

        while(b != 0) {
            if(b % 2 == 1)
                res = (res * a) % p;
            
            a = (a * a) % p;
            b /= 2;
        }

        return res;
    }   

    int countGoodNumbers(long long n) {
        int primes = 4;
        int evens = 5;
        int p = 1e9 + 7;

        return (power(evens, (n + 1) / 2, p) * power(primes, n / 2, p)) % p;
    }
};