#include <iostream>
using namespace std;

// 交换两个元素
void swapValue(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 划分函数：将比基准值小的放左边，大的放右边
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];  // 选择最后一个元素作为基准值
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swapValue(arr[i], arr[j]);
        }
    }

    swapValue(arr[i + 1], arr[right]);

    return i + 1;
}

// 快速排序
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);

        // 排序基准值左边的部分
        quickSort(arr, left, pivotIndex - 1);

        // 排序基准值右边的部分
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main()
{
    int arr[] = {12, 4, 89, 43, 21, 78};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    cout << "排序后的结果：" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}