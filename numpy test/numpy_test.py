"""Numpy test file"""
import numpy as np
import matplotlib.pyplot as plt

x_axis = np.linspace(-10, 10, 100)
y_axis = np.sin(x_axis)
print(x_axis, y_axis, sep="\n")

plt.plot(x_axis, y_axis, c="orange", label="y=sin(x)")
plt.axvline(x=0, c="black")
plt.axhline(y=0, c="black")
plt.legend()
plt.show()
