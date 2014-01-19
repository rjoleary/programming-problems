#include <iostream>
#include <fstream>

// This recursive function returns `0` for empty and `1` for crystal.
bool isCrystal(int m, int x, int y, int cm = 1);
// custom implementation of std::pow for ints
int pow(int b, int e);

int main()
{
    std::ifstream in("s3.in");
    if (!in)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // Iterate through all the tests.
    int T;
    in >> T;
    while (T --> 0)
    {
        int m, x, y;
        in >> m >> x >> y;
        std::cout << (isCrystal(m, x, y) ? "crystal" : "empty") << '\n';
    }
}

bool isCrystal(int m, int x, int y, int cm)
{
    // too magnified, no crystal
    if (cm > m)
        return false;

    // calculate x/y relative to current magnification
    int rx = (x / pow(5, m - cm)) % 5;
    int ry = (y / pow(5, m - cm)) % 5;

    // This array represents the fractal pattern.
    const int fractal[5][5] =
        {{ 0, 1, 1, 1, 0 },
         { 0, 2, 1, 2, 0 },
         { 0, 0, 2, 0, 0 },
         { 0, 0, 0, 0, 0 },
         { 0, 0, 0, 0, 0 }};

    switch (fractal[ry][rx])
    {
        // definately no crystal
        case 0: return false;
        // definately a crystal
        case 1: return true;
        // must go deeper
        case 2: return isCrystal(m, x, y, cm + 1);
    }

    // Execution should never reach here. Return statement removes warning.
    return false;
}

int pow(int b, int e)
{
    int p = 1;
    while (e --> 0)
        p *= b;
    return p;
}
