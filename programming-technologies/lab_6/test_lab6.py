import unittest
import lab6
class TEST_LAB6_VAR_1(unittest.TestCase):
    def test_1(self):
        self.assertEqual(lab6.LAB6_VAR_1([[1, 2], [3, 4]], [[5, 6], [7, 8]]), [[19.0, 22.0], [43.0, 50.0]])
    def test_2(self):
        self.assertEqual(lab6.LAB6_VAR_1([["one", "two"], [3, 4]], [[5, 6], [7, 8]]), ValueError)
    def test_3(self):
        self.assertEqual(lab6.LAB6_VAR_1([[False, True], [3, 4]], [[5, 6], [7, 8]]), ValueError)
    def test_4(self):
        self.assertEqual(lab6.LAB6_VAR_1([[1, 2, 3], [3, 4, 5]], [[5, 6], [7, 8]]), "Число столбцов в первой матрице не равно числу строк во второй")
    def test_5(self):
        self.assertEqual(lab6.LAB6_VAR_1([[5, 6], [7, 8]], [[1, 2, 3], [3, 4, 5]]), [[23.0, 34.0], [31.0, 46.0]])