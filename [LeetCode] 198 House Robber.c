
int rob(int* nums, int numsSize)
{
  if (numsSize== 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize== 2) return fmax(nums[0], nums[1]);
    
    int sum[numsSize+1];
    int i;
    sum[0] = 0;
    sum[1] = nums[0];
    sum[2] = fmax(nums[0], nums[1]);
    for (i = 3 ; i <= numsSize ; i++) 
    {
        sum[i] = fmax(nums[i-1]+sum[i-2], sum[i-1]);
    }
    return sum[numsSize];
}