#include <iostream>
#include <vector>

int main()
{
    const int range = 10000;
    std::vector<bool> primeSieve(range, 0);
    for (int n = 2; n * n < range; n++)
        if (!primeSieve[n])
            for (int m = 2 * n; m < range; m += n)
                primeSieve[m] = true;

    std::vector<bool> goldbachSieve(range, 0);
    for (int n = 2; n < range; n++)
    {
        if (!primeSieve[n])
        {
            for (int m = 1; n + 2 * m * m < range; m++)
                goldbachSieve[n+2*m*m] = true;
        }
        if (n % 2 == 1 && !goldbachSieve[n] && primeSieve[n])
        {
            std::cout << n << '\n';
            return 0;
        }
    }
}
