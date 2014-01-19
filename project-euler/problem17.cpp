#include <cassert>
#include <iostream>

// Results in the length of a c-style string.
#define STR_LEN(a) ((sizeof(a)/sizeof(0[a])-1))

int getNumberLength(int);
int getDigitLength(int);

int main()
{
    int sum = 0;
    for (unsigned i = 1; i <= 1000; i++)
    {
        sum += getNumberLength(i);
    }
    std::cout << sum << '\n';
}

int getNumberLength(int x)
{
    int digit4 = (x / 1000) % 10;
    int digit3 = (x / 100)  % 10;
    int digit2 = (x / 10)   % 10;
    int digit1 =  x         % 10;

    int length = 0;

    // thousands digit
    assert(0 <= digit4 && digit4 <= 9);
    if (digit4 > 0)
    {
        length += getDigitLength(digit4);
        length += STR_LEN("thousand");
    }

    // hundreds digit
    assert(0 <= digit3 && digit3 <= 9);
    if (digit3 > 0)
    {
        length += getDigitLength(digit3);
        length += STR_LEN("hundred");
        if (digit2 > 0 || digit1 > 0)
            length += STR_LEN("and");
    }

    // tens digit
    assert(0 <= digit2 && digit2 <= 9);
    const int teens[10] = {
        STR_LEN("ten"),      STR_LEN("eleven"),    STR_LEN("twelve"),
        STR_LEN("thirteen"), STR_LEN("fourteen"),  STR_LEN("fifteen"),
        STR_LEN("sixteen"),  STR_LEN("seventeen"), STR_LEN("eighteen"),
        STR_LEN("nineteen")
    };
    const int tens[10] = {
        0, 0,
        STR_LEN("twenty"), STR_LEN("thirty"), STR_LEN("forty"),
        STR_LEN("fifty"),  STR_LEN("sixty"),  STR_LEN("seventy"),
        STR_LEN("eighty"), STR_LEN("ninety")
    };
    switch (digit2)
    {
        case 0:
            break;
        case 1:
            length += teens[digit1];
            break;
        default:
            length += tens[digit2];
    }

    // ones digit
    assert(0 <= digit1 && digit1 <= 9);
    if (digit2 != 2)
        length += getDigitLength(digit1);

    return length;
}

int getDigitLength(int x)
{
    assert(0 <= x && x <= 9);
    const int digits[10] = {
        0,
        STR_LEN("one"),   STR_LEN("two"),   STR_LEN("three"),
        STR_LEN("four"),  STR_LEN("five"),  STR_LEN("six"),
        STR_LEN("seven"), STR_LEN("eight"), STR_LEN("nine")
    };
    return digits[x];
}

