#include<stdio.h>
#include<conio.h>
#include<math.h>


void print(int arr[],int n){
    int i,j,k;
    for(i=0;i<n;i++){;
    printf("%d\t",arr[i]);
    }
}

void swap_ele(int *i,int *j){
    int temp;
    temp = *i;
    *i=*j;
    *j=temp;
}

void selection_sort(int samp_arr[], int n){
    //printf("Func call\n");
    int j,ind_min,swap=0;
    for(int i=0;i<n-1;i++){
        ind_min=i;
        for(j=i+1;j<n;j++){
            if (samp_arr[j]<samp_arr[ind_min]){
                ind_min=j;
        }
        swap_ele(&samp_arr[ind_min],&samp_arr[i]);
        swap++;
        printf("\nswap %d :\n",swap);
        print(samp_arr,n);
    }
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
    selection_sort(arr,n);
    printf("\n___________SORTED_ARRAY____________\n");
    print(arr,n);
}