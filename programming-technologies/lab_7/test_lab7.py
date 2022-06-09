import unittest
import lab7
class TEST_LAB7_VAR_3(unittest.TestCase):
    def test_1(self):
        self.assertEqual(lab7.LAB7_VAR_3(87, 34, 300, 35, 84), "Успешное построение графика")
    def test_2(self):
        self.assertEqual(lab7.LAB7_VAR_3("one", "two", 3, 4, 5), ValueError)
    def test_3(self):
        self.assertEqual(lab7.LAB7_VAR_3([1], [2], 3, 4, 5), ValueError)
    def test_4(self):
        self.assertEqual(lab7.LAB7_VAR_3([1], [2, 0], 3, 4, 5), ValueError)
    def test_5(self):
        self.assertEqual(lab7.LAB7_VAR_3(87, 34, -1, 35, 84), ValueError)
    def test_6(self):
        self.assertEqual(lab7.LAB7_VAR_3(87, 34, 500, 0.1, 84), ValueError)
    def test_7(self):
        self.assertEqual(lab7.LAB7_VAR_3(87, 34, 300, 84, 35), ValueError)