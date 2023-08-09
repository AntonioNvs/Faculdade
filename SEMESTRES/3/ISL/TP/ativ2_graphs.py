import numpy as np
import matplotlib.pyplot as plt

pol1 = np.array([15, 14, 12, 8, 1, 2, 4, 9, 3, 6, 13, 10, 5, 11, 7, 15, 14, 12, 8, 1, 2, 4, 9, 3, 6, 13, 10, 5, 11, 7, 15, 14, 12, 8, 1, 2, 4, 9, 3, 6, 13, 10, 5, 11, 7, 15, 14, 12, 8, 1, 2, 4, 9, 3, 6, 13, 10, 5, 11, 7, 15, 14, 12, 8, 1])
size1 = np.array(list(range(0, pol1.shape[0])))

pol2 = np.array([1, 2, 4, 8, 16, 33, 3, 6, 12, 24, 49, 34, 5, 10, 20, 41, 19, 39, 15, 30, 61, 58, 52, 40, 17, 35, 7, 14, 28, 57, 50, 36, 9, 18, 37, 11, 22, 45, 27, 55, 46, 29, 59, 54, 44, 25, 51, 38, 13, 26, 53, 42, 21, 43, 23, 47, 31, 63, 62, 60, 56, 48, 32])
size2 = np.array(list(range(0, pol2.shape[0])))

pol3 = np.array([1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3])
size3 = np.array(list(range(0, pol3.shape[0])))

plt.plot(size3, pol3, marker='o', color='blue', linestyle='--')
plt.title("Polinômio x^2 + x + 1")
plt.xlabel("Ocorrência")
plt.ylabel("Número decimal gerado")
plt.show()