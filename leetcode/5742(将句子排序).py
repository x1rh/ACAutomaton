class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        mp = dict()
        for each in words:
            idx = -1
            for i, ch in enumerate(each):
                if ch.isdigit():
                    idx = i
                    break
            mp[each[idx:]] = each[:idx] 
        
        
        
        nm = sorted(mp.items(), key=lambda x:x[0])
        
        ans = [x[1] for x in nm]
        
        return ' '.join(ans)