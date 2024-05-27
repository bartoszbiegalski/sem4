#include <unistd.h>

void swap(int *a, int *b);

bool compare(int a, int b);

int min(int a, int b);

int top(int a, int b);

void print(int *A, int p, int q);

void copyArray(int *A, int *B, int p, int q);

void InsertionSort(int *A, int p, int q, int &swap_number, int &comp_number);

int RandomPartition(int *A, int p, int q, int &swap_number, int &comp_number);

int RandomizedSelect(int *A, int p, int q, int k, int &swap_number, int &comp_number);

int median(int *A, int p, int q, int &swap_number, int &comp_number);

int MedianPartition(int *A, int p, int q, int pivot, int &swap_number, int &comp_number);

int Select(int *A, int p, int q, int div, int i, int &swap_number, int &comp_number);
//

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool compare(int a, int b) {
    return a <= b;
}

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int top(int a, int b) {
    if (a % b == 0) return a / b;
    else return (a / b) + 1;
}

void print(int *A, int p, int q) {
    for (int i = p; i <= q; i++) {
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
}

void copyArray(int *A, int *B, int p, int q) {
    for (int i = p; i <= q; i++) {
        B[i] = A[i];
    }
}

void InsertionSort(int *A, int p, int q, int &swap_number, int &comp_number) {
    //std::cout<<"insertion\n";

    for (int i = p + 1; i <= q; i++) {
        int key = A[i];
        int j = i - 1;
        comp_number++;
        while (j >= p && A[j] > key) {
            comp_number++;
            swap_number++;
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}


int RandomPartition(int *A, int p, int q, int &swap_number, int &comp_number)
{
    int pivot = A[q];

    int i = p - 1;

    for (int j = p; j <= q; j++)
    {
        if(A[j] < pivot)
        {
            comp_number++;
            i++;
            swap(&A[i],&A[j]);
            swap_number++;
        }
        comp_number++;
    }
    swap(&A[i+1],&A[q]);
    swap_number++;
    //print(A, p, q);

    return i+1;
}

int RandomizedSelect(int *A, int p, int q, int i, int &swap_number, int &comp_number) {
    if (p == q) return A[q];
    int r = RandomPartition(A, p, q, swap_number, comp_number);
    int k = r - p;

    if (i == k) return A[r];
    if (i < k) return RandomizedSelect(A, p, r-1, i, swap_number, comp_number);
    else return RandomizedSelect(A, r + 1, q, i - k - 1, swap_number, comp_number);
}

int median(int *A, int p, int q, int &swap_number, int &comp_number) {
    int n =  q - p + 1;

    if (p==q) return p;

    int B[n];

    int index = 0;
    for (int i = p; i <=q; i++) {
        B[index] = A[i];
        index++;
    }
    InsertionSort(B, 0, n-1, swap_number, comp_number);

    int pivot = B[n/2];

    for (int i = p; i <= q; i++)
        if (A[i] == pivot) {
            return i;
    }
}

int MedianPartition(int *A, int p, int q, int pivot, int &swap_number, int &comp_number) {
    int i = p;
    while (A[i] != pivot) i++;

    swap(&A[i], &A[q]);


    return RandomPartition(A, p, q, swap_number, comp_number);
}

int Select(int *A, int p, int q, int div, int i, int &swap_number, int &comp_number) {
    if (p == q) return A[q];

    int pivot = 0;

    int n = ((q - p) + 1) / div;
    if (((q - p) + 1) % div != 0) {
            n++;
    }

    int B[n];
    int index = p;

    for (int i = 0; i < n; i++) {
        if (index + div > q) {
            B[i] = A[median(A, index, q, swap_number, comp_number)];
        } else B[i] = A[median(A, index, index + div - 1, swap_number, comp_number)];
        index += div;
    }

    if (n <= div) {
        InsertionSort(B, 0, n-1, swap_number, comp_number);
        pivot = B[n/2];
    }
    else {
        pivot = Select(B, 0, n-1, div, n/2, swap_number, comp_number);
    }

    int r = MedianPartition(A, p, q, pivot, swap_number, comp_number);

    int k = r - p;

    if (i == k) return A[r];
    if (i < k) return Select(A, p, r-1, div, i, swap_number, comp_number);
    else return Select(A, r + 1, q, div,  i - k - 1, swap_number, comp_number);
}
