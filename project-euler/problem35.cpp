#include <iostream>
#include <vector>

int main()
{
    // Generate a sieve of prime numbers.
    std::vector<bool> sieve(500000, true);
    for (unsigned i = 3; i < 1000000; i += 2)
        if (sieve[i/2])
            for (unsigned j = i * 2; j < 1000000; j += i)
                if (j % 2 == 1)
                    sieve[j/2] = false;

    int sum = 1;
    for (unsigned i = 3; i < 1000000; i += 2)
    {
        if (sieve[i/2])
        {
            unsigned length = 0;
            unsigned factor = 1;
            for (unsigned j = i; j > 0; j /= 10)
            {
                length++;
                factor *= 10;
            }
            bool isPrime = true;
            for (unsigned j = 0; j < length; ++j)
            {
                i += i % 10 * factor;
                i /= 10;
                if (i % 2 == 0 || !sieve[i/2])
                    isPrime = false;
                if (i % 2 == 1 && isPrime == false)
                    sieve[i/2] = false;
            }
            if(isPrime)
                sum++;
        }
    }

    std::cout << sum << '\n';
}
