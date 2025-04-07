import dumbpy as dp

def test_vector_add():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.add(a, b)
    assert c == dp.Vector([5, 7, 9]), f"Expected {c} to be [5, 7, 9]"

    d = dp.math.add(a, 2)

    assert d == dp.Vector([3, 4, 5]), f"Expected {d} to be [3, 4, 5]"

    print("Addition test passed!")

def test_vector_sub():
    a = dp.Vector([1, 2, 3])
    b = dp.Vector([4, 5, 6])
    c = dp.math.subtract(a, b)
    assert c == dp.Vector([-3, -3, -3]), f"Expected {c} to be [-3, -3, -3]"

    d = dp.math.subtract(a, 2)
    assert d == dp.Vector([-1, 0, 1]), f"Expected {d} to be [-1, 0, 1]"

    print("Subtraction test passed!")