#include<stdio.h>
#include<math.h>

int max=0,min=0,max1=0,min1=0;

struct soln{
    int max;
    int min;
};

int no_calls=0;
void print_Arr(int arr[],int m, int n){
    int i;
printf("Array : ");
    for(i=m;i<=n;i++){
        printf("%d ",arr[i]);
    }
}

struct soln mymaxmin(int arr[],int s, int e){
    int max,min;
    struct soln s1;
    s1.max=-1;
    s1.min=-1;
    no_calls++;
    if (s==e){
        s1.max=arr[s];
        s1.min=max;
    }
    else if (s==e-1){
        if (arr[s]<arr[e]){
           s1.max=arr[e];
            s1.min = arr[s];
        }
        else{
           s1.max = arr[s];
            s1.min = arr[e];
        }
    }
    else{
        struct soln s2;
        s2.max=-1;
        s2.min=-1;
        int mid = s+(s+e)/2;
        s1 = mymaxmin(arr,s,mid);
        s2 = mymaxmin(arr,mid+1,e);
        if (s1.max<s2.max){
            s1.max=s2.max;
        }
        if (s1.min>s2.min){
            s1.min = s2.min;
        }
    }
    printf("____Call number : %d_____\n",no_calls);
    print_Arr(arr,s,e);
    printf("\nMax : %d Min : %d\n",no_calls,s1.max,s1.min);
    return s1;
}

void MaxMin(int a[],int start,int end){
    int mid;
    if (start==end){
        max = min = a[start];
}
else if(start= end-1){
    if(a[start] < a[end]){
    max = a[end]; 
    min = a[start];
    }
    else{
    max = a[start];
    min = a[end];
    }
}
else{
        mid = (start+end)/2;
        MaxMin(a, start,mid);
        MaxMin(a, mid+1,end);
        if (max < max1){
            max = max1;
            if (min > min1)
            min = min1;
            }
}
printf("MAX = %d MIN= %d",max,min);
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
    if (n==1){
        printf("MAX = %d MIN= %d",arr[0],arr[0]);
    }
    else{
    struct soln sol = mymaxmin(arr,0,n-1);
    //MaxMin(arr,0,n-1);
    printf("******FINAL*******\nMAX = %d \t MIN= %d",sol.max,sol.min);
    printf("\nNo of calls : %d",no_calls);
}
}
