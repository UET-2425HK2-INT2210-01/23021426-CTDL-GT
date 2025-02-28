#include <iostream>
#include <string>
using namespace std;
void swap(string str)
{
	for (int i = str.length(); i >= 0; i--)
	{
		cout << str[i];
	}
}
int main()
{
	string str;
	getline(cin, str);
	swap(str);
	return 0;
}