import dumbpy as dp
data = [[1, 2], [3, 4]]
m1 = dp.Matrix(2, 2)
m1.set_values(data)
print(m1)

r = dp.math.add(m1, m1)

print(r)