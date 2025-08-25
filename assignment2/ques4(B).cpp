#include <iostream>
using namespace std;
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int n = 0;
    while (str[n] != '\0') 
    n++; 
    for (int i = 0; i < n / 2; i++)
     {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    cout << "Reversed String is  " << str << endl;
    return 0;
}
