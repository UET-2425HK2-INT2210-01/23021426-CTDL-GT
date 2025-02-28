#include <iostream>
using namespace std;

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    cout << "Nhap hai so nguyen: ";
    cin >> a >> b;

    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << ucln(a, b) << endl;

    return 0;
}
