#include <algorithm>
#include <iostream>

int main()
{
    // the swap and add implementation of the fibonacci sequence
    int sum = 0, prevVal = 0, curVal = 1;
    while (curVal <= 4000000)
    {
        curVal += prevVal;
        if (curVal % 2 == 0)
            sum += curVal;
        std::swap(curVal, prevVal);
    }

    std::cout << sum << '\n';
}
