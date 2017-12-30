#include <stdlib.h>

#if 0
/* 时间复杂度 O(n^2)
 * 空间复杂度 O(1)
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    for (i = 0; i < numsSize; ++i) {
        for (j = (i+1); j < numsSize; ++j) {
            if ((target - nums[i]) == nums[j]) {
                int *ret_idx = (int*)malloc(2*sizeof(int));
                ret_idx[0] = i;
                ret_idx[1] = j;
                return ret_idx;
            }
        }
    }
    return NULL;
}
#endif 

#if 1
/* 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
#include <unordered_map>
using std::unordered_map;
int* twoSum(int* nums, int numsSize, int target) {
    unordered_map<int, int> uo_map;
    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        unordered_map<int, int>::const_iterator it = uo_map.find(complement);
        if (it != uo_map.end()) {
            int *ret_idx = (int*)malloc(2*sizeof(int));
            ret_idx[0] = it->second;
            ret_idx[1] = i;
            return ret_idx;
        }
        else {
            uo_map.insert(unordered_map<int, int>::value_type(nums[i], i));
        }
    }
    return NULL;
}
#endif

#ifdef TEST
#include <stdio.h>
#include <time.h>

void fill_test_case(int count, int **numbers, int *target)
{
    int i;
    srandom((unsigned int)time(NULL));
    *numbers = (int*)malloc(count*sizeof(int));
    for (i = 0; i < count; ++i)
    {
        (*numbers)[i] = (int)random() % 1000000;
    }
    i = random() % count;
    *target = (*numbers)[i];
    i = random() % count;
    *target += (*numbers)[i];
    return;
}

int main(int argc, char *argv[])
{
    int count = 10000;
    int *numbers;
    int target;
    int *idx;
    
    if (argc > 1)
    {
        count = atoi(argv[1]);
    }
    if (count < 10000)
    {
        count = 10000;
    }
    fill_test_case(count, &numbers, &target);

    idx = twoSum(numbers, count, target);
    if (idx)
    {
        printf("target(%d) = numbers[%d](%d) + numbers[%d](%d)\n", target, idx[0], numbers[idx[0]], idx[1], numbers[idx[1]]);
    }
    else
    {
        printf("target(%d) was not found\n", target);
    }
    free(idx);
    free(numbers);
    return 0;
}
#endif