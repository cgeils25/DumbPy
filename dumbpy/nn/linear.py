import dumbpy as dp
import math

class Linear:
    def __init__(self, input_size: int, output_size: int, random_seed: int = None):
        """Initialize a Linear layer with weights and bias using Xavier initialization.

        Args:
            input_size (int): _description_
            output_size (int): _description_
            random_seed (int, optional): _description_. Defaults to None.
        """
        self.input_size = input_size
        self.output_size = output_size

        xavier_upper_bound = (math.sqrt(6)) / (math.sqrt(input_size + output_size))

        if random_seed:
            generator = dp.random.Generator(random_seed)
        
        else:
            generator = dp.random.Generator()
        
        self.weights = generator.uniform(output_size, input_size, -xavier_upper_bound, xavier_upper_bound)
        
        self.bias = dp.zeros(output_size)

    def forward(self, x):
        return dp.math.add(dp.math.mat_mul(self.weights, x), self.bias)

    def __call__(self, x):
        # no real reason for this. Pytorch does some extra handling of the .forward function but I'm just doing it here because I like the API
        return self.forward(x)

    def __repr__(self):
        return f"<Linear block with {self.input_size} inputs and {self.output_size} outputs>"

