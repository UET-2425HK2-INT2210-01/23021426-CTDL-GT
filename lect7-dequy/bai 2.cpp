#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 0 || n == 1) return 1; // Neu n = 0 hoac n = 1 thi giai thua = 1
    return n * factorial(n - 1); // Tinh giai thua n! = n * (n - 1)!
}
int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl; // In ra giai thua n!
    return 0;
}