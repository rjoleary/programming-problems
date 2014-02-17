#include <iostream>
#include <sstream>
#include <algorithm>

int main()
{
    unsigned maxPandigital = 0;
    for (unsigned i = 1; i < 10000; ++i)
    {
        std::stringstream ss;
        for (unsigned j = 1; ss.str().length() < 9; ++j)
            ss << i * j;

        if (ss.str().length() != 9)
            continue;

        std::string sortedPan = "123456789";
        std::string sorted = ss.str();
        std::sort(sorted.begin(), sorted.end());
        if (sortedPan == sorted)
        {
            unsigned pandigital = 0;
            ss >> pandigital;
            maxPandigital = std::max(maxPandigital, pandigital);
        }
    }
    std::cout << maxPandigital << '\n';
}
