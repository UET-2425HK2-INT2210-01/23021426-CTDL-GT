#include <iostream>

using namespace std;

int vongLap(int n) {
	int result = 1; // cho result = 1
	for (int i = 0; i < n; i++) {
		result *= 2;
	} // Cho result nhân với 2n lần
	return result; // Trả về result
} // Độ phức tạp O(n)

int deQuy(int n) {
	if (n == 0) {
		return 1;
	} // Nếu n = 0 thì  trả về 1
	else {
		return 2 * deQuy(n - 1);
	}// nếu n khác 0 tiếp tục hàm với n - 1
} // Độ phức tạp O(n)