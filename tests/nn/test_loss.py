import dumbpy as dp
import math

def test_mse_loss():
    y_true_list = [-2, -3, 1, 2, 3, 4]
    y_pred_list = [y_true_list[i] + (.1 * (-1 ** i)) for i in range(len(y_true_list))] # alternate adding and subtracting .1

    y_true = dp.Vector(y_true_list)
    y_pred = dp.Vector(y_pred_list)
    
    loss = dp.nn.loss.mse(y_true, y_pred)

    expected_loss = (.1 ** 2)

    # Assert the result
    assert abs(loss - expected_loss) < .0001 , f"Expected {loss} to be close to {expected_loss}"
    print("MSE loss test passed!")


def test_mse_gradient():
    y_true_list = [-2, -3, 1, 2, 3, 4]
    y_pred_list = [y_true_list[i] + (.1 * (-1 ** i)) for i in range(len(y_true_list))] # alternate adding and subtracting .1

    y_true = dp.Vector(y_true_list)
    y_pred = dp.Vector(y_pred_list)
    
    gradient = dp.nn.loss.mse_gradient(y_true, y_pred)

    expected_gradient = dp.Vector([-.2 for _ in range(len(y_true_list))])

    # Assert the result
    assert dp.all_close(gradient, expected_gradient), f"Expected {gradient} to be close to {expected_gradient}"
    print("MSE loss test passed!")
    