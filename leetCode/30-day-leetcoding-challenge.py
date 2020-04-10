"""
Single Number
"""
class Single_Number(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = {}
        counter.keys()
        for n in nums:
            if n in counter.keys():
                counter[n] += 1
            else:
                counter[n] = 1
        res = 0
        for k in counter.keys():
            if counter.get(k) == 1:
                res = k

        return res

# s = Single_Number()
# print(s.singleNumber([1,2,3,4,2,1,4]))

"""
Happy Number
"""
class Happy_Number:
    def isHappy(self, n: int) -> bool:
        if n==1:
            return True
        out = n
        inter_result = set()
        while out!=1 :
            str_out = str(out)
            new_out = 0
            for s in str_out:
               new_out += int(s)**2 
            
            if new_out in inter_result:
                return False
            else:
                inter_result.add(new_out)
            out = new_out
        return True

# s = Happy_Number()
# print(s.isHappy(19))


"""
Counting Elements
1 <= arr.length <= 1000
0 <= arr[i] <= 1000
"""
class Counting_Elements:
    def countElements(self, arr: List[int]) -> int:
        res_list = [0]*1002
        arr_set = set()
        for a in arr:
            res_list[a+1] += 1
            arr_set.add(a)
        num = 0
        for i, r in enumerate(res_list):
            if i in arr_set:
                num += r 
            pass
        return num

"""
"""
class Move_Zeroes:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero = [num for _, num in enumerate(nums) if num!=0]
        list_size = len(nums)      
        cur_pos = 0
        end_pos = list_size-1
        temp = 0
        while cur_pos < end_pos:
            if nums[cur_pos] == 0:
                temp = nums[end_pos]
                nums[end_pos] = nums[cur_pos]
                nums[cur_pos] = temp
                end_pos -= 1
            else:
                cur_pos += 1
        for i, num in enumerate(non_zero):
            nums[i] = num
            pass

t = Move_Zeroes()
t.moveZeroes([0,1,0,3,12])