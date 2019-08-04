//solution1
void rotate(int* nums, int numsSize, int k)
{
        int* t = nums;
       // printf(" k = %d\n",k);
        for (int i = 0; i < numsSize; ++i) 
        {
             printf("i=%d, k=%d\n",i,k);
            printf("nums[(i + k) % numsSize]=%d \n", nums[(i + k) % numsSize]);
            nums[(i + k) % numsSize] = t[i];
        }
 }

//solution2
void rotate(int* nums, int numsSize, int k)
{
    int t[numsSize];
         for (int j = 0; j < numsSize; ++j) 
        {       
             t[j]=nums[j];
             printf("1nums[%d]=%d\n",j,nums[j]);  
             printf("1t[%d]=%d\n",j,t[j]);
        }
    
  
        for (int i = 0; i < numsSize; ++i) 
        {
           printf("2t[%d]=%d\n",i,t[i]);
            printf("2nums[%d]=%d\n",i,nums[i]);
            nums[(i + k) % numsSize] = t[i];
        }
}

//solution3
int maxyueshu(int n, int k) 
{
    if (n < k) 
    {
        return maxyueshu(k, n);
    } 
    else 
    {
        if (n % k == 0) 
        {
            return k;
        } 
        else 
        {
            return maxyueshu(k, n % k);
        }
    }
}

void rotate(int* nums, int numsSize, int k)
{
  if (k == 0 || numsSize == k) 
  {
        return;
  }
    for (int i = 0 ; i < maxyueshu(numsSize, k) ; i++) 
    {
        int swap = 0, cur = i, temp1 = nums[cur], temp2 = 0;
        while ((swap = (cur + k) % numsSize) != i) 
        {
            temp2 = nums[swap];
            nums[swap] = temp1;
            cur = swap;
            temp1 = temp2;
        }
        nums[i] = temp1;
    }
}

//solution4
void swap(int *a , int *b)
{
    int temp;
    temp =*a;
    *a  =*b ;
    *b = temp;
    
}

void rotate(int* nums, int numsSize, int k)
{
        int n = numsSize, start = 0;   
        while (n && (k %= n)) 
        {
            for (int i = 0; i < k; ++i) 
            {
                swap(&(nums[i + start]), &(nums[n - k + i + start]));
            }
            n -= k;
            start += k;
        }
}



//solution5
void rotate(int* nums, int numsSize, int k)
{
  if ( (k %=numsSize) == 0) 
      return;
        int start = 0, idx = 0, pre = 0, cur = nums[0], n = numsSize;
        for (int i = 0; i < n; ++i) 
        {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) 
            {
                idx = ++start;
                cur = nums[idx];
            }
        }
 }
