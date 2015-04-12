#! python

import unittest
from q6 import *
from q5 import *

class TestQ6(unittest.TestCase):

  def test_first(self):
        l = [1,2,3,4]
        swapped = [2,1,3,4]
        self.assertEqual(swapped, to_list(swap(create_list(l), 0)))

  def test_basic(self):
        l = [1,2,3,4]
        swapped = [1,3,2,4]
        self.assertEqual(swapped, to_list(swap(create_list(l), 1)))

  def test_end(self):
        l = [1,2,3,4]
        with self.assertRaisesRegexp(Exception, 'Invalid list position to swap.'):
            swap(create_list(l), 3)

  def test_vazia(self):
        l = []
        with self.assertRaisesRegexp(Exception, 'Invalid list position to swap.'):
            swap(create_list(l), 0)

  def test_1_element(self):
        l = [23]
        with self.assertRaisesRegexp(Exception, 'Invalid list position to swap.'):
            swap(create_list(l), 0)


  def test_last_plus_one(self):
        l = [1,2,3,4]
        with self.assertRaisesRegexp(Exception, 'Invalid list position to swap.'):
            swap(create_list(l), 4)

unittest.main()