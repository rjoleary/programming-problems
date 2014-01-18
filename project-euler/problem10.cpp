#include <cstdint>
#include <iostream>

int main()
{
    // This problem is solved with a Sieve of Eratosthenes.
    const int sieveSize = 2000000;

    // `false` elements are prime.
    bool primes[sieveSize] = {0};

    // Ignore even primes greater than 2.
    std::int64_t sum = 2;
    for (int i = 3; i < sieveSize; i += 2)
    {
        if (primes[i] == false)
        {
            sum += i;
            for (int j = i; j < sieveSize; j += i)
                primes[j] = true;
        }
    }

    std::cout << sum << '\n';
}
