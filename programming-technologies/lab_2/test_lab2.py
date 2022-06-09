import unittest
import lab2
class TEST_LAB2_VAR_910(unittest.TestCase):
    def test_1(self):
        self.assertEqual(lab2.LAB2_VAR_910(0), 7.0 )
    def test_2(self):
        self.assertEqual(lab2.LAB2_VAR_910(1.2), -33.32 )
    def test_3(self):
        with self.assertRaises(TypeError):
            lab2.LAB2_VAR_910("var")
    def test_4(self):
        self.assertEqual(lab2.LAB2_VAR_910(True), TypeError)
    def test_5(self):
        with self.assertRaises(TypeError):
            lab2.LAB2_VAR_910([1])