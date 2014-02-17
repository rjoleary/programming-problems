#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::ostringstream;
using std::string;

int main()
{
	ostringstream ss;
	
	for (unsigned i = 1; ss.tellp() < 1000000; i++)
	{
		ss << i;
	}

	string s = ss.str();

	cout << (s[99]-'0') * (s[999]-'0') * (s[9999]-'0') * (s[99999]-'0') * (s[999999]-'0') << '\n';
}
