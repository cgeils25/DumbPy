import dumbpy as dp
import math

def test_relu():
    data = [[0, 1, -3], [-1, 2, -2], [-3, -4, 5]]
    expected_relu_output = [[0, 1, 0], [0, 2, 0], [0, 0, 5]]

    a = dp.Matrix(data)

    relu_output = dp.nn.activation.relu(a)

    assert relu_output == dp.Matrix(expected_relu_output), f"Expected {relu_output} to be {expected_relu_output}"
    print("ReLU test passed!")


def test_relu_gradient():
    data = [[0, 1, -3], [-1, 2, -2], [-3, -4, 5]]
    expected_relu_gradient = [[0, 1, 0], [0, 1, 0], [0, 0, 1]]

    a = dp.Matrix(data)

    relu_gradient = dp.nn.activation.relu_gradient(a)

    assert relu_gradient == dp.Matrix(expected_relu_gradient), f"Expected {relu_gradient} to be {expected_relu_gradient}"

    print("ReLU gradient test passed!")


def test_sigmoid():
    data = [[0, 1, -3], [-1, 2, -2], [-3, -4, 5]]
    sigmoid = lambda x: 1 / (1 + math.exp(-x))
    expected_sigmoid_output = dp.Matrix([[sigmoid(x) for x in row] for row in data])

    a = dp.Matrix(data)
    sigmoid_output = dp.nn.activation.sigmoid(a)

    assert dp.all_close(sigmoid_output, expected_sigmoid_output), f"Expected {sigmoid_output} to be {expected_sigmoid_output}"
    print("Sigmoid test passed!")


def test_sigmoid_gradient():
    data = [[0, 1, -3], [-1, 2, -2], [-3, -4, 5]]
    sigmoid = lambda x: 1 / (1 + math.exp(-x)) # not sure why I can't define this globally
    expected_sigmoid_gradient = dp.Matrix([[sigmoid(x) * (1 - sigmoid(x)) for x in row] for row in data])

    a = dp.Matrix(data)
    sigmoid_gradient = dp.nn.activation.sigmoid_gradient(a)

    assert dp.all_close(sigmoid_gradient, expected_sigmoid_gradient), f"Expected {sigmoid_gradient} to be {expected_sigmoid_gradient}"
    print("Sigmoid gradient test passed!")
