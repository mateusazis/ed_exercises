import unittest
from q3 import find_modo

class TestQ2(unittest.TestCase):

  def test_upper(self):
      self.assertEqual(8, find_modo([2,7,8,6,8]))
      self.assertEqual(3, find_modo([2,3,7,8,6,8,3,3]))
      self.assertEqual(2, find_modo([2]))
      self.assertEqual(None, find_modo([]))

unittest.main()