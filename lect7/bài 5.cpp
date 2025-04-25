#include <iostream>                         
#include <string.h>                          

using std::cin, std::cout;                  

void print(int a, int s[], bool f[], int index) {
    if (a == index) {                      // Nếu đã chọn đủ a phần tử
        for (int i = 0; i < index; i++) {
            cout << s[i];                   // In ra 1 hoán vị
        }
        cout << std::endl;                  // Xuống dòng sau mỗi hoán vị
        return;
    }

    // Quay lui: thử từng giá trị từ 1 đến a
    for (int j = 1; j <= a; j++) {
        if (f[j] == false) {                // Nếu j chưa được dùng
            s[index] = j;                   // Gán j vào vị trí hiện tại
            f[j] = true;                    // Đánh dấu j đã dùng
            print(a, s, f, index + 1);      // Gọi đệ quy cho vị trí tiếp theo
            f[j] = false;                   // Quay lui: bỏ đánh dấu j để thử giá trị khác
        }
    }
}

int main() {
    int n;
    cin >> n;                               // Nhập số nguyên n

    int a[n + 1];                           // Mảng chứa hoán vị (tạm thời)
    bool b[n + 1];                          // Mảng đánh dấu phần tử đã dùng

    memset(a, 0, sizeof(a));                // Khởi tạo mảng a với 0
    memset(b, false, sizeof(b));            // Khởi tạo mảng b với false (chưa dùng)

    print(n, a, b, 0);                      // Bắt đầu tạo hoán vị từ index = 0
}
