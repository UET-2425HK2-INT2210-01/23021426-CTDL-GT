#include <iostream>
using namespace std;
int tim_max(int n, int arr[])
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
int tim_min(int n, int arr[])
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
int main()
{
	int n;
	int arr[10];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	;

	cout << "tong min va max: " << tim_max(n, arr) + tim_min(n, arr);
	return 0;

}