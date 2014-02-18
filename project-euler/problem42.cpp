#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::ifstream fin("problem42.txt");

    if (!fin)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    std::vector<bool> triangleNumbers(10000, false);
    for (unsigned n = 0; (n*n+n)/2 < triangleNumbers.size(); n++)
        triangleNumbers[(n*n+n)/2] = true;

    unsigned wordSum = 0;
    std::string word;
    while (fin >> word)
    {
        unsigned sum = std::accumulate(word.begin(), word.end(), 0) - word.size() * ('A' - 1);
        if (triangleNumbers[sum])
            wordSum++;
    }

    std::cout << wordSum << '\n';
}
