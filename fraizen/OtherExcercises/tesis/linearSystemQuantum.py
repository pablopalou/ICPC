import numpy as np
from qiskit import QuantumCircuit, transpile, Aer, execute
from qiskit.algorithms.linear_solvers.hhl import HHL
from qiskit.opflow import MatrixOp
from qiskit.algorithms.linear_solvers.numpy_linear_solver import NumPyLinearSolver
from qiskit.algorithms.linear_solvers.observable import LinearSystemObservable
from qiskit.algorithms.eigen_solvers import NumPyEigensolver
from qiskit.algorithms.linear_solvers.hhl import HHL
# from qiskit.aqua import run_algorithm

# Define the linear system
A = np.array([[1, 2], [3, 4]])
b = np.array([5, 6])

# Create a MatrixOp object
matrix_operator = MatrixOp(A)

# Create an HHL object
hhl = HHL(matrix_operator)

# Execute the HHL algorithm
backend = Aer.get_backend('statevector_simulator')
result = hhl.solve(matrix_operator, b, backend)
print("Quantum Solution:", result)