import dumbpy as dp

SEED = 1738

def test_random_generator_seed_normal():
    # Test that random seed allows reproducibility
    
    # default (standard normal)
    num_rows = 10
    num_cols = 10
    generator_1 = dp.random.Generator(SEED)
    generator_2 = dp.random.Generator(SEED)

    v1 = generator_1.normal(num_rows)
    v2 = generator_2.normal(num_rows)

    assert v1 == v2, f"Expected {v1} to equal {v2}"

    m1 = generator_1.normal(num_rows, num_cols)
    m2 = generator_2.normal(num_rows, num_cols)
    assert m1 == m2, f"Expected {m1} to equal {m2}"

    # specified mean and std
    mean = 5
    std = .5
    
    generator_3 = dp.random.Generator(SEED)
    generator_4 = dp.random.Generator(SEED)

    v3 = generator_3.normal(num_rows, mean, std)
    v4 = generator_4.normal(num_rows, mean, std)

    assert v3 == v4, f"Expected {v3} to equal {v4}"

    m3 = generator_3.normal(num_rows, num_cols, mean, std)
    m4 = generator_4.normal(num_rows, num_cols, mean, std)

    assert m3 == m4, f"Expected {m3} to equal {m4}"

    print("Random generator seed test passed for normal distribution!")


def test_random_generator_seed_uniform():
    # Test that random seed allows reproducibility
    
    # default (standard normal)
    num_rows = 10
    num_cols = 10
    generator_1 = dp.random.Generator(SEED)
    generator_2 = dp.random.Generator(SEED)

    v1 = generator_1.uniform(num_rows)
    v2 = generator_2.uniform(num_rows)

    assert v1 == v2, f"Expected {v1} to equal {v2}"

    m1 = generator_1.uniform(num_rows, num_cols)
    m2 = generator_2.uniform(num_rows, num_cols)
    assert m1 == m2, f"Expected {m1} to equal {m2}"

    # specified mean and std
    low = -3
    high = 8
    
    generator_3 = dp.random.Generator(SEED)
    generator_4 = dp.random.Generator(SEED)

    v3 = generator_3.uniform(num_rows, low, high)
    v4 = generator_4.uniform(num_rows, low, high)

    assert v3 == v4, f"Expected {v3} to equal {v4}"

    m3 = generator_3.uniform(num_rows, num_cols, low, high)
    m4 = generator_4.uniform(num_rows, num_cols, low, high)

    assert m3 == m4, f"Expected {m3} to equal {m4}"

    print("Random generator seed test passed for uniform distribution!")


def test_normal_matrix_given_mean_std():
    num_matrices = 1000
    mean = 5
    std = .5
    num_rows = 25
    num_cols = 50

    results = []

    generator = dp.random.Generator(SEED)

    for _ in range(num_matrices):
        result = generator.normal(num_rows, num_cols, mean, std)
        results.append(result)
        
    expected_means = dp.math.multiply(dp.ones(num_rows, num_cols), mean)
    expected_stds = dp.math.multiply(dp.ones(num_rows, num_cols), std)
    
    actual_means = dp.zeros(num_rows, num_cols)

    for matrix in results:
        actual_means = dp.math.add(actual_means, matrix)
    
    actual_means = dp.math.divide(actual_means, num_matrices)

    assert dp.all_close(actual_means, expected_means, .1), f"Expected means to be close to {expected_means}, but got {actual_means}"

    actual_stds = dp.zeros(num_rows, num_cols)
    for matrix in results:
        actual_stds = dp.math.add(actual_stds, dp.math.power(dp.math.subtract(matrix, expected_means), 2))
    
    actual_stds = dp.math.divide(actual_stds, num_matrices)

    actual_stds = dp.math.sqrt(actual_stds)

    assert dp.all_close(actual_stds, expected_stds, .1), f"Expected stds to be close to {expected_stds}, but got {actual_stds}"

    print("Normal matrix generation test passed!")


def test_uniform_matrix_given_low_high():
    num_matrices = 10_000
    low = -3
    high = 2
    num_rows = 25
    num_cols = 50

    results = []

    generator = dp.random.Generator(SEED)

    for _ in range(num_matrices):
        result = generator.uniform(num_rows, num_cols, low, high)
        results.append(result)
        
    expected_low = dp.math.multiply(dp.ones(num_rows, num_cols), low)
    expected_high = dp.math.multiply(dp.ones(num_rows, num_cols), high)
    expected_mean = dp.math.multiply(dp.ones(num_rows, num_cols), (low + high) / 2)

    actual_low = dp.math.multiply(dp.ones(num_rows, num_cols), high)
    actual_high = dp.math.multiply(dp.ones(num_rows, num_cols), low)
    actual_mean = dp.zeros(num_rows, num_cols)

    for matrix in results:
        actual_low = dp.math.min(actual_low, matrix)
        actual_high = dp.math.max(actual_high, matrix)
        actual_mean = dp.math.add(actual_mean, matrix)

    actual_mean = dp.math.divide(actual_mean, num_matrices)
    
    assert dp.all_close(actual_low, expected_low, .1), f"Expected low to be close to {expected_low}, but got {actual_low}"
    assert dp.all_close(actual_high, expected_high, .1), f"Expected high to be close to {expected_high}, but got {actual_high}"
    assert dp.all_close(actual_mean, expected_mean, .1), f"Expected mean to be close to {expected_mean}, but got {actual_mean}"

    print("Uniform matrix generation test passed!")
