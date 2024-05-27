#include <iostream>
#include <climits>
#include <vector>

int maxSumArray(std::vector<int> &A) {
    int n = A.size();
    int global_max = INT_MIN;
    int local_max = 0;
	
    int start = 0;
    int end = 0;
    int current_start = 0;
    
    for (int i = 0; i < n; i++) {
        if (A[i] > A[i] + local_max) {
            local_max = A[i];
            current_start = i;
        } else {
            local_max = A[i] + local_max;
        }
        
        if (local_max > global_max) {
            global_max = local_max;
            start = current_start;
            end = i;
        }
    }
    
    for (int i = start; i <= end; i++) {
    	std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    
    return global_max;
}

int main() {
    std::vector<int> vec = {5, 15, -30, 10, -5, 40, 10};
    std::cout << maxSumArray(vec) << std::endl;

    return 0;
}

