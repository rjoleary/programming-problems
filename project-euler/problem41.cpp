#include <algorithm>
#include <iostream>

// Return true if n is prime.
bool isPrime(int n);

int main()
{
    int set[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int len = 9; len >= 1; len--)
    {
        do
        {
            int n = 0;
            for (int i = len - 1, j = 1; i >= 0; i--, j *= 10)
                n += (len + 1 - set[i]) * j;
            if (isPrime(n))
            {
                std::cout << n << '\n';
                return 0;
            }
        }
        while (std::next_permutation(set, set + len));
    }
}

bool isPrime(int n)
{
    for (int m = 2; m * m <= n; m++)
        if (n % m == 0)
            return false;
    return true;
}
