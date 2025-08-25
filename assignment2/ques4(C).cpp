#include <iostream>
using namespace std;

bool isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + 32; // convert uppercase to lowercase manually
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';

    cout << "String after removing vowels: " << result << endl;
    return 0;
}
