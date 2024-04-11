import matplotlib.pyplot as plt

# Dane wyjściowe dla quicksort
quicksort_swap = [207.338, 229.172, 244.017, 253.755, 260.815, 266.99, 272.018, 277.12, 280.423, 284.476, 287.817, 290.538, 293.636, 295.544, 298.284, 299.789, 302.336, 304.022, 305.852, 307.808, 309.322, 310.475, 312.352, 313.8, 315.108, 316.204, 317.758, 319.465, 320.275, 321.339, 322.617, 323.479, 324.313, 325.186, 326.598, 327.409, 328.469, 329.575, 330.062, 331.017, 332.359, 332.606, 333.302, 334.081, 334.901, 335.78, 336.595, 336.985, 337.917, 338.57]
quicksort_compare = [1452.54, 1629.88, 1708.92, 1782.23, 1836.45, 1875.1, 1921.31, 1930.03, 1977.24, 1993.63, 2014.2, 2030.36, 2046.27, 2082.78, 2083.78, 2111.66, 2118.49, 2131.11, 2148.21, 2160.03, 2172.53, 2191.1, 2192.2, 2200.68, 2210.64, 2229.08, 2230.47, 2225.79, 2241.96, 2252.86, 2262.18, 2274.05, 2276.41, 2290.12, 2290.46, 2294.27, 2296.08, 2299.27, 2314.76, 2324.45, 2314.86, 2332.09, 2341.98, 2352.0, 2348.44, 2350.99, 2356.16, 2366.85, 2371.5, 2372.6]

# Dane wyjściowe dla dualpivotquicksort
dualpivotquicksort_swap = [431.158, 468.202, 493.905, 509.808, 519.535, 536.462, 547.583, 547.69, 559.091, 563.768, 568.873, 570.714, 582.442, 588.584, 591.332, 594.071, 604.66, 604.366, 601.166, 608.267, 612.003, 614.57, 619.319, 619.432, 621.132, 622.352, 625.848, 625.551, 629.646, 639.601, 637.223, 634.681, 628.832, 642.618, 639.761, 638.406, 648.063, 647.867, 650.937, 648.138, 651.213, 659.576, 650.064, 657.108, 649.74, 657.636, 653.464, 658.359, 667.133, 663.8]
dualpivotquicksort_compare = [534.014, 594.328, 625.891, 649.305, 671.404, 696.193, 704.898, 720.592, 729.849, 733.536, 741.875, 747.279, 767.568, 766.378, 772.769, 781.224, 789.164, 796.969, 797.789, 800.374, 800.877, 812.242, 813.435, 818.925, 821.27, 826.01, 826.664, 832.55, 830.067, 848.149, 844.247, 844.293, 833.913, 851.575, 848.013, 852.227, 864.002, 861.92, 864.79, 869.156, 862.99, 866.998, 870.7, 869.325, 873.677, 871.73, 874.587, 877.71, 882.55, 882.78]

n_values = [i * 1000 for i in range(1, 51)]

# Generowanie wykresu dla ilości zamian
plt.figure(figsize=(10, 6))
plt.plot(n_values, quicksort_swap, 'ro-', label='Quicksort')
plt.plot(n_values, dualpivotquicksort_swap, 'bo-', label='Dual Pivot Quicksort')

plt.xlabel('n')
plt.ylabel('Swap count')
plt.title('Swap count comparison')
plt.legend()
plt.grid(True)
plt.show()

# Generowanie wykresu dla ilości porównań
plt.figure(figsize=(10, 6))
plt.plot(n_values, quicksort_compare, 'ro-', label='Quicksort')
plt.plot(n_values, dualpivotquicksort_compare, 'bo-', label='Dual Pivot Quicksort')

plt.xlabel('n')
plt.ylabel('Compare count')
plt.title('Compare count comparison')
plt.legend()
plt.grid(True)
plt.show()