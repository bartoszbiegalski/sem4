import matplotlib.pyplot as plt


quick_swap = [
    207.527, 230.325, 243.737, 253.391, 260.854, 266.877, 272.753, 276.703, 280.732, 283.914, 
    287.394, 290.148, 292.875, 295.459, 297.81, 299.83, 302.174, 304.431, 306.311, 307.688, 
    309.487, 310.442, 312.665, 314.183, 315.233, 316.723, 317.758, 318.948, 320.071, 321.37, 
    322.29, 323.558, 324.559, 325.569, 326.277, 327.056, 328.575, 329.07, 330.285, 330.93, 
    331.803, 332.706, 333.119, 334.463, 334.927, 335.656, 336.197, 336.586, 337.683, 338.53
]


quick_compare = [
    1453.25, 1613.62, 1714.43, 1785.59, 1834.95, 1883.06, 1904.92, 1939.97, 1977.06, 2001.63, 
    2018.74, 2038.82, 2065.1, 2078.49, 2093.61, 2115.07, 2118.54, 2129.45, 2132.11, 2132.11, 
    2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 
    2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 
    2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11, 2132.11
]


hybrid_swap = [
    271.462, 295.327, 307.944, 318.01, 325.546, 331.763, 336.746, 340.719, 345.518, 348.935, 
    352.573, 354.651, 357.051, 359.807, 362.884, 364.698, 366.63, 368.591, 370.097, 371.893, 
    374.334, 375.012, 376.305, 378.213, 379.095, 380.976, 382.181, 383.436, 384.264, 385.623, 
    386.857, 387.738, 388.774, 389.793, 390.213, 392.006, 392.336, 393.541, 394.394, 395.458, 
    396.337, 397.3, 397.566, 398.043, 399.797, 399.96, 400.88, 401.272, 401.921, 402.872
]


hybrid_compare = [
    1273.44, 1419.95, 1529.75, 1600.95, 1645.58, 1685.9, 1714.23, 1763.53, 1780.43, 1809.42, 
    1831.71, 1852.23, 1880.76, 1899.46, 1900.01, 1915.28, 1933.61, 1949.41, 1960.3, 1981.21, 
    1968.24, 1998.77, 2016.45, 2016.38, 2036.32, 2029.84, 2043.08, 2053.87, 2069.42, 2070.05, 
    2075.57, 2086.05, 2085.54, 2102.54, 2112.23, 2105.93, 2125.51, 2129.75, 2135.52, 2135.9, 
    2139.99, 2145.08, 2154.07, 2163.17, 2150.31, 2173.56, 2174.38, 2185.37, 2187.62, 2194.97
]


tim_swap = [
    175.969, 176.264, 176.655, 176.869, 176.995, 176.573, 176.429, 176.881, 176.614, 176.751, 
    176.774, 176.486, 176.769, 176.777, 176.761, 176.587, 176.529, 176.642, 176.636, 176.711, 
    176.786, 176.538, 176.514, 176.701, 176.664, 176.816, 176.661, 176.875, 176.726, 176.815, 
    176.793, 176.793, 176.753, 176.589, 176.718, 176.629, 176.713, 176.654, 176.712, 176.704, 
    176.845, 176.733, 176.73, 176.847, 176.777, 176.805, 176.774, 176.72, 176.64, 176.831
]


tim_compare = [
    175.969, 176.264, 176.655, 176.869, 176.995, 176.573, 176.429, 176.881, 176.614, 176.751, 
    176.774, 176.486, 176.769, 176.777, 176.761, 176.587, 176.529, 176.642, 176.636, 176.711, 
    176.786, 176.538, 176.514, 176.701, 176.664, 176.816, 176.661, 176.875, 176.726, 176.815, 
    176.793, 176.793, 176.753, 176.589, 176.718, 176.629, 176.713, 176.654, 176.712, 176.704, 
    176.845, 176.733, 176.73, 176.847, 176.777, 176.805, 176.774, 176.72, 176.64, 176.831
]


# Wartości n
n_values = [i * 1000 for i in range(1, 51)]

# Wykres dla Quick - swap
plt.plot(n_values, quick_swap, label="Quick - Swap")
plt.xlabel("n")
plt.ylabel("Swap count")
plt.title("Quick Sort - Swap count vs n")
plt.legend()
plt.show()

# Wykres dla Quick - compare
plt.plot(n_values, quick_compare, label="Quick - Compare")
plt.xlabel("n")
plt.ylabel("Compare count")
plt.title("Quick Sort - Compare count vs n")
plt.legend()
plt.show()

# Wykres dla Hybrid - swap
plt.plot(n_values, hybrid_swap, label="Hybrid - Swap")
plt.xlabel("n")
plt.ylabel("Swap count")
plt.title("Hybrid Sort - Swap count vs n")
plt.legend()
plt.show()

# Wykres dla Hybrid - compare
plt.plot(n_values, hybrid_compare, label="Hybrid - Compare")
plt.xlabel("n")
plt.ylabel("Compare count")
plt.title("Hybrid Sort - Compare count vs n")
plt.legend()
plt.show()

# Wykres dla Tim - swap
plt.plot(n_values, tim_swap, label="Tim - Swap")
plt.xlabel("n")
plt.ylabel("Swap count")
plt.title("Tim Sort - Swap count vs n")
plt.legend()
plt.show()

# Wykres dla Tim - compare
plt.plot(n_values, tim_compare, label="Tim - Compare")
plt.xlabel("n")
plt.ylabel("Compare count")
plt.title("Tim Sort - Compare count vs n")
plt.legend()
plt.show()