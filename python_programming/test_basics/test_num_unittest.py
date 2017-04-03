import unittest
from number import convert_binary
from number import convert_binary_octal
from number import convert_binary_hex
from number import built_in_binary

class TestNum(unittest.TestCase):

    def setUp(self):
        pass

    def test_binary(self):
        #1000
        self.assertEqual(convert_binary(8), built_in_binary(8))
        #1000011
        self.assertEqual(convert_binary(35), built_in_binary(35))
        #110110011
        self.assertEqual(convert_binary(435), built_in_binary(435))

    def test_octal(self):
        #8
        self.assertEqual(convert_binary_octal('1000'), '10')
        #35
        self.assertEqual(convert_binary_octal('100011'), '43')
        #435
        self.assertEqual(convert_binary_octal('110110011'), '663')

    def test_hex(self):
        self.assertEqual(convert_binary_hex(), None)
if __name__ == '__main__':
    unittest.main()
