// Q10 Write a function to check if a given string contains only alphabetic characters.The function should return true if the string contains only alphabetic characters, and false otherwise.

#include <iostream>
using namespace std;
bool checkString(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] < 'a' || str[i] > 'z'))
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string s = "ldjfld@j"; // false;
    string s1 = "ldjfldj"; // true;
    cout << s << " " << checkString(s) << endl;
    return 0;
}
