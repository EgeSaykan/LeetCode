
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        letters = [
            ['a', a],
            ['b', b],
            ['c', c]
        ]
        total = a + b + c
        count = sorted(letters, key=lambda x: x[1])
        count.reverse()
        queue = count[:]

        result = "0"
        current_max = queue[0][1]
        while queue:
            if queue[0][1] >= 2 and queue[0][1] == current_max and result[-1] != queue[0][0]:
                queue[0][1] -= 2
                count[0][1] -= 2
                count = sorted(letters, key=lambda x: x[1])
                count.reverse()
                result += queue[0][0]*2
                queue = queue[1:] + [queue[0]]
                total -= 2
                _max = count[0][1]
                if current_max > _max:
                    current_max =_max
            elif queue[0][1] >= 1 and queue[0][1]:
                queue[0][1] -= 1
                count[0][1] -= 1
                count = sorted(letters, key=lambda x: x[1])
                count.reverse()
                result += queue[0][0]
                queue = queue[1:] + [queue[0]]
                total -= 1

                _max = count[0][1]
                if current_max > _max:
                    current_max =_max

            elif queue[0][1] == 0:
                for i in range(len(count)):
                    if count[i][0] == queue[0][0]:
                        count.pop(i)
                        break
                queue = queue[1:]

            else:
                return ""
        return result[1:]


a = Solution()
print(a.longestDiverseString(1, 1, 7))