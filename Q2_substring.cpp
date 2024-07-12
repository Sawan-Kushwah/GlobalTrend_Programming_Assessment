// Q2 Given a string, find the length of the longest substring without repeating characters.The function should return an integer representing the length of the longest substring without repeating characters.


#include <iostream>
using namespace std;
int substringWithNoRepeatation(string s)
{
    if (s.length() == 0 || s.length() == 1)
    {
        return s.length();
    }
    int start = 0;
    int e = 0;
    int maxi = 0;
    int hash[26];
    for (int i = 0; i < 26; i++)
    {
        hash[i] = 0;
    }
    while (e < s.length())
    {
        if (hash[s[e] - 'a'] == 0)
        {
            hash[s[e] - 'a'] = 1;
            e++;
        }
        else
        {
            char ch = s[e];
            while (s[start] != ch)
            {
                hash[s[start] - 'a'] = 0;
                start++;
            }
            hash[s[start] - 'a'] = 0;
            start++;
        }
        maxi = max(maxi, e - start);
    }
    return maxi;
}
int main()
{
    // You can run on following Testcases

    // string s = "abcddefghij";
    // => Excepted Output : 7 ("defghij")

    // string s = "abcddefgghij";
    // => Excepted Output : 4 ("abcd" or "defg" or "ghij")

    // string s = ""
    // => Excepted Output : 0

    int len = substringWithNoRepeatation(s);
    cout << len;
    return 0;
}
