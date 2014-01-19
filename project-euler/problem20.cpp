#include <iostream>
#include <numeric>

int main()
{
    // Represents the digits of an integer initialized to 1.
    char digits[200] = {1};

    for (unsigned i = 2; i <= 100; i++)
    {
        int carry = 0;
        for (unsigned j = 0; j < sizeof(digits); j++)
        {
            int digit = digits[j] * i + carry;
            carry = digit / 10;
            digits[j] = digit % 10;
        }
    }

    std::cout << std::accumulate(digits, digits + sizeof(digits), 0) << '\n';
}
