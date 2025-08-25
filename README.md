# Gradient Generator

## Overview

This project provides a command-line application that generates a text
file containing a color gradient matrix.
Each pixel is represented as a 16-bit RGB565 value, interpolated between
four corner colors.

Additionally, the project includes a helper script **visualize.py** for
rendering the generated matrix as an image.

## Usage

``` bash
program.exe <image_width> <image_height> <tl> <tr> <bl> <br> <output_path>
```

-   `<tl>` -- top-left pixel color
-   `<tr>` -- top-right pixel color
-   `<bl>` -- bottom-left pixel color
-   `<br>` -- bottom-right pixel color
-   Color values may be provided as **hex** (e.g., `0xf800`) or
    **decimal**.

### Examples

``` bash
program.exe 16 16 0x0 0xf 0x0 0xf ./file.txt
program.exe 32 32 3000 6000 9000 12000 ./file.txt
```

## Output

-   A text file containing a matrix of size
    `<image_width> x <image_height>`
-   Each pixel value in **hex**, space-separated per row
-   Linear interpolation ensures corners match the input colors

Example (simplified):

    0xf   0xf   ...  0xf
    0xfa  0xfb  ...  0xfc
    ...

## Color Format (RGB565)

-   **White**: `0xffff`
-   **Black**: `0x0000`
-   **Red**: `0xf800`
-   **Green**: `0x07e0`
-   **Blue**: `0x001f`

## Visualization (visualize.py)

A Python script is provided to display the generated gradient file as an
image.

### Requirements

Install dependencies with:

``` bash
pip install numpy matplotlib
```

### Usage

``` bash
python visualize.py ./file.txt
```

This will open a matplotlib window showing the gradient with dimensions
labeled.
