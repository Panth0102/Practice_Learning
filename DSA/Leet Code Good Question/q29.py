class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 0:
            raise ZeroDivisionError("Divided by 0")

        negative = (dividend < 0) != (divisor < 0)

        if dividend < 0:
            dividend = -dividend

        if divisor < 0:
            divisor = -divisor

        ans = 0

        i = dividend.bit_length() - 1

        while i >= 0:
            if (divisor << i) <= dividend:
                dividend -= divisor << i
                ans |= 1 << i
            i -= 1

        if negative:
            ans = -ans

        if ans > 2**31 - 1:
            return 2**31 - 1

        if ans < -2**31:
            return -2**31

        return ans