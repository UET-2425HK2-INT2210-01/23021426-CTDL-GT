#include <iostream>
using namespace std;
int reverseRec(int n, int rev) {
    if (n == 0) return rev; // Neu n = 0 thi tra ve rev
    return reverseRec(n / 10, rev * 10 + n % 10); // Tinh dao nguoc = 10 * rev + chu so cuoi
}
int main() {
    int n;
    cin >> n;
    cout << reverseRec(n, 0) << endl; // In ra so dao nguoc
    return 0;
}