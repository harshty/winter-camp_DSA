#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string name)
{
    int n = name.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (name[i] != name[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string names[] = {"madam", "anna"};

    for (int i = 0; i < 2; i++)
    {
        cout << names[i] << " is ";
        if (!isPalindrome(names[i]))
        {
            cout << "not ";
        }
        cout << "a palindrome." << endl;
    }

    return 0;
}