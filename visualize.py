import numpy as np
import matplotlib.pyplot as plt
import argparse

# Convert hex value (e.g., 0x1042) to RGB565 format
def hex_to_rgb565(hex_value):
    # Extract the red, green, and blue parts from the 16-bit hex value
    red = (hex_value >> 11) & 0x1F  # 5 bits
    green = (hex_value >> 5) & 0x3F  # 6 bits
    blue = hex_value & 0x1F  # 5 bits

    # Normalize the values to 0-255 range (for RGB)
    red = int((red / 31) * 255)
    green = int((green / 63) * 255)
    blue = int((blue / 31) * 255)

    return [red, green, blue]

# Read the file and parse hex values
def read_file_to_matrix(file_path):
    matrix = []
    with open(file_path, 'r') as file:
        for line in file:
            # Split each line by spaces and convert hex values to RGB
            row = [hex_to_rgb565(int(value, 16)) for value in line.split()]
            matrix.append(row)
    return np.array(matrix)

# Parse command-line arguments
parser = argparse.ArgumentParser(description="Plot a color matrix from a file containing hex values.")
parser.add_argument("file_path", help="Path to the file containing hex values.")
args = parser.parse_args()

# Read the hex values and convert to RGB matrix
color_matrix = read_file_to_matrix(args.file_path)

# Plot the result
fig, ax = plt.subplots(figsize=(8, 8))
ax.imshow(color_matrix, origin='upper')
ax.axis("off")
ax.set_title(f"Color Matrix: {color_matrix.shape[1]} x {color_matrix.shape[0]}", fontsize=16)
plt.show()
