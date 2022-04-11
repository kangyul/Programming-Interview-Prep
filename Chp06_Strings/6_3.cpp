#include <bits/stdc++.h>

using namespace std;

int SSDecodeColID(const string& col) {
    return accumulate(begin(col), end(col), 0, [](int result, char c) {
        return result * 26 + c - 'A' + 1;
    });
}

int main(void) {

    cout << SSDecodeColID("ZZ") << endl;

    return 0;
}