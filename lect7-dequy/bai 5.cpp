#include <iostream>
using namespace std;
int dem(int n) {
    if (n == 0) return 1; // Neu n = 0 thi co 1 chu so
    if (n < 10) return 1; // Neu n < 10 thi co 1 chu so
    return 1 + dem(n / 10); // Tinh so chu so = 1 + so chu so cua n / 10
}
int main() {
    int n;
    cin >> n;
    cout << dem(n) << endl; // In ra so chu so trong n
    return 0;
}