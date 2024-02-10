import random
import math

# File path for saving
file_path = 'A.in'

# Function to generate points on a circle
def generate_circle_points(radius, center, n):
    points = []
    for i in range(n):
        angle = 2 * math.pi * i / n
        x = center[0] + radius * math.cos(angle)
        y = center[1] + radius * math.sin(angle)
        points.append((int(x), int(y)))
    return points

# Generate 100,000 points on a circle
radius = 5000000  # Large radius to ensure points are spread out
center = (5000000, 5000000)  # Center of the circle
n_points = 100000
circle_points = generate_circle_points(radius, center, n_points)

# Open file for writing
with open(file_path, 'w') as file:
    # Write the number of points for each set, they are the same
    file.write(f"{n_points} {n_points}\n")

    # Write the generated points for the first set
    for point in circle_points:
        file.write(f"{point[0]} {point[1]}\n")

    # Write the generated points for the second set (same points)
    for point in circle_points:
        file.write(f"{point[0]} {point[1]}\n")

# Output the file path
file_path