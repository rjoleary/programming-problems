#include <iostream>
#include <cmath>

// Returns true if prime.
bool isPrime(int);

int main()
{
    // This is a very inefficient algorithm.
    int n = 3;
    for (int primes = 2; primes < 10001;)
        if (isPrime(n += 2))
            primes++;

    std::cout << n << '\n';
}

bool isPrime(int x)
{
    // `x == 2` is the only even prime.
    if (x == 2)
        return true;
    // Test divisibility by all odd factors below `sqrt(x)`.
    for (int f = 3; f <= x / f; f += 2)
        if (x % f == 0)
            return false;
    return true;
}
