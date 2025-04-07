import dumbpy as dp

v = dp.Vector(3)

v.set_values([1, 2, 3])

r = dp.math.add(v, v)

r.print()

r = dp.math.subtract(v, 2)

r.print()

print('Attempting to get item ')

print(r[0])

r[0] = 10

print(r[0])