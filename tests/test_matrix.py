import dumbpy as dp

def test_instantiation():
    data = [[1, 2, 3], [4, 5, 6]]

    a = dp.Matrix(data)

    assert isinstance(a, dp.Matrix), f"Expected {a} to be an instance of Matrix"

    print("Instantiation test passed!")

def test_len():
    data = [[1, 2, 3], [4, 5, 6]]

    a = dp.Matrix(data)

    assert len(a) == len(data), f"Expected {len(a)} to be {len(data)}"

    print("Len test passed!")

def test_getitem():
    data = [[1, 2, 3], [4, 5, 6]]

    v = dp.Matrix(data)

    for i in range(len(data)):
        for j in range(len(data[i])):
            assert v[i][j] == data[i][j], f"Expected {v[i][j]} to be {data[i][j]}"
    
    print("Get item test passed!")

def test_setitem():
    data = [[1, 2, 3], [4, 5, 6]]
    a = dp.Matrix(data)

    assert a[1][1] == data[1][1], f"Expected {a[1][1]} to be {data[1][1]}"

    new_val = 4

    a[1, 1] = new_val

    assert a[1, 1] == new_val, f"Expected {a[1, 1]} to be 4"

    assert a[1, 1] != data[1][1], f"Expected {a[1, 1]} to be not equal to {data[1][1]}"

    print("Set item test passed!")

def test_equality():
    data = [[1, 2, 3], [4, 5, 6]]

    a = dp.Matrix(data)
    b = dp.Matrix(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    a[0, 0] = 2

    assert a != b, f"Expected {a} to be not equal to {b}"

    print("Equality test passed!")

def test_repr():
    # tried to make this pretty broad. Just makes sure the value is in the representation and the output is a string
    data = [[1, 2, 3], [4, 5, 6]]

    a = dp.Matrix(data)

    repr_out = repr(a)

    assert isinstance(repr_out, str), f"Expected {repr(a)} to be a string"

    for row in data:
        for value in row:
            assert str(value) in repr_out, f"Expected {value} to be in {repr_out}"

    print("Repr test passed!")