import dumbpy as dp

def test_identity_matrix_instantiation():
    data = [[1, 0], [0, 1]]
    a = dp.identity(2)

    assert len(a) == len(data), f"Expected {len(a)} to be {len(data)}"

    for i in range(len(data)):
        for j in range(len(data[i])):
            assert a[i][j] == data[i][j], f"Expected {a[i][j]} to be {data[i][j]}"
    
    b = dp.Matrix(data)

    assert a == b, f"Expected {a} to be equal to {b}"

    print("Identity matrix instantiation test passed!")


def test_identity_matrix_properties():
    # is A @ I = A ?
    data = [[1, 2, 3], [0, 1, 4], [0, 82, 1]]
    
    m = dp.Matrix(data)

    a = dp.identity(3)

    result = dp.math.mat_mul(a, m)

    assert result == m, f"Expected {result} to be equal to {m}"

    print("Identity matrix properties test passed!")
