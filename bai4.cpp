#include <iostream>
#include <algorithm>
using namespace std;
void swap(int arr[], int n)
{
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int n, arr[100];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	swap(arr, n);
	return 0;

}