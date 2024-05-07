#include <iostream>
#include <random>
#include <chrono>

#include "algorithms.cpp"

int main() {
    double result1[4][500];
   // double result2[4][500];

    int index  = 0;
    for (int i = 100; i <= 50000; i+=100) {

        double swapSum1 = 0;
        double compSum1 = 0;

      //  double swapSum2 = 0;
      //  double compSum2 = 0;

        std::chrono::duration<double> time1 = std::chrono::duration<double>::zero();
        std::chrono::duration<double> time2 = std::chrono::duration<double>::zero();
        for (int j = 0; j < 50; j++) {
            int *numbers1 = new int[i];
       //     int *numbers2 = new int[i];

            std::random_device rd;
            std::mt19937 g(rd());
            std::uniform_int_distribution<int> distrib(1, 2*i - 1);
            std::uniform_int_distribution<int> k_distrib(0, i-1);

            int position = k_distrib(g);

            for (int k = 0; k < i; k++) {
                numbers1[k] = distrib(g);
            //    numbers2[k] = numbers1[k];
            }

            int swap1 = 0;
            int comp1 = 0;

          //  int swap2 = 0;
         //   int comp2 = 0;

            auto start = std::chrono::high_resolution_clock::now();
            Select(numbers1, 0, i - 1, 9, position, swap1, comp1);
            auto end = std::chrono::high_resolution_clock::now();
            time1 += end - start;

         //   start = std::chrono::high_resolution_clock::now();
         //   Select(numbers2, 0, i - 1, 5, position, swap2, comp2);
        //    end = std::chrono::high_resolution_clock::now();

        //    time2+= end - start;

            swapSum1+=swap1;
            compSum1+=comp1;

        //    swapSum2+=swap2;
        //    compSum2+=comp2;


            delete[] numbers1;
         //   delete[] numbers2;
        }
        result1[0][index] = i;
        result1[1][index] = time1.count();
        result1[2][index] = swapSum1/(double)50;
        result1[3][index] = compSum1/(double)50;

      //  result2[0][index] = i;
      //  result2[1][index] = time2.count();
     //   result2[2][index] = swapSum2/(double)50;
    //    result2[3][index] = compSum2/(double)50;
        index++;
    }

    for (int i = 0; i < 500; i++) {
        std::cout<<result1[0][i]<<", "<<result1[1][i]<<", "<<result1[2][i]<<", "<<result1[3][i]<<std::endl;
    }
  //  for (int i = 0; i < 500; i++) {
  //      std::cout<<result2[0][i]<<", "<<result2[1][i]<<", "<<result2[2][i]<<", "<<result2[3][i]<<std::endl;
 //   }
}

