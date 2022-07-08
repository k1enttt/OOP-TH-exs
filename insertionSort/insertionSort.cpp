#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && temp <= a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

int main()
{
    int a[5]{12, 4, 3, 1, 15};
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    InsertionSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}