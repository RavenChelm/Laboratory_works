import unittest
import lab8
class TEST_LAB8_VAR_1(unittest.TestCase):
    def test_1(self):
        self.assertEqual(lab8.LAB8_VAR_1(2), "successful")
    def test_2(self):
        self.assertEqual(lab8.LAB8_VAR_1(-1), ValueError)
    def test_3(self):
        self.assertEqual(lab8.LAB8_VAR_1("one"), ValueError)
    def test_4(self):
        self.assertEqual(lab8.LAB8_VAR_1([1]), ValueError)
    def test_5(self):
        self.assertEqual(lab8.LAB8_VAR_1(1.5), ValueError)
    def test_6(self):
        self.assertEqual(lab8.LAB8_VAR_1(42), ValueError)