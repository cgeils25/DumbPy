import dumbpy as dp
from timeit import timeit
import random


def matmul(a, b):
    result = []

    for i in range(len(a)):
        result.append([0] * len(b[0]))
        for j in range(len(b[0])):
            for k in range(len(b)):
                result[i][j] += a[i][k] * b[k][j]
    
    return result


def benchmark_matmul(a: list, b: list, iterations: int = 1000):
    py_time = timeit(lambda: matmul(a, b), number=iterations)

    a_dp = dp.Matrix(a)
    b_dp = dp.Matrix(b)

    dp_time = timeit(lambda: dp.math.mat_mul(a_dp, b_dp), number=iterations)

    return py_time, dp_time


def test_result(a, b):
    try:
        out_py = matmul(a, b)

        a_dp = dp.Matrix(a)
        b_dp = dp.Matrix(b)
        out_dp = dp.math.mat_mul(a_dp, b_dp)

        assert dp.all_close(dp.Matrix(out_py), out_dp, 1e-4), "Results do not match!"
    
    except Exception as e:
        print(f"Test failed with exception: {e}")
        raise


def main():
    n_iterations = 100
    n_rows = 300
    n_cols = 100

    a = [[random.random() for _ in range(n_cols)] for _ in range(n_rows)]
    b = [[random.random() for _ in range(n_rows)] for _ in range(n_cols)]
    
    print('-' * 100)
    print("Testing that matrix multiplication results match for python and DumbPy:")
    test_result(a, b)
    print("Test passed!")

    print('-' * 100)
    print("Matrix Multiplication Benchmark:")
    py_time, dp_time = benchmark_matmul(a, b, iterations=n_iterations)
    print(f"Python time: {round(py_time, 3)} seconds")
    print(f"DumbPy time: {round(dp_time, 3)} seconds")

if __name__ == "__main__":
    main()