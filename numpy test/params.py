"""numpy testing"""
import numpy as np
import matplotlib.pyplot as plt

t_values = np.arange(100, step=0.5)

x_exponents = t_values ** (1 / 1 - t_values)
x_values = np.arange(100, step=0.5) ** x_exponents

y_exponents = t_values ** (t_values / 1 - t_values)
y_values = np.arange(100, step=0.5) ** y_exponents
