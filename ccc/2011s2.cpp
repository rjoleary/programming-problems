#include <fstream>
#include <iostream>
#include <string>

// Reads `n` answers into a string.
std::string readAnswerSet(std::istream &, int n);

int main()
{
    std::ifstream in("s2.in");
    if (!in)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    int n;
    in >> n;

    // Read student and correct answers.
    auto a1 = readAnswerSet(in, n), a2 = readAnswerSet(in, n);

    // Compare the answer sets.
    int correct = 0;
    for (auto i1 = a1.begin(), i2 = a2.begin(); i1 != a1.end(); ++i1, ++i2)
        if (*i1 == *i2)
            correct++;

    std::cout << correct << '\n';
}

std::string readAnswerSet(std::istream &stream, int n)
{
    std::string answerSet(n, ' ');
    for (char &c : answerSet)
        stream >> c;
    return answerSet;
}
