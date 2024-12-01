
#include "libmy.h"

void countSort(int *arr, const int len, const int nbDigit) {
    int output[len];
    int count[10] = {0};

    for (int i = 0; i < len; i++)
        count[(arr[i] / nbDigit) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = len - 1; i >= 0; i--) {
        output[count[(arr[i] / nbDigit) % 10] - 1] = arr[i];
        count[(arr[i] / nbDigit) % 10]--;
    }

    for (int i = 0; i < len; i++)
        arr[i] = output[i];
}

void radix(int *arr, const int len, const int maxValue) {
    for (int nbDigit = 1; maxValue / nbDigit > 0; nbDigit *= 10) {
        countSort(arr, len, nbDigit);
    }
}
