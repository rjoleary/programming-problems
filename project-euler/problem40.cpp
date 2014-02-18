#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::ostringstream ss;

    for (int i = 1; ss.tellp() < 1000000; i++)
        ss << i;

    std::string s = ss.str();

    std::cout << (s[99]     - '0') *
                 (s[999]    - '0') *
                 (s[9999]   - '0') *
                 (s[99999]  - '0') *
                 (s[999999] - '0') << '\n';
}
