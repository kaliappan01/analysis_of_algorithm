#include<stdio.h>
#include<math.h>


void print(int arr[],int n){
    int i,j,k;
    for(i=0;i<n;i++){;
    printf("%d\t",arr[i]);
    }
}
void insertion_sort(int arr[], int n){
    int i,j,swap=1,pivot;
    for(i=1;i<n;i++){
    pivot = arr[i];
    j= i-1;
    while(pivot<arr[j] && j >=0){
        arr[j+1] =arr[j];
        --j;
    }
    
    arr[j+1] = pivot;
    printf("\nswap %d \n",swap++);

    print(arr,n);
    printf("\n");
    }

}

int main(){
    int i,c,n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter data : ");
        scanf("%d",&arr[i]);
    }
    printf("\n___________UNSORTED_ARRAY____________\n");
    print(arr,n);
    insertion_sort(arr,n);
    printf("\n___________SORTED_ARRAY____________\n");
    print(arr,n);
}