"""Complex numbers"""

import matplotlib.pyplot as plt

class Complex:
    """Complex number data type"""
    def __init__(self, real: float, imm: float, name: str = "z") -> None:
        self.real = real
        self.imm = imm
        self.name = name

    def plot(self, color: str = "blue"):
        "plot the complex number"
        if self.imm >= 0:
            label = f"{self.name} = {self.real} + {self.imm}i"
        else:
            label = f"{self.name} = {self.real} - {-1 * self.imm}i"
        plt.plot(self.real, self.imm, "o", c=color, label=label)
        plt.axvline(x=0, c="black")
        plt.axhline(y=0, c="black")
        plt.legend()
        plt.show()
