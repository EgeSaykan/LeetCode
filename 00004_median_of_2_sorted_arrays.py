
class Solution:
    def median(self, arr):
        le = len (arr)-1
        if le == -1:
            return (0,(0,0))
        if le % 2 == 1:
            return ((arr[le//2] + arr[le//2+1])/2,(arr[le//2],arr[le//2+1]))
        return ((arr[le//2]),(arr[le//2],arr[le//2]))


    def switcheroo(self, nums1, nums2):
        if len(nums1) > len(nums2):
            temp = nums2[:]
            nums2[:] = nums1[:]
            nums1[:] = temp[:]

    def isValid(self, nums1, nums2, mid, antimid):
        len1,  len2 = len(nums1), len(nums2)
        total_len = len1+len2
        if mid >=len1-1: return "huh"
        if antimid >=len2-1: return "huh"
        if nums1[mid] <= nums2[antimid+1] and nums1[mid+1] >= nums2[antimid]:
            return 0
        elif nums1[mid+1] < nums2[antimid]:
            return -1
        elif nums2[antimid+1] < nums1[mid]:
            return 1
        else:
            raise Exception("how")

    def avg(self, tup):
        sum = 0
        for i in tup:
            sum += i
        return sum / len(tup)

    def binPlace(self, arr, num):
        left, right = 0, len(arr)-1
        while left <= right:
            mid = (left+right)//2
            if arr[mid] == num:
                return mid
            elif arr[mid] < num:
                left = mid + 1
            else:
                right = mid - 1
        return left


    def findMedianSortedArrays(self, nums1, nums2, left = 0, right = -50, med = 0):
        self.switcheroo(nums1, nums2)
        len1,  len2 = len(nums1), len(nums2)
        total_len = len1+len2
        if len1 == 0 and len2 == 0: return 0
        elif len1 == 0: return self.median(nums2)[0]
        elif nums1[-1] <= nums2[0]:
            return self.median(nums1+nums2)[0]
        elif nums2[-1] <= nums1[0]: return self.median(nums2+nums1)[0]
        elif len1 == 1:
            pos = self.binPlace(nums2, nums1[0])
            nums2 = nums2[:pos] + nums1 + nums2[pos:]
            return self.median(nums2)[0]

        if right == -50: right = len1-1

        isEven = True if (len1+len2)%2==0 else False


        if left > right: return med

        # decide if
        mid = (left+right)//2
        antimid = (total_len+1) // 2 - mid - 2

        validity = self.isValid(nums1,nums2,mid,antimid)
        if not isEven:
            if validity == 0:
                return max(nums1[mid], nums2[antimid])
            elif validity == 1:
                if mid == 0:
                    new = nums2 + nums1
                    if nums1[mid] <= nums2[antimid+2]:
                        new[antimid+2] = nums1[mid]
                    return self.median(new)[0]
                return self.findMedianSortedArrays(nums1,nums2,left,mid-1,med)
            elif validity == -1:
                if mid == len1-2:
                    if nums1[mid+1] >= nums2[antimid-1]:
                        return nums1[mid+1]
                    return self.median(nums1+nums2)[0]
                return self.findMedianSortedArrays(nums1,nums2,mid+1,right,med)
            else: raise Exception("huh")
        else:
            if validity == 0:
                return self.avg((max(nums1[mid], nums2[antimid]),min(nums1[mid+1], nums2[antimid+1])))
            elif validity == 1:
                if mid == 0:
                    new = nums2 + nums1
                    if nums1[mid] <= nums2[antimid+2]:
                        new[antimid+2] = nums1[mid]
                    return self.median(new)[0]
                return self.findMedianSortedArrays(nums1,nums2,left,mid-1,med)
            elif validity == -1:
                if mid == len1-2:
                    if nums1[mid+1] >= nums2[antimid-1]:
                        return self.avg((nums1[mid+1], nums2[antimid]))
                    return self.median(nums1+nums2)[0]
                return self.findMedianSortedArrays(nums1,nums2,mid+1,right,med)
            else: raise Exception("heh")