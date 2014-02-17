#include <iostream>

// Reverse the digits in an integer.
unsigned reverse(unsigned);

int main()
{
    unsigned sum = 0;

    for (unsigned a = 1; a < 10; a += 2)
    {
        // a
        if (a == reverse(a))
            sum += a;

        // aa
        unsigned aa = a * 10 + a;
        if (aa == reverse(aa))
            sum += aa;

        for (unsigned b = 0; b < 10; ++b)
        {
            // aba
            unsigned aba = a * 100 + b * 10 + a;
            if (aba == reverse(aba))
                sum += aba;

            // abba
            unsigned abba = a * 1000 + b * 100 + b * 10 + a;
            if (abba == reverse(abba))
                sum += abba;

            for (unsigned c = 0; c < 10; ++c)
            {
                // abcba
                unsigned abcba = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
                if (abcba == reverse(abcba))
                    sum += abcba;

                // abccba
                unsigned abccba = a * 100000 + b * 10000 + c * 1000 + c * 100 + b * 10 + a;
                if (abccba == reverse(abccba))
                    sum += abccba;
            }
        }
    }

    std::cout << sum << '\n';
}

unsigned reverse(unsigned x)
{
    unsigned y = 0;
    while (x > 0)
    {
        y *= 2;
        y += x % 2;
        x /= 2;
    }
    return y;
}
