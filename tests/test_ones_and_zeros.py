import dumbpy as dp

def test_ones_matrix():
    data = [[1, 1], [1, 1]]
    a = dp.ones(2, 2)

    assert len(a) == len(data), f"Expected {len(a)} to be {len(data)}"

    for i in range(len(data)):
        for j in range(len(data[i])):
            assert a[i][j] == data[i][j], f"Expected {a[i][j]} to be {data[i][j]}"
    
    b = dp.Matrix(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    print("Ones matrix test passed!")

def test_ones_vector():
    data = [1, 1, 1]
    a = dp.ones(3)

    assert len(a) == len(data), f"Expected {len(a)} to be {len(data)}"

    for i in range(len(data)):
        assert a[i] == data[i], f"Expected {a[i]} to be {data[i]}"
    
    b = dp.Vector(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    print("Ones vector test passed!")

def test_zeros_matrix():
    data = [[0, 0], [0, 0]]
    a = dp.zeros(2, 2)

    assert len(a) == len(data), f"Expected {len(a)} to be {len(data)}"

    for i in range(len(data)):
        for j in range(len(data[i])):
            assert a[i][j] == data[i][j], f"Expected {a[i][j]} to be {data[i][j]}"
    
    b = dp.Matrix(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    print("Zeros matrix test passed!")

def test_zeros_vector():
    data = [0, 0, 0]
    a = dp.zeros(3)

    assert len(a) == len(data), f"Expected {len(a)} to be {len(data)}"

    for i in range(len(data)):
        assert a[i] == data[i], f"Expected {a[i]} to be {data[i]}"
    
    b = dp.Vector(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    print("Zeros vector test passed!")
