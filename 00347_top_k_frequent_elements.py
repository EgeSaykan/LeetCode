from collections import Counter

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        record = Counter(nums)
        result = []
        
        for i in record.most_common():
            result.append(i[0])
        return result[:k]

a = Solution()
print(a.topKFrequent([1,2,1,2,1,2,3,1,3,2, 2], 2))