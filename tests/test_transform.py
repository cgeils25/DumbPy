import dumbpy as dp

def test_transpose():
    m = dp.Matrix([[1, 2, 3], [4, 5, 6]])

    result = dp.transform.transpose(m)

    expected_result = dp.Matrix([[1, 4], [2, 5], [3, 6]])

    assert result == expected_result, f"Expected {result} to be {expected_result}"

    result_T = dp.transform.transpose(result)

    assert result_T == m, f"Expected {result_T} to be {m} (m'' should be m)"

    print("Matrix transpose test passed!")