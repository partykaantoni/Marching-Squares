# Implementation of the Marching Squares algorithm in C

This project is an implementation of the Marching Squares algorithm in C.  
The algorithm is used to generate contours in a two-dimensional grid of points based on scalar values.  
It was implemented as a console program using only standard C input/output functions.

---

## Description of operation

The Marching Squares algorithm analyzes successive squares composed of four adjacent points in the grid.  
Each of these points has a binary value.  
Based on the combination of these values, it is determined which edges of a given square are crossed by the contour line.

In the implementation:
1. A grid of points with random values of 0 and 1 is generated.  
2. Each set of four adjacent points forms a `Square` structure.  
3. For each square, its state (`all`) is calculated based on the sum and distribution of the corner values.  
4. The `segmentSquare()` function creates a lookup table that specifies the interpolation method for each configuration.  
5. Based on this, the resulting “screen” is built, which represents the contours in the form of ASCII characters.

The program prints the following to the console:
- a grid of input points,
- the resulting contour map.
