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

plt.figure(figsize=(10, 6))
plt.plot(n_values, quicksort_swap, 'ro-', label='Quicksort')
plt.plot(n_values, hybrid_swap, 'bo-', label='Hybrid sort')
plt.plot(n_values, tim_sort_swap, 'go-', label='Tim sort')
plt.plot(n_values, standard_sort_swap, 'mo-', label='Standard sort')

plt.xlabel('n')
plt.ylabel('Swap count')
plt.title('Swap count comparison')
plt.legend()
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(n_values, quicksort_compare, 'ro-', label='Quicksort')
plt.plot(n_values, hybrid_compare, 'bo-', label='Hybrid sort')
plt.plot(n_values, tim_sort_compare, 'go-', label='Tim sort')
plt.plot(n_values, standard_sort_compare, 'mo-', label='Standard sort')

plt.xlabel('n')
plt.ylabel('Compare count')
plt.title('Compare count comparison')
plt.legend()
plt.grid(True)
plt.show()
