#pragma once
#include<iostream>
using namespace std;

void merge(int arr[], int const left, int const mid, int const right) {
    // Параметры подмассивов.
    int start_ind = 0;
    int mid_ind = 0;
    int size = right - left;
    int* res = new int[size];

    // Заполнение результирующего массива.
    while (left + start_ind < mid && mid + mid_ind < right) {
        if (arr[left + start_ind] < arr[mid + mid_ind]) {
            res[start_ind + mid_ind] = arr[left + start_ind];
            start_ind++;
        }
        else {
            res[start_ind + mid_ind] = arr[mid + mid_ind];
            mid_ind++;
        }
    }

    // Циклы на случай, если какой-то массив был пройден.
    while (left + start_ind < mid) {
        res[start_ind + mid_ind] = arr[left + start_ind];
        start_ind++;
    }

    while (mid + mid_ind < right) {
        res[start_ind + mid_ind] = arr[mid + mid_ind];
        mid_ind++;
    }

    // Получаем отсортированный участок.
    for (int i = 0; i < start_ind + mid_ind; i++) {
        arr[left + i] = res[i];
    }
}

// Итеративная сортировка слиянием.
void mergeSort(int arr[], int n) {
    int subArr_size;
    int left;
    for (subArr_size = 1; subArr_size < n; subArr_size *= 2) {
        for (left = 0; left < n - subArr_size;
            left += 2 * subArr_size) {
            int right = min(left + 2 * subArr_size, n);
            merge(arr, left, left + subArr_size, right);
        }
    }
}