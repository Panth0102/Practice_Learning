#38. Count and Say

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for _ in range(n - 1):
            s = ''.join(str(len(group)) + digit
                for group, digit in re.findall(r'((.)\2*)', s))
        return s 