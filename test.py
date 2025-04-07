from tests import test_vector, test_matrix, test_vector_math, test_matrix_math

def run_functions_in_module(module):
    for i in dir(module):
        item = getattr(module,i)
        if callable(item):
            item()

def main():
    print("-"*50, "Testing vector class...", "-"*50)
    run_functions_in_module(test_vector)

    print("-"*50, "Testing matrix class...", "-"*50)
    run_functions_in_module(test_matrix)

    print("-"*50, "Testing vector math...", "-"*50)
    run_functions_in_module(test_vector_math)

    print("-"*50, "Testing matrix math...", "-"*50)
    run_functions_in_module(test_matrix_math)
    

if __name__ == "__main__":
    main()