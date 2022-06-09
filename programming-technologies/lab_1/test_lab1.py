import unittest
import lab1
class TEST_LAB1_VAR_19(unittest.TestCase):
    def test_Int(self):
        self.assertEqual(lab1.LAB1_VAR_19(1, 4, 3), (-4.0, 3.0) )
    def test_Type_Float(self):
        self.assertEqual(lab1.LAB1_VAR_19(1.0, 4.5, -0.3), (-4.5, -0.3))
    def test_Type_Str(self):
        self.assertEqual(lab1.LAB1_VAR_19("a", 2, 4), TypeError)
    def test_Type_Bool(self):
        self.assertEqual(lab1.LAB1_VAR_19(1, False, 4), TypeError)
    def test_Anull(self):
        self.assertEqual(lab1.LAB1_VAR_19(0, 2, 4), ("Ошибка.", "Уравнение не является квадратным."))
    def test_NoRoots(self):
        self.assertEqual(lab1.LAB1_VAR_19(1, 0, 4), ("Ошибка.", "Корней не существует."))