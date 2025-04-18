#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n == 0) return 0; // Neu n = 0 thi F(0) = 0
    if (n == 1) return 1; // Neu n = 1 thi F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Tinh F(n) = F(n - 1) + F(n - 2)
}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl; // In ra F(n)
    return 0;
}