class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        s.lstrip()
        s.rstrip()
        t = s.split()
        return len(t)