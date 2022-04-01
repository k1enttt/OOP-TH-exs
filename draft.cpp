#include <iostream>
#include <time.h>
#include <algorithm>
#include <random>
using namespace std;

void shuffle_arr(int *arr, int n)
{
    unsigned seed = 0;

    shuffle(arr, arr + n, default_random_engine(seed));
}

int main(){
    int arr[5]{1, 2, 3, 4, 5};
    shuffle_arr(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << endl;
    return 0;
}
