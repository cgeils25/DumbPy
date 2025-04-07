import dumbpy as dp

def test_instantiation():
    data = [1, 2, 3]

    a = dp.Vector(data)

    isinstance(a, dp.Vector), f"Expected {a} to be an instance of Vector"

    print("Instantiation test passed!")

def test_setitem():
    data = [1, 2, 3]
    a = dp.Vector(data)

    assert a[1] == data[1], f"Expected {a[1]} to be {data[1]}"

    new_val = 4

    a[1] = new_val

    assert a[1] == new_val, f"Expected {a[1]} to be 4"

    assert a[1] != data[1], f"Expected {a[1]} to be not equal to {data[1]}"

    print("Set item test passed!")

def test_equality():
    data = [1, 2, 3]

    a = dp.Vector(data)
    b = dp.Vector(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    a[0] = 2

    assert a != b, f"Expected {a} to be not equal to {b}"

    print("Equality test passed!")

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

if __name__ == "__main__":
    print("-"*50, "Testing matrix math...", "-"*50)

    test_instantiation()
    test_setitem()
    test_equality()
    test_vector_add()
    test_vector_sub()
