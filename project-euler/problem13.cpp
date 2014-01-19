#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
    std::ifstream file("problem13.txt");
    std::int64_t sum = 0;
    for (int i = 0; i < 100; i++)
    {
        // Only read the first 15 digits. It works out the same as
        //  long as addition is concerned.
        char c[16] = {0};
        file.read(c, 15);
        file.ignore(100, '\n');
        std::int64_t n;
        std::istringstream(c) >> n;
        sum += n;
    }
    // Reduce the number to 10 digits.
    while (sum >= 1e10)
        sum /= 10;
    std::cout << sum << '\n';
}
