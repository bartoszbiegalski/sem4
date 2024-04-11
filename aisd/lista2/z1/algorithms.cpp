#include <iostream>
#include <random>
#include <algorithm>

class Pair {
public:
    int x;
    int y;
    Pair(int x, int y) : x(x), y(y) {};

};


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
            if(n < 40) printArray(A, p, q, n);
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


    void timSort(int *A, int n, int &swap, int &comp)
    {
        for (int i = 0; i < n; i += twoPower(n)) {
            insertionSort(A, i, std::min((i + twoPower(n) - 1), (n - 1)), n, swap, comp);
        }

        for (int size = twoPower(n); size < n; size = 2 * size) {

            for (int left = 0; left < n; left += 2 * size) {

                int mid = left + size - 1;
                int right = std::min((left + 2 * size - 1), (n - 1));

                if (mid < right)
                    merge(A, left, mid, right);
            }
        }
    }
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    Pair partition(int* A, int p, int q, int n, int &swapNumber, int &compareNumber) {
        if(q-p == n) {
            swapNumber = 0;
            compareNumber = 0;
        }

        if (A[p] > A[q]) {
            swap(A[p], A[q]);
            compareNumber++;
        }

        int j = p + 1;
        int g = q - 1;
        int k = p + 1;

        int pivot1 = A[p];
        int pivot2 = A[q];

        while (k <= g) {
            if (A[k] < pivot1) {
                compareNumber++;
                swapNumber++;
                swap(A[k], A[j]);
                j++;
            } else if (A[k] >= pivot2) {
                compareNumber++;
                while (A[g] > pivot2 && k < g) {
                    g--;
                    compareNumber++;
                }
                swap(A[k], A[g]);
                swapNumber++;
                g--;
                if (A[k] < pivot1) {
                    compareNumber++;
                    swapNumber++;
                    swap(A[k], A[j]);
                    j++;
                }
            }
            k++;
        }
        j--;
        g++;

        swap(A[p], A[j]);
        swap(A[q], A[g]);
        swapNumber+=2;
        Pair pair(j, g);
        return pair;
    }

    void DualPivotQuickSort(int* A, int p, int q, int n, int &swapNumber, int &compareNumber) {
        if (p < q) {
            Pair pair = partition(A, p, q, n, swapNumber, compareNumber);
            DualPivotQuickSort(A, p, pair.x - 1, n,swapNumber, compareNumber);
            if(n<30) printArray(A, p, pair.x - 1, n);
            DualPivotQuickSort(A, pair.x + 1, pair.y - 1, n,swapNumber, compareNumber);
            if(n<30) printArray(A, pair.x + 1, pair.y - 1, n);
            DualPivotQuickSort(A, pair.y + 1, q, n,swapNumber, compareNumber);
            if(n<30) printArray(A, pair.y + 1, q, n);

        }
    }



};
