#include <iostream>
#include <string>

using namespace std;

int main() {
    string text, find, replace;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the substring to find: ";
    getline(cin, find);

    cout << "Enter the replacement substring: ";
    getline(cin, replace);

    int pos = text.find(find);

    while (pos != string::npos) {
        text.replace(pos, find.length(), replace);
        pos = text.find(find);
    }

    cout << "The modified text is: " << text << endl;

    return 0;
}