#include <iostream>                        
using namespace std;                       

// Hàm tính ước chung lớn nhất (GCD) của hai số
int findGCD(int a, int b) {
    // Sử dụng thuật toán Euclid để tính GCD
    while (b != 0) {                       // Lặp cho đến khi b bằng 0
        int remainder = a % b;            // Tính số dư của a chia cho b
        a = b;                            // Gán giá trị b cho a
        b = remainder;                    // Gán số dư cho b
    }
    return a;                             // Khi b = 0, a là GCD
}

int main() {
    int num1, num2;                       // Khai báo hai biến số nguyên
    cin >> num1 >> num2;                  // Nhập hai số từ đầu vào
    cout << "GCD of " << num1 << " and " << num2 << " is "
        << findGCD(num1, num2) << endl;  // In ra GCD của hai số
    return 0;                             
