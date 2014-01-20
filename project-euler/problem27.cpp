#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> generatePrimes(int maxPrime);

int main()
{
    auto primes = generatePrimes(10000);
    int maxN = 0;
    int maxMul = 0;
    for (int a = -999; a < 999; a++)
    {
        // b must be prime
        for (int bi = 0; primes[bi] < 999; bi++)
        {
            int n = 0;
            while (std::binary_search(primes.begin(), primes.end(),
                n * n + a * n + primes[bi])) n++;
            if (n > maxN)
            {
                maxN = n;
                maxMul = a * primes[bi];
            }
        }
    }
    std::cout << maxMul << '\n';
}

std::vector<int> generatePrimes(int maxPrime)
{
    std::vector<bool> sieve(maxPrime + 1, true);
    std::vector<int> primes = {2};
    for (int i = 3; i <= maxPrime; i += 2)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= maxPrime; j += i)
                sieve[j] = false;
        }
    }
    return primes;
}
