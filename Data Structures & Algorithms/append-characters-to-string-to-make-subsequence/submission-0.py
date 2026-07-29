class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        p = -1

        i = 0
        j = 0

        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                p = j
                j += 1
            
            i += 1

        
        if p > -1:
            return len(t[p+1:])
        else:
            return len(t)