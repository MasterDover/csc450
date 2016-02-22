#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL));
    int num;
    int i;
    int numofNums = 10;
    int nums[numofNums];
    for(i = 0; i < 10; i++)
    {
        nums[i] = rand();
        //printf("%d\n", num);
    }
    
   
    
    merge_sort(nums, 0, numofNums);
    
    for(i = 0; i < 10; i++)
    {
      printf("%d\n", nums[i]);
    }
    //do the merge sort, maybe save the final things to a file and then merge up?
    //problem is writing to the file not be done in the right order... kinda important
    
}

void merge_sort(int arr[],int low,int high)
{
  int mid;
  if(low<high) {
    mid=(low+high)/2;
    
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    
    merge(arr,low,mid,high);
  }
}

void merge(int arr[],int l,int m,int h)
{
  
  int endArr1,endArr2,i,j,k;
  endArr1=m-l+1;
  //middle - low +1
  endArr2=h-m;
  //high - middle
  int arr1[endArr1],arr2[endArr2];
  
  
  for(i=0; i<endArr1; i++)
    arr1[i]=arr[l+i];
  for(j=0; j<endArr2; j++)
    arr2[j]=arr[m+j+1];

  //arr1[i]=9999;
 //arr2[j]=9999;

  i=0;
  j=0;
  for(k=l; k<=h; k++) { 
    
    if(arr1[i]<=arr2[j])
    {
      if(i<endArr1)
      {
      arr[k]=arr1[i];
      i++;
      }
      else
      {
        arr[k]=arr2[j];
        j++;
      }
    }
    else
     {
       if(j<endArr2)
       {
       arr[k]=arr2[j];
       j++;
        }
     else
     {
       arr[k]=arr1[i];
       i++;
     }
  }
}
}