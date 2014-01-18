#include <iostream>

int main()
{
    // This is pretty much a brute-force solution.
    for (int a = 1; a < 1000; a++)
    {
        for (int b = a + 1; b < 1000; b++)
        {
            // Confirm that `a + b + c == 1000`.
            int c = 1000 - a - b;
            if (c < 1)
                break;

            if (a * a + b * b == c * c)
            {
                std::cout << a * b * c << '\n';
                return 0;
            }
        }
    }

    // If the triplet exists, the execution should never reach here.
    return 1;
}
