#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

// case-insensitive comparison for 's' and 't'
bool isS(char);
bool isT(char);

int main()
{
    std::ifstream in("s1.in");
    if (!in)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // Read the number of lines.
    int N;
    in >> N;
    in.ignore(); // Ignore the '\n' as the first line does not count.

    int s = 0, t = 0;

    // Iterate through all lines.
    while (N --> 0)
    {
        std::string line;
        std::getline(in, line);
        s += std::count_if(line.begin(), line.end(), isS);
        t += std::count_if(line.begin(), line.end(), isT);
    }

    if (t > s)
        std::cout << "English\n";
    else
        std::cout << "French\n";
}

bool isS(char c)
{
    return c == 'S' || c == 's';
}

bool isT(char c)
{
    return c == 'T' || c == 't';
}
