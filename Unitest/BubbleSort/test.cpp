#include "pch.h"
class ArraySorter {
private:
    int* arr;
    int size;

public:
    ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

    void BubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                   
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void PrintArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};
TEST(TestCaseName, TestName) {
    int unsortedArray[5] = { 9, 5, 2, 7, 1 };
    int sortedArray[5] = { 1, 2, 5, 7, 9 };
    ArraySorter sorter(unsortedArray, 5);
    sorter.BubbleSort();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(sortedArray[i], unsortedArray[i]);


    }
}