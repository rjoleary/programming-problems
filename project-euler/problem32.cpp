#include <array>
#include <iostream>
#include <numeric>
#include <set>

// Returns the length of an integer.
int len(int a);
// Returns true is the concatenation of `a+b+c` is pandigital.
bool isPandigital(int a, int b, int c);

int main()
{
    std::set<int> products;

    for (int a = 1; a <= 9876; a++)
    {
        for (int b = a; b <= 9876; b++)
        {
            int l = len(a) + len(b) + len(a * b);
            if (l > 9)
                break;
            if (l == 9 && isPandigital(a, b, a * b))
                products.insert(a * b);
        }
    }

    std::cout << std::accumulate(products.begin(), products.end(), 0) << '\n';
}

int len(int a)
{
    int sum = 0;
    while (a)
    {
        sum++;
        a /= 10;
    }
    return sum;
}

bool isPandigital(int a, int b, int c)
{
    // element n in digits represents existance of digit n
    std::array<char,10> digits{};
    while (a)
    {
        digits[a%10]++;
        a /= 10;
    }
    while (b)
    {
        digits[b%10]++;
        b /= 10;
    }
    while (c)
    {
        digits[c%10]++;
        c /= 10;
    }
    // Check that there is one of each digit 1 through 9.
    if (digits[0] != 0)
        return false;
    for (int i = 1; i < 10; i++)
        if (digits[i] != 1)
            return false;
    return true;
}

