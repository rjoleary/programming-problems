#include <algorithm>
#include <cstdint>
#include <iostream>

int main()
{
    const int limit = 1000000;
    int lengths[limit] = {0};

    for (int i = 2; i < limit; ++i)
    {
        int length = 0;
        std::int64_t n = i;
        while (n != 1)
        {
            if (n < limit && lengths[n] != 0)
            {
                length += lengths[n];
                break;
            }

            if (n % 2 == 0)
                n = n / 2;
            else
                n = n * 3 + 1;

            length++;
        }
        lengths[i] = length;
    }

    std::cout << std::max_element(lengths, lengths + limit) - lengths
              << '\n';
}
