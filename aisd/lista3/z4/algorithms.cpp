void print(int *A, int p, int q) {
    for (int i = p; i <= q; i++) {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}

int binarySearch(int *A, int p, int q, int v) {
    if (p == q) {
        if (A[p] == v) return 1;
        else return 0;
    }
    else {
        if (A[(p+q)/2] == v) return 1;
        else if(A[(p+q)/2] > v) return binarySearch(A, p, (p+q)/2 - 1, v);
        else return binarySearch(A, (p+q)/2 + 1, q, v);
    }
}