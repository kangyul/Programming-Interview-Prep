// Write a program that performs base conversion. The input is a string, an integer b1,
// and another integer b2. The string represents an integer in base b1. 
// The output should be the string representing the integer in the base b2.
// Assume 2 <= b1, b2 <= 16
// Use "A" to represent 10, "B" for 11, ... "F" for 15.

#include <bits/stdc++.h>

using namespace std;

string ConvertBase(const string& num_as_string, int b1, int b2);

string ConstructFromBase(int num_as_int, int base);

int main(void) {
    
    string ans = ConvertBase("615", 7, 13);
    cout << ans << endl;

    return 0;
}

string ConvertBase(const string& num_as_string, int b1, int b2) {
    bool is_negative = num_as_string.front() == '-';

    int num_as_int = accumulate(begin(num_as_string) + is_negative, end(num_as_string), 0, 
        [b1](int x, char c) {
            return x * b1 + (isdigit(c) ? c - '0' : c - 'A' + 10);
        }
    );

    return (is_negative ? "-" : "") + (num_as_int == 0 ? "0" : ConstructFromBase(num_as_int, b2));
}

string ConstructFromBase(int num_as_int, int base) {
    return num_as_int == 0 ? "" : ConstructFromBase(num_as_int / base, base) +
            (char)(num_as_int % base >= 10 ? 'A' + num_as_int % base - 10 : '0' + num_as_int & base);
}