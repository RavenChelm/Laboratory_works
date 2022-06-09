import unittest
import lab3
class TEST_LAB3_VAR_32(unittest.TestCase):
    def test_1(self):
        self.assertEqual(lab3.LAB3_VAR_32(1, 0.00002), 0.3678791887125221 )
    def test_2(self):
        self.assertEqual(lab3.LAB3_VAR_32(1.2, 0.00002), 0.3011926747428572 )
    def test_3(self):
        with self.assertRaises(TypeError):
            lab3.LAB3_VAR_32("var", 0.00002)
    def test_4(self):
        self.assertEqual(lab3.LAB3_VAR_32(True, 0.00002), TypeError)
    def test_5(self):
        with self.assertRaises(TypeError):
            lab3.LAB3_VAR_32([1], 0.00002)
    def test_6(self):
        self.assertEqual(lab3.LAB3_VAR_32(2, 0.00002), 0.13533643311421098 )
    def test_7(self):
        self.assertEqual(lab3.LAB3_VAR_32(5, 2), "Недопустимое значение точности" )
    def test_8(self):
         self.assertEqual(lab3.LAB3_VAR_32(1, -0.00002), "Недопустимое значение точности" )
    def test_9(self):
        with self.assertRaises(TypeError):
            lab3.LAB3_VAR_32(1, "var")
    def test_10(self):
        self.assertEqual(lab3.LAB3_VAR_32(1, True), TypeError)      
    def test_11(self):
        with self.assertRaises(TypeError):
            lab3.LAB3_VAR_32(1, [1])