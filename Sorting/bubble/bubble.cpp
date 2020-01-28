#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; //worst case

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}