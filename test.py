import dumbpy as dp

dp.say_hello('Christian Geils')

data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# Create a vector and set its values
print("Vector:")
v1 = dp.Vector(data[0])
v1.print()

v2 = dp.Vector(data[1])

print(dp.math.dot_product(v1, v2))
dp.math.add(v1, v2).print()
dp.math.subtract(v1, v2).print()
dp.math.multiply(v1, v2).print()
dp.math.divide(v1, v2).print()
dp.math.power(v1, v2).print()
dp.math.sqrt(v1).print()
dp.math.exp(v1).print()
dp.math.ln(v1).print()
dp.math.log(v1, v2).print()


# Create a matrix and set its values
print("Matrix:")
m = dp.Matrix(data)
m.print()