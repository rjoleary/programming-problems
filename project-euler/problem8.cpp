#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

// Return the numeric representation of a digit. Ex: '2' -> 2
int digitToInt(char);

int main()
{
    // Read the number from the file.
    // Due to its size, the number must be represented by a string.
    std::ifstream file("problem8.txt");
    if (!file)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }
    std::string number;
    getline(file, number);
    file.close();

    int maxProduct = 0;
    for (auto windowBegin = number.begin(), windowEnd = number.begin() + 5;
         windowEnd != number.end();
         ++windowBegin, ++windowEnd)
    {
        // Calculate the product of the moving window.
        int product = 1;
        for (auto i = windowBegin; i != windowEnd; ++i)
            product *= digitToInt(*i);

        maxProduct = std::max(product, maxProduct);
    }

    std::cout << maxProduct << '\n';
}

int digitToInt(char c)
{
    return c - '0';
}
