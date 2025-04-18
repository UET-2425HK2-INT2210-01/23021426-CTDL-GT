#include <iostream>
using namespace std;
int sum(int n) {
    if (n == 0) return 0; // Neu n = 0 thi tong cac chu so = 0
    return n % 10 + sum(n / 10); // Tinh tong cac chu so = chu so cuoi + tong cac chu so cua n / 10
}
int main() {
    int n;
    cin >> n;
    cout << sum(n) << endl; // In ra tong cac chu so trong n
    return 0;
}