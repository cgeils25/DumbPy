import dumbpy as dp

dp.say_hello('Christian Geils')

data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# Create a scalar and set its value
print("Scalar:")
scalar = dp.Scalar(10)
scalar.print()

# Create a vector and set its values
print("Vector:")
v1 = dp.Vector(len(data))
v1.set_values(data[0])
v1.print()

v2 = dp.Vector(len(data[0]))
v2.set_values(data[1])

print(dp.math.dot_product(v1, v2))
dp.math.vector_add(v1, v2).print()
dp.math.vector_subtract(v1, v2).print()
dp.math.vector_multiply(v1, v2).print()
dp.math.vector_divide(v1, v2).print()
dp.math.vector_power(v1, v2).print()
dp.math.vector_sqrt(v1).print()
dp.math.vector_exp(v1).print()
dp.math.vector_ln(v1).print()
dp.math.vector_log(v1, v2).print()


# Create a matrix and set its values
m = dp.Matrix(len(data), len(data[0]))
m.set_values(data)
m.print()