#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int sw=0;
#define MAX 6
void swap(int arr[], int k, int l){
    int temp= arr[k]; 
    arr[k] = arr[l]; 
    arr[l] = temp; 
    sw++;
}
void printArray(int arr[]) 
{ 
    int i; 
    for (i = 1; i <=MAX; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}
int partition(int arr[], int p, int r)
{
	int x =arr[r];
    int i= p-1;
    for(int j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    printf("Pass : ");
    printArray(arr);
    return i+1;
}
void QuickSort(int arr[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(arr,p,r);
        QuickSort(arr, p, q-1);
        QuickSort(arr, q + 1, r);
    }
}
int main() 
{ int i;
    int arr[MAX];
    for(i=0;i<MAX;i++){
        printf("Enter data : ");
        scanf("%d",&arr[i]);
    }
    printf("\n___________UNSORTED_ARRAY____________\n");
    printArray(arr);
    QuickSort(arr,1,MAX); 
    printf("\n___________SORTED_ARRAY____________\n");
    printArray(arr); 
    printf("TOTAL SWAPS: %d",sw);
    return 0; 
} 
