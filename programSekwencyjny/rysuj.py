from matplotlib import pyplot as plt


import numpy as np

dane = np.loadtxt("rozklad.txt")

plt.title("Rozklad temperatury metoda Monte Carlo")
plt.xlabel("nr. wezla X")
plt.ylabel("nr. wezla Y")


plt.imshow(dane)
plt.colorbar()
plt.savefig("rozklad.png")
plt.show()




# plt.step(zapis[0], zapis[1], "r", label="A")

# plt.xlabel("wezel X")
# plt.ylabel("wezel Y")
# plt.grid()

# plt.legend()

# plt.savefig("rozkald.png")
# plt.show()