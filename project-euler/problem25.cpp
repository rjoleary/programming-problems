#include <algorithm>
#include <iostream>

int main()
{
    // The solution basically implements arbitrary length integers.
    const int length = 1000;
    char a[length] = {1}, b[length] = {1};
    unsigned term = 2;
    while (b[length-1] == 0)
    {
        // c = a + b
        char c[length] = {0};
        for (int i = 0; i < length - 1; i++)
        {
            // add
            c[i] += a[i] + b[i];

            // carry
            c[i+1] = c[i] / 10;
            c[i] %= 10;
        }

        std::copy(b, b + length, a);
        std::copy(c, c + length, b);

        term++;
    }

    std::cout << term << '\n';
}
