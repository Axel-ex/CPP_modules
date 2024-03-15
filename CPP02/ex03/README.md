# Exercise03: BSP

This exercice implements a function to determine whether a given point lies inside a triangle or not. It includes the implementation of a `Point` class in Orthodox Canonical Form to represent 2D points.

## Point Class

The `Point` class represents a 2D point with fixed-point coordinates. It has the following characteristics:

### Private Members
- `x`: A constant fixed-point attribute representing the x-coordinate.
- `y`: A constant fixed-point attribute representing the y-coordinate.

### Public Members
- Default constructor: Initializes both `x` and `y` to 0.
- Constructor with parameters: Takes two constant floating-point numbers and initializes `x` and `y` with them.
- Copy constructor
- Copy assignment operator overload
- Destructor

## Inside Triangle Function

The function `bsp(Point const a, Point const b, Point const c, Point const point)` checks whether a given point `point` lies inside the triangle formed by the vertices `a`, `b`, and `c`. It returns `true` if the point is inside the triangle and `false` otherwise.

### Parameters
- `a`, `b`, `c`: Vertices of the triangle.
- `point`: Point to be checked.

### Return Value
- `true` if the point is inside the triangle.
- `false` otherwise.

## Implementation Details

The `GetTriangleArea` function calculates the area of the triangle formed by three points using the formula:

```math
A = |[x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2)] / 2|
```

The `bsp` function calculates the areas of sub-triangles formed by the given point and the vertices of the triangle. It then checks if the sum of these areas is equal to the area of the main triangle, indicating that the point lies inside the triangle. Additionally, it checks if the point lies on any of the triangle edges.

## Testing
Unit tests have been implemented to ensure that the `Point` class and the `bsp` function behave as expected in different scenarios.

