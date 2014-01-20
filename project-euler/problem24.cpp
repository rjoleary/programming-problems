#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    unsigned counter = 1;
    std::string permutation = "0123456789";

    while (counter++ < 1000000)
        next_permutation(permutation.begin(), permutation.end());

    std::cout << permutation << '\n';
}
