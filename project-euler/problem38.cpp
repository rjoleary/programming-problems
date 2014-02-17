#include <algorithm>
#include <functional>
#include <iostream>

// Return the number of digits in the interger.
int length(int);
// Return the true if the pandigital number is valid.
bool isvalid(const int pandigital[]);

int main()
{
    int pandigital[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    while (!isvalid(pandigital))
        next_permutation(pandigital, pandigital + 9, std::greater<int>());

    std::cout << pandigital[0] << pandigital[1] << pandigital[2]
              << pandigital[3] << pandigital[4] << pandigital[5]
              << pandigital[6] << pandigital[7] << pandigital[8] << '\n';
}

int length(int p)
{
    int e = 0;
    while (p > 0)
    {
        e++;
        p /= 10;
    }
    return e;
}

bool isvalid(const int pandigital[])
{
    for (int i = 1; i <= 4; ++ i)
    {
        bool isPandigital = true;

        // convert the first i digits into an int
        int n = 0;
        for (int j = 0; j < i; ++j)
        {
            n *= 10;
            n += pandigital[j];
        }

        // repeat n through the pandigital while multiplying by 2, 3, ...
        int r = i;
        int f = 1;
        while (r < 9)
        {
            f++;
            int m = f * n;
            int mLength = length(m);

            if (r + mLength > 9)
            {
                isPandigital = false;
                break;
            }

            // compare f * n to the pandigital
            int actualM[9];
            std::reverse_copy(pandigital + r, pandigital + r + mLength, actualM);
            for (int j = 0; j < mLength; ++j)
            {
                if (actualM[j] != m % 10)
                    isPandigital = false;
                m /= 10;
            }

            r += mLength;
        }

        if (isPandigital == true)
            return true;
    }
    return false;
}
