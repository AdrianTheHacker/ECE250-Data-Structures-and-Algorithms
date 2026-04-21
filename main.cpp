#include <iostream>

void print(int arr[], int size);

// Merge Sort
void merge_sort(int arr[], int size);
void merge(int arr[], int pivot, int size);

// Quick Sort
void quick_sort(int arr[], int size);

int main()
{
    int numbers[] = {2, 9, 5, 1, 0, 7, 6};
    int size = 7;

    print(numbers, size);
    // merge_sort(numbers, size);
    quick_sort(numbers, size);
    print(numbers, size);

    return 0;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

////////////////
// Merge Sort //
////////////////
void merge_sort(int arr[], int size)
{
    if (size > 2)
    {
        int pivot = size / 2;
        int new_size = size - pivot;

        merge_sort(&arr[0], pivot);
        merge_sort(&arr[pivot], new_size);

        merge(arr, pivot, size);
    }

    else
    {
        if (size == 2)
        {
            if (arr[0] > arr[1])
            {
                int temp = arr[0];
                arr[0] = arr[1];
                arr[1] = temp;
            }
        }
    }
}

void merge(int arr[], int pivot, int size)
{
    int *new_arr = new int[size];

    int i = 0;
    int j = pivot;

    for (int k = 0; k < size; k++)
    {
        if (i == pivot)
        {
            new_arr[k] = arr[j];
            j++;
            continue;
        }

        if (j == size)
        {
            new_arr[k] = arr[i];
            i++;
            continue;
        }

        if (arr[i] < arr[j])
        {
            new_arr[k] = arr[i];
            i++;
            continue;
        }

        new_arr[k] = arr[j];
        j++;
    }

    for (int k = 0; k < size; k++)
    {
        arr[k] = new_arr[k];
    }

    delete[] new_arr;
    new_arr = nullptr;
}

////////////////
// Quick Sort //
////////////////
void quick_sort(int arr[], int size)
{
    if (size < 2) return;

    int pivot_value = arr[size - 1];
    int i = -1;

    for (int j = 0; j < size - 1; j++)
    {
        if (arr[j] < pivot_value)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    i++;
    int temp = arr[i];
    arr[i] = arr[size - 1];
    arr[size - 1] = temp;

    // Recurse on left and right, excluding the pivot
    quick_sort(arr, i);
    quick_sort(&arr[i + 1], size - i - 1);
}
