#include<stdio.h>
#include<math.h>

int no_iter=0;

void print_Arr(int arr[],int m,int n){
    int i;
    printf("\nArray : ");
    for(i=m;i<=n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}


int bin_search(int arr[],int beg,int end,int key){
    no_iter++;
    printf("\nCall no : %d",no_iter);
    print_Arr(arr,beg,end);
    if (beg<=end){
        int mid = beg + (end-beg)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]<key){
            bin_search(arr,mid+1,end,key);
        }
        else{
            bin_search(arr,beg,mid,key);
        }
    }
else{
    return -1;
}
}



void main(){
    int i,j,k;
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter the element : ");
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search : ");
    int key;
    scanf("%d",&key);
    int loc = bin_search(arr,0,n-1,key);
    if (loc==-1){
        printf("Element not found in array !!!!!!!!");
    }
    else{
    printf("The element %d is the %d element in the array ",key,loc+1);
    printf("\nNo of iterations is %d",no_iter);

    }
}
