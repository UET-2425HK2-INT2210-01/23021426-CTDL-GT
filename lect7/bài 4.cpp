#include <iostream>                      
using namespace std;

const int MAXN = 20;                    // Giới hạn tối đa độ dài chuỗi nhị phân
int binary[MAXN];                       // Mảng lưu trữ chuỗi nhị phân tạm thời

void generateBinary(int pos, int n) {
    if (pos == n) {                     // Nếu đã xây dựng xong độ dài n
        for (int i = 0; i < n; ++i) {
            cout << binary[i];          // In từng bit của số nhị phân
        }
        cout << endl;                   // Xuống dòng sau mỗi số
        return;
    }

    // Thử gán 0 vào vị trí hiện tại và tiếp tục đệ quy
    binary[pos] = 0;
    generateBinary(pos + 1, n);

    // Thử gán 1 vào vị trí hiện tại và tiếp tục đệ quy
    binary[pos] = 1;
    generateBinary(pos + 1, n);
}

void listBinaryNumbers() {
    int n;
    cin >> n;                           // Nhập độ dài chuỗi nhị phân
    generateBinary(0, n);              // Bắt đầu đệ quy từ vị trí đầu tiên
}

int main() {
    listBinaryNumbers();               // Gọi hàm chính để liệt kê
    return 0;                         
}
