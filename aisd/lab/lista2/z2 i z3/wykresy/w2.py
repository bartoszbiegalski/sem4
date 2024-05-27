import matplotlib.pyplot as plt


quicksort_swap = [448, 587.2, 657.667, 715.025, 773]
quicksort_compare = [64.2, 81.5, 93.9667, 102.3, 108.14]


hybrid_swap = [244.3, 374, 467.233, 524.3, 571.68]
hybrid_compare = [123.8, 151.75, 158.067, 161.95, 177.12]


tim_sort_swap = [227.4, 475.2, 717.033, 978.375, 1245.78]
tim_sort_compare = [227.4, 475.2, 717.033, 978.375, 1245.78]


standard_sort_swap = [227.3, 493, 731.167, 985.275, 1208.44]
standard_sort_compare = [227.3, 493, 731.167, 985.275, 1208.44]


n_values = [10, 20, 30, 40, 50]


quicksort_swap_per_n = [swap / n for swap, n in zip(quicksort_swap, n_values)]
hybrid_swap_per_n = [swap / n for swap, n in zip(hybrid_swap, n_values)]
tim_sort_swap_per_n = [swap / n for swap, n in zip(tim_sort_swap, n_values)]
standard_sort_swap_per_n = [swap / n for swap, n in zip(standard_sort_swap, n_values)]

quicksort_compare_per_n = [comp / n for comp, n in zip(quicksort_compare, n_values)]
hybrid_compare_per_n = [comp / n for comp, n in zip(hybrid_compare, n_values)]
tim_sort_compare_per_n = [comp / n for comp, n in zip(tim_sort_compare, n_values)]
standard_sort_compare_per_n = [comp / n for comp, n in zip(standard_sort_compare, n_values)]


plt.figure(figsize=(10, 6))
plt.plot(n_values, quicksort_swap_per_n, 'ro-', label='Quicksort')
plt.plot(n_values, hybrid_swap_per_n, 'bo-', label='Hybrid sort')
plt.plot(n_values, tim_sort_swap_per_n, 'go-', label='Tim sort')
plt.plot(n_values, standard_sort_swap_per_n, 'mo-', label='Standard sort')

plt.xlabel('n')
plt.ylabel('Swap count / n')
plt.title('Swap count per element comparison')
plt.legend()
plt.grid(True)
plt.show()


plt.figure(figsize=(10, 6))
plt.plot(n_values, quicksort_compare_per_n, 'ro-', label='Quicksort')
plt.plot(n_values, hybrid_compare_per_n, 'bo-', label='Hybrid sort')
plt.plot(n_values, tim_sort_compare_per_n, 'go-', label='Tim sort')
plt.plot(n_values, standard_sort_compare_per_n, 'mo-', label='Standard sort')

plt.xlabel('n')
plt.ylabel('Compare count / n')
plt.title('Compare count per element comparison')
plt.legend()
plt.grid(True)
plt.show()
