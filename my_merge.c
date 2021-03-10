#include<stdio.h>
#include <conio.h>
#include<math.h>

void print(int arr[],int n){
    int i,j,k;
    for(i=0;i<n;i++){;
    printf("%d\t",arr[i]);
    }
}

void merge(int arr[], int l_start,int mid,int end){
    int s_l_arr = mid-l_start+1;
    int s_r_arr = end-mid;
    //printf("s_l_arr = %d s_r_arr = %d",s_l_arr,s_r_arr);
    int l_arr[s_l_arr];
    int r_arr[s_r_arr];
    int i,j,k;
 //printf("\nl_start=%d mid=%d end=%d ",l_start,mid,end);

    for(i=0;i<s_l_arr;i++){
        l_arr[i]=arr[l_start+i];
    }

    for(i=0;i<s_r_arr;i++){
        r_arr[i] = arr[mid+i+1];
    }

    i=0;
    j=0;
    k=l_start;
    int temp;
    
    
    while(i<s_l_arr && j<s_r_arr){
        if (l_arr[i]<=r_arr[j]){
            arr[k]=l_arr[i];
            i++;
        }
        else{
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }

    while (i<s_l_arr){
        arr[k] = l_arr[i];
        k++;
        i++;
    }

    while (j<s_r_arr){
        arr[k] = r_arr[j];
        k++;
        j++;
    }
    printf("\n");
    print(arr,end+1);
}
void merge_sort(int arr[],int start, int end){
    int mid_indx;
    //printf("l = %d , r = %d\n",start,end);
    if (start<end){
        mid_indx = start + (end - start) / 2;
        merge_sort(arr,start,mid_indx);
        merge_sort(arr,mid_indx+1,end);
        //printf("md = %d",mid_indx);
        merge(arr,start,mid_indx,end);
    }

}

void main(){
    int i,j,k,c;
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter data : ");
        scanf("%d",&arr[i]);
    }
    printf("\n___________UNSORTED_ARRAY____________\n");
    print(arr,n);
    printf("%d",n);
    merge_sort(arr,0,n-1);
    printf("\n___________SORTED_ARRAY____________\n");
    print(arr,n);
}