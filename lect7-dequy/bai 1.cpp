#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) return 0; // Neu n = 0 thi tong = 0
    if (n == 1) return 1; // Neu n = 1 thi tong = 1
    return n + sum(n - 1); // Tinh tong n + tong (1 + 2 + ... + n - 1)
}
int main() {
    int n;
    cin >> n;
    cout << sum(n) << endl; // In ra tong 1 + 2 + ... + n
    return 0;
}