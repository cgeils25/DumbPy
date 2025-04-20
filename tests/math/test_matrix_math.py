import dumbpy as dp
import math

def test_matrix_add():
    # Test matrix addition
    a = dp.Matrix([[1, 2], [3, 4]])
    b = dp.Matrix([[5, 6], [7, 8]])
    c = dp.math.add(a, b)

    assert c == dp.Matrix([[6, 8], [10, 12]]), f"Expected {c} to be [[6, 8], [10, 12]]"

    d = dp.math.add(a, 2)

    assert d == dp.Matrix([[3, 4], [5, 6]]), f"Expected {d} to be [[3, 4], [5, 6]]"

    print("Matrix addition test passed!")

def test_matrix_subtract():
    # Test matrix subtraction
    a = dp.Matrix([[1, 2], [3, 4]])
    b = dp.Matrix([[5, 6], [7, 8]])
    c = dp.math.subtract(a, b)

    assert c == dp.Matrix([[-4, -4], [-4, -4]]), f"Expected {c} to be [[-4, -4], [-4, -4]]"

    d = dp.math.subtract(a, 2)
    assert d == dp.Matrix([[-1, 0], [1, 2]]), f"Expected {d} to be [[-1, 0], [1, 2]]"

    print("Matrix subtraction test passed!")

def test_matrix_multiply():
    # Test ELEMENT-WISE matrix multiplication
    a = dp.Matrix([[1, 2], [3, 4]])
    b = dp.Matrix([[5, 6], [7, 8]])
    c = dp.math.multiply(a, b)

    assert c == dp.Matrix([[5, 12], [21, 32]]), f"Expected {c} to be [[5, 12], [21, 32]]"

    d = dp.math.multiply(a, 2)
    assert d == dp.Matrix([[2, 4], [6, 8]]), f"Expected {d} to be [[2, 4], [6, 8]]"

    print("Matrix multiplication test passed!")

def test_matrix_divide():
    # Test matrix division
    a = dp.Matrix([[1, 2], [3, 4]])
    b = dp.Matrix([[5, 6], [7, 8]])
    result = dp.math.divide(a, b)

    expected_result = dp.Matrix([[0.2, 0.3333333333333333], [0.42857142857142855, 0.5]])

    assert dp.all_close(m1=result,  m2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    d = dp.math.divide(a, 2)

    assert d == dp.Matrix([[0.5, 1.0], [1.5, 2.0]]), f"Expected {d} to be [[0.5, 1.0], [1.5, 2.0]]"

    try:
        dp.math.divide(a, 0)
    except Exception as e:
        pass
    else:
        raise AssertionError("Expected error for division by zero")

    print("Matrix division test passed!")

def test_mat_multiply():
    # Test matrix multiplication
    a = dp.Matrix([[1, 2], [3, 4]])
    b = dp.Matrix([[5, 6], [7, 8]])
    result = dp.math.mat_mul(a, b)
    expected_result = dp.Matrix([[19, 22], [43, 50]])

    assert result == expected_result, f"Expected {result} to be {expected_result}"

    # Test matrix-vector multiplication
    v = dp.Vector([1, 2])

    result = dp.math.mat_mul(a, v)
    expected_result = dp.Vector([5, 11])

    assert result == expected_result, f"Expected {result} to be {expected_result}"

    print("Matrix multiplication test passed!")

def test_matrix_exp():
    # Test matrix exponential
    a = dp.Matrix([[1, 2], [3, 4]])
    result = dp.math.exp(a)

    expected_result = dp.Matrix([[math.exp(1), math.exp(2)], [math.exp(3), math.exp(4)]])

    assert dp.all_close(m1=result, m2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    print("Matrix exponential test passed!")

def test_matrix_ln():
    # Test matrix natural logarithm
    a = dp.Matrix([[1, 2], [3, 4]])
    result = dp.math.ln(a)

    expected_result = dp.Matrix([[math.log(1), math.log(2)], [math.log(3), math.log(4)]])

    assert dp.all_close(m1=result, m2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    print("Matrix natural logarithm test passed!")

def test_matrix_log():
    # Test matrix logarithm with base 2
    a = dp.Matrix([[1.0, 2.0], [3.0, 4.0]])
    result = dp.math.log(a, 2.0)

    expected_result = dp.Matrix([[math.log(val, 2.0) for val in row] for row in a])

    assert dp.all_close(m1=result, m2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    # test element-wise logarithm 
    b = dp.Matrix([[5.1, 6.2], [8.3, 9.4]])
    expected_result = dp.Matrix([[math.log(a_val, b_val) for a_val, b_val in zip(row_a, row_b)] for row_a, row_b in zip(a, b)])
    result = dp.math.log(a, b)
    assert dp.all_close(m1=result, m2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    print("Matrix logarithm test passed!")

def test_matrix_power():
    # Test matrix power with scalar
    a = dp.Matrix([[1, 2], [3, 4]])
    result = dp.math.power(a, 2)
    expected_result = dp.Matrix([[1**2, 2**2], [3**2, 4**2]])

    assert result == expected_result, f"Expected {result} to be {expected_result}"

    # Test element-wise matrix power
    b = dp.Matrix([[2, 3], [4, 5]])
    result = dp.math.power(a, b)

    expected_result = dp.Matrix([[a_val**b_val for a_val, b_val in zip(row_a, row_b)] for row_a, row_b in zip(a, b)])

    assert result == expected_result, f"Expected {result} to be {expected_result}"

    print("Matrix power test passed!")

def test_matrix_sqrt():
    # Test matrix square root
    a = dp.Matrix([[1, 4], [9, 16]])
    result = dp.math.sqrt(a)

    expected_result = dp.Matrix([[math.sqrt(val) for val in row] for row in a])

    assert dp.all_close(m1=result, m2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    print("Matrix square root test passed!")
