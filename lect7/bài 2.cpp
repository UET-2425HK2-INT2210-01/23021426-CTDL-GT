#include <iostream>                          
using namespace std;

const int MAXM = 100;                         // Giới hạn số dòng của ma trận
const int MAXN = 100;                         // Giới hạn số cột của ma trận

void findMaxRectangle() {
    int m, n;                                 // m là số hàng, n là số cột
    int matrix[MAXM][MAXN];                   // Ma trận đầu vào
    long long prefixSum[MAXM + 1][MAXN + 1] = { 0 }; // Ma trận tổng tích lũy 2D (1-based)

    cin >> m >> n;                            // Nhập kích thước ma trận

    for (int i = 0; i < m; ++i) {             // Nhập các phần tử của ma trận
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tính prefix sum 2D (dạng 1-based)
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefixSum[i][j] = matrix[i - 1][j - 1]
                + prefixSum[i - 1][j]
                + prefixSum[i][j - 1]
                - prefixSum[i - 1][j - 1];
        }
    }

    // Tìm hình chữ nhật con có tổng lớn nhất
    long long maxSum = -1e18;                 // Giá trị khởi tạo rất nhỏ
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;       // Tọa độ hình chữ nhật kết quả (1-based)

    for (int i1 = 0; i1 < m; ++i1) {          // Duyệt hàng bắt đầu
        for (int j1 = 0; j1 < n; ++j1) {      // Duyệt cột bắt đầu
            for (int i2 = i1; i2 < m; ++i2) { // Duyệt hàng kết thúc
                for (int j2 = j1; j2 < n; ++j2) { // Duyệt cột kết thúc
                    // Tính tổng các phần tử trong hình chữ nhật từ (i1,j1) đến (i2,j2)
                    long long sum = prefixSum[i2 + 1][j2 + 1]
                        - prefixSum[i2 + 1][j1]
                        - prefixSum[i1][j2 + 1]
                        + prefixSum[i1][j1];

                    // Cập nhật kết quả nếu tìm được tổng lớn hơn
                    if (sum > maxSum) {
                        maxSum = sum;
                        r1 = i1 + 1;          // +1 để chuyển sang chỉ số 1-based
                        c1 = j1 + 1;
                        r2 = i2 + 1;
                        c2 = j2 + 1;
                    }
                }
            }
        }
    }

    // In kết quả: tọa độ góc trái trên, góc phải dưới và tổng lớn nhất
    cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl;
}

int main() {
    findMaxRectangle();                      // Gọi hàm xử lý
    return 0;
}
