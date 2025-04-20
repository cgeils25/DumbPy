from tests import test_vector, test_matrix, test_transform, test_ones_and_zeros, test_identity, test_random
from tests.math import test_vector_math, test_matrix_math

def run_functions_in_module(module):
    for i in dir(module):
        item = getattr(module,i)
        if callable(item):
            item()

def main():
    print("="*125)
    print('Running DumbPy unit tests...')
    print("="*125)

    print("-"*50, "Testing vector class...", "-"*50)
    run_functions_in_module(test_vector)

    print("-"*50, "Testing matrix class...", "-"*50)
    run_functions_in_module(test_matrix)

    print("-"*50, "Testing vector math...", "-"*50)
    run_functions_in_module(test_vector_math)

    print("-"*50, "Testing matrix math...", "-"*50)
    run_functions_in_module(test_matrix_math)

    print("-"*50, "Testing transformations...", "-"*50)
    run_functions_in_module(test_transform)

    print("-"*50, "Testing ones and zeros...", "-"*50)
    run_functions_in_module(test_ones_and_zeros)

    print("-"*50, "Testing identity matrix...", "-"*50)
    run_functions_in_module(test_identity)

    print("-"*50, "Testing random matrix and vector generation...", "-"*50)
    run_functions_in_module(test_random)

    print("="*125)
    print("All tests completed.")
    

if __name__ == "__main__":
    main()