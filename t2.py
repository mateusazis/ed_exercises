import unittest
from q2 import perfect_square

squares = [1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024]

class TestQ2(unittest.TestCase):

  def test_upper(self):
      for i in range(1, squares[-1]):
          self.assertEqual(i in squares, perfect_square(i), "Testing %d" % i)

if __name__ == '__main__':
    unittest.main()