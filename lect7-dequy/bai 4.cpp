#include <iostream>
using namespace std;
double power(double x, int n) {
    if (n == 0) return 1; // Neu n = 0 thi x^0 = 1  
    if (n == 1) return x; // Neu n = 1 thi x^1 = x
    return x * power(x, n - 1); // Tinh x^n = x * x^(n - 1)
}
int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << power(x, n) << endl; // In ra x^n
    return 0;
}