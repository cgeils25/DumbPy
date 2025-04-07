import dumbpy as dp
import math

def test_vector_add():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.add(a, b)
    assert c == dp.Vector([5, 7, 9]), f"Expected {c} to be [5, 7, 9]"

    d = dp.math.add(a, 2)

    assert d == dp.Vector([3, 4, 5]), f"Expected {d} to be [3, 4, 5]"

    print("Addition test passed!")

def test_vector_subtract():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.subtract(a, b)
    assert c == dp.Vector([-3, -3, -3]), f"Expected {c} to be [-3, -3, -3]"

    d = dp.math.subtract(a, 2)
    assert d == dp.Vector([-1, 0, 1]), f"Expected {d} to be [-1, 0, 1]"

    print("Subtraction test passed!")

def test_vector_multiply():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.multiply(a, b)
    assert c == dp.Vector([4, 10, 18]), f"Expected {c} to be [4, 10, 18]"

    d = dp.math.multiply(a, 2)
    assert d == dp.Vector([2, 4, 6]), f"Expected {d} to be [2, 4, 6]"

    print("Multiplication test passed!")

def test_vector_divide():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.divide(a, b)
    assert c == dp.Vector([0.25, 0.4, 0.5]), f"Expected {c} to be [0.25, 0.4, 0.5]"

    d = dp.math.divide(a, 2)
    assert d == dp.Vector([0.5, 1.0, 1.5]), f"Expected {d} to be [0.5, 1.0, 1.5]"

    try:
        dp.math.divide(a, 0)
    except Exception as e:
        pass
    else:
        raise AssertionError("Expected error for division by zero")

    print("Division test passed!")

def test_vector_dot_product():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.dot_product(a, b)
    assert c == 32, f"Expected {c} to be 32"

    print("Dot product test passed!")

def test_vector_sqrt():
    a = dp.Vector([1, 4, 9])
    b = dp.math.sqrt(a)
    assert b == dp.Vector([1.0, 2.0, 3.0]), f"Expected {b} to be [1.0, 2.0, 3.0]"

    print("Square root test passed!")

def test_vector_exp():
    a = dp.Vector([1, 2, 3])
    b = dp.math.exp(a)

    result = dp.Vector([math.exp(val) for val in a])

    assert b == result, f"Expected {b} to be {result}"

    print("Exponential test passed!")

def test_vector_ln():
    a = dp.Vector([1, 2, 3])
    result = dp.math.ln(a)

    expected_result = dp.Vector([math.log(val) for val in a])

    assert result == expected_result, f"Expected {result} to be {expected_result}"

    print("Natural logarithm test passed!")

def test_vector_log():
    a = dp.Vector([1.0, 2.0, 3.0])
    result = dp.math.log(a, 2.0)

    expected_result = dp.Vector([math.log(val, 2.0) for val in a])

    assert dp.all_close(v1=result, v2=expected_result, tolerance=.001), f"Expected {b} to be {expected_result}"

    b = dp.Vector([5.1, 6.2, 8.3])

    expected_result = dp.Vector([math.log(a_val, b_val) for a_val, b_val in zip(a, b)])

    result = dp.math.log(a, b)

    assert dp.all_close(v1=result, v2=expected_result, tolerance=.001), f"Expected {result} to be {expected_result}"

    print("Logarithm test passed!")

def test_vector_power():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.power(a, b)
    assert c == dp.Vector([a_val**b_val for a_val, b_val in zip(a, b)]), f"Expected {c} to be {[a_val**b_val for a_val, b_val in zip(a, b)]}"

    d = dp.math.power(a, 2)
    assert d == dp.Vector([a_val**2 for a_val in a]), f"Expected {d} to be {[a_val**2 for a_val in a]}"

    print("Power test passed!")
