#include <cstdint>
#include <iostream>

int main()
{
    std::int64_t n = 600851475143;

    // Repeatedly divide N by a factor f until N is prime.
    for (std::int64_t f = 2; f <= n / f; f++)
        while (n % f == 0)
            n /= f;

    std::cout << n << '\n';
}

