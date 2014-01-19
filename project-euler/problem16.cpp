#include <cassert>
#include <iostream>
#include <numeric>

int main()
{
    const int power = 1000;
    const int digitCount = 400;

    char digits[digitCount] = {0};
    digits[0] = 2;

    // Continuously add the number in `digits` to self `power` times.
    for (int i = 1; i < power; i++)
    {
        for (int j = digitCount - 1; j >= 0; j--)
        {
            // If a digit is greater than 5, 1 gets carried.
            if (digits[j] >= 5)
            {
                digits[j] -= 5;
                // Detect an overflow.
                assert(j != digitCount - 1);
                digits[j+1] += 1;
            }
            digits[j] *= 2;
        }
    }

    // Sum the digits.
    std::cout << std::accumulate(digits, digits + digitCount, 0) << '\n';
}

