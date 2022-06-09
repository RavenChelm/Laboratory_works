import unittest
import lab5
class TEST_LAB5_VAR_1(unittest.TestCase):
    def test_1(self):
        self.assertEqual(lab5.LAB5_VAR_1([1, 2, 3, 4, 5]), 15)
    def test_2(self):
        self.assertEqual(lab5.LAB5_VAR_1([1, 2, 3.5, 4, 5]), 15.5)
    def test_3(self):
        self.assertEqual(lab5.LAB5_VAR_1([1, 2, 3, 4, 6, 5]), 16)
    def test_4(self):
        self.assertEqual(lab5.LAB5_VAR_1([5, 4, 3, 2, 1]), 15)
    def test_5(self):
        self.assertEqual(lab5.LAB5_VAR_1([1, "F", 3, 4, 5]), ValueError)