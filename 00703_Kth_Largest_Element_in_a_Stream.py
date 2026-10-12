class KthLargest:

    def __init__(self, k: int, nums: list[int]):
        self.k = k
        self.nums = sorted(nums)

    def binary_add(self, n):
        if not self.nums:
            self.nums = [n]
            return True
        if len(self.nums) == 1:
            if self.nums[0] > n:
                self.nums = [n, self.nums[0]]
            else:
                self.nums = [self.nums[0], n]
            return True
        left = 0
        right = len(self.nums)
        while left < right:
            middle = (left + right) // 2
            if self.nums[middle] < n:
                left = middle + 1
            else:
                right = middle
        self.nums.insert(left, n)


    def add(self, val: int) -> int:
        self.binary_add(val)
        return list(self.nums)[-self.k]

a = KthLargest(3,[4,5,8,2])
print(a.add(3))
print(a.add(5))
print(a.add(10))