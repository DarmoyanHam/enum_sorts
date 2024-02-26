#include <iostream>
#include <algorithm>

void bubble_sort(int* arr, int size)
{
    bool swapped;
    for(int i = 0; i < size - 1; ++i)
    {
        swapped = false;
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] < arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

void selection_sort(int* arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        int m_index = i;
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] > arr[m_index])
            {
                m_index = j;
            }
        }

        if(i != m_index)
        {
            std::swap(arr[i], arr[m_index]);
        }
    }
}

enum Strategy {
    bubble = 1,
    selection
};

struct Option {
    Strategy strategy;
    void (*f_ptr)(int*, int);
};

void sort(Option& op, int* arr, int n)
{
    switch(op.strategy)
    {
        case bubble:
            op.f_ptr = bubble_sort;
            break;
        case selection:
            op.f_ptr = selection_sort;
    }   
}


int main()
{
    int const size = 5;
    int arr[size] = {1, 3, -7, 4, -2};

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Option option;
    option.strategy = selection;
    sort(option, arr, size);
    option.f_ptr(arr, size);

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}