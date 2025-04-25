#include <iostream>           
using namespace std;             

int main() {
    int a[100], num, n = 0;      

    while (cin >> num) {         // Đọc các số từ đầu vào cho đến khi không còn số nào
        a[n++] = num;            // Thêm số vào mảng và tăng số lượng phần tử
    }

    // Sắp xếp mảng bằng thuật toán Selection Sort
    for (int i = 0; i < n - 1; i++) {          // Lặp qua từng vị trí trong mảng (trừ phần tử cuối cùng)
        int minIdx = i;                        // Giả sử phần tử nhỏ nhất là a[i]
        for (int j = i + 1; j < n; j++) {      // Duyệt các phần tử còn lại để tìm phần tử nhỏ nhất
            if (a[j] < a[minIdx]) {            // Nếu tìm thấy phần tử nhỏ hơn
                minIdx = j;                    // Cập nhật chỉ số phần tử nhỏ nhất
            }
        }
        if (minIdx != i) {                     // Nếu phần tử nhỏ nhất không nằm đúng vị trí
            swap(a[i], a[minIdx]);             // Hoán đổi phần tử nhỏ nhất với a[i]
        }
    }

    for (int i = 0; i < n; i++) {              // In các phần tử đã sắp xếp
        cout << a[i];                          // In phần tử thứ i
        if (i != n - 1) {                      // Nếu chưa phải phần tử cuối cùng
            cout << " ";                       // In khoảng trắng ngăn cách
        }
    }

    return 0;                                  
}
