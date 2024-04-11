#include <iostream>
#include <random>
#include <algorithm>

class MySort {
private:
public:

    int twoPower(int n) {
        int i = 1;
        while (i < n) {
            i *= 2;
        }
        return i;
    }

    void printArray(int A[], int p, int q, int n) {
        for (int i = p; i <= q; i++) {
            if(A[i] < 10) std::cout <<0<< A[i] << " ";
            else std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    void insertionSort(int A[], int p, int q, int n, int &swapNumber, int &compareNumber) {

        for (int j = p+1; j <= q; j++) {
            int key = A[j];
            int i = j - 1;
            while (i>=p && key < A[i]) {
                compareNumber++;
                swapNumber++;

                A[i+1] = A[i];
                i--;
            }
            A[i+1] = key;
           // if(n < 40) printArray(A, p, q, n);
        }
    }
    int partition(int *A, int p, int q, int &swapNumber, int &compareNumber) {
        int pivot = A[(p + q) / 2];
        int i = p - 1;
        int j = q + 1;
        while (true) {
            do {
                compareNumber++;
                i++;
            } while (A[i] < pivot);

            do {
                compareNumber++;
                j--;
            } while (A[j] > pivot);

            if (i >= j)
                return j;

            compareNumber++;
            if(A[i] != A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                swapNumber++;
            }
        }
    }

    void quicksort(int *A, int p, int q, int n, int &swapNumber, int &compareNumber)
    {
        if(q-p == n-1) {
            swapNumber = 0;
            compareNumber = 0;
        }

        if (p < q)
        {
            int pivot = partition(A, p, q, swapNumber, compareNumber);
            quicksort(A, p, pivot-1, n, swapNumber, compareNumber) ;
            quicksort(A, pivot + 1, q, n, swapNumber, compareNumber) ;
        }
    }

    void hybridQuickInsertionSort(int *A, int p, int q, int n, int &swapNumber, int &compareNumber)
    {
        while (p < q)
        {
            if (q-p + 1 < 10)
            {
                insertionSort(A, p, q, n, swapNumber, compareNumber);
                break;
            }

            else {
                int pivot = partition(A, p, q, swapNumber, compareNumber) ;
                if (pivot-p<q-pivot)
                {
                    hybridQuickInsertionSort(A, p, pivot - 1, n, swapNumber, compareNumber);
                    p = pivot + 1;
                }
                else
                {
                    hybridQuickInsertionSort(A, pivot + 1, q, n, swapNumber, compareNumber);
                    q = pivot-1;
                }
            }
        }
    }

    void merge(int *A, int l, int m, int r)
    {
        int len1 = m - l + 1, len2 = r - m;
        int left[len1], right[len2];
        for (int i = 0; i < len1; i++)
            left[i] = A[l + i];
        for (int i = 0; i < len2; i++)
            right[i] = A[m + 1 + i];

        int i = 0;
        int j = 0;
        int k = l;

        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                A[k] = left[i];
                i++;
            }
            else {
                A[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < len1) {
            A[k] = left[i];
            k++;
            i++;
        }

        while (j < len2) {
            A[k] = right[j];
            k++;
            j++;
        }
    }

    void myTimSort(int *A, int n, int &swap, int &comp)
    {
        for (int i = 0; i < n; i += 8) {
            insertionSort(A, i, std::min((i + 8 - 1), (n - 1)), n, swap, comp);
        }

        for (int size = 8; size < n; size = 2 * size) {

            for (int left = 0; left < n; left += 2 * size) {

                int mid = left + size - 1;
                int right = std::min((left + 2 * size - 1), (n - 1));

                if (mid < right)
                    merge(A, left, mid, right);
            }
        }
    }


    void partitionCount(int *A, int p, int q, int &s_count, int &l_count, int n) {
        printArray(A, p, q, n);

        int pivot_p = A[p];
        int pivot_q = A[q];
        int i = p + 1;
        int j = q - 1;

        for (int k = p + 1; k <= j; ++k) {
            if (A[k] < pivot_p)
                ++s_count;
            else if (A[k] > pivot_q)
                ++l_count;
            else {
                if (l_count <= s_count) {
                    std::swap(A[k], A[i]);
                    ++i;
                    ++s_count;
                } else {
                    while (A[j] > pivot_q && k < j)
                        --j;
                    std::swap(A[k], A[j]);
                    --j;
                    ++l_count;
                }
            }
        }

        std::swap(A[p], A[i - 1]);
        std::swap(A[q], A[j + 1]);

        s_count += (i - p - 1);
        l_count += (q - j - 1);
    }

    void dualPivotQuicksort(int *A, int p, int q, int n) {
        if (p < q) {
            int s_count = 0;
            int l_count = 0;
            partitionCount(A, p, q, s_count, l_count, n);
            dualPivotQuicksort(A, p, p + s_count - 1, n);
            dualPivotQuicksort(A, p + s_count + 1, q, n);
        }
    }



};
