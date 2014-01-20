#include <iostream>

int main()
{
    unsigned sum = 1, i = 1, inc = 2;
    while (i < 1001 * 1001)
    {
        sum += i + inc;
        sum += i + 2 * inc;
        sum += i + 3 * inc;
        sum += i + 4 * inc;
        i += inc * 4;
        inc += 2;
    }
    std::cout << sum << '\n';
}
