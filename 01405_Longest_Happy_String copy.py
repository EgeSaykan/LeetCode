class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        letters = [
            ['a', a],
            ['b', b],
            ['c', c]
        ]
        letters = [[i, m] for i, m in letters if m > 0]
        count = sorted(letters, key=lambda x: x[1])
        count.reverse()

        result = "00"
        while count:
            if count[0][1] >= 2 and result[-1] != count[0][0]:
                count[0][1] -= 2
                result += count[0][0]*2
                if count[0][1] == 0:
                    count = count[1:]
                elif len(count) > 1 and count[0][1] < count[1][1]:
                    count.sort(key=lambda x: x[1])
                    count.reverse()
            elif count[0][1] >= 1 and (result[-1] != count[0][0] or result[-2] != count[0][0]):
                count[0][1] -= 1
                result += count[0][0]
                if count[0][1] == 0:
                    count = count[1:]
                elif len(count) > 1 and count[0][1] < count[1][1]:
                    count.sort(key=lambda x: x[1])
                    count.reverse()
            elif len(count) > 1:
                result += count[1][0]
                count[1][1] -= 1
                if len(count) > 2 and count[1][1] == 0:
                    count = [count[0]] + [count[2]]
                elif count[1][1] == 0:
                    count = [count[0]]
                elif len(count) > 2 and count[1][1] < count[2][1]:
                    count = [count[0]] + [count[2]] + [count[1]]
            else:
                return result[2:]

        return result[2:]

    
a = Solution()
print(a.longestDiverseString(1, 0, 3))