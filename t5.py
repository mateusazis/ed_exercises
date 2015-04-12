import unittest
from q5 import *

class TestQ5(unittest.TestCase):

  def test_upper(self):
        l = [1,2,3,4]
        inv = l[::-1]
        self.assertEqual(inv, to_list(invert(create_list(l))))

unittest.main()