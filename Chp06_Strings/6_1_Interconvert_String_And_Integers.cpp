// Implement an integer to string conversion function, and a string to integer conversion function. 

#include <bits/stdc++.h>

using namespace std;

string IntToString(int x) {
    bool is_negative = false;
    if (x < 0) {
        is_negative = true;
    }

    string s;
    do {
        s += '0' + abs(x % 10);
        x /= 10;
    } while (x);

    s += is_negative ? "-" : "";
    return {rbegin(s), rend(s)};
}

int StringToInt(const string& s) {
    int sign = s[0] == '-' ? -1 : 1;
    int startIndex = s[0] == '-' ? 1 : 0;

    int num = 0;
    for(int i = startIndex; i < s.length(); ++i) {
        int digit = s[i] - '0';
        num = num * 10 + digit;
    }

    return sign * num;
}

int main(void) {

    int a = 123;
    int b = -1234;

    cout << IntToString(a) << endl;
    cout << IntToString(b) << endl;

    string s1 = "123";
    cout << StringToInt(s1) << endl;

    
    return 0;
}