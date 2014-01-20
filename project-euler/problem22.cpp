#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::ifstream file("problem22.txt");
    if (!file)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // Read all the names from `file`.
    // The file is already sorted.
    typedef std::istream_iterator<std::string> I;
    std::vector<std::string> names(I(file), (I()));

    unsigned sum = 0, i = 0;
    for (auto &name : names)
    {
        sum += (++i) * std::accumulate(name.begin(), name.end(), 0,
            [] (unsigned acc, char c) {
                return acc + (unsigned)(c - 'A') + 1;
            });
    }

    std::cout << sum << '\n';
}
