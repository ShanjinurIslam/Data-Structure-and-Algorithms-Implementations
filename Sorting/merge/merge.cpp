#include <iostream>
#include <time.h>

using namespace std ;

int num[100000];
int temp[100000];

void MergeSort(int lo,int hi){
    if(lo==hi){
        return ;
    }

    int mid = (lo+hi)/2 ;

    MergeSort(lo,mid);
    MergeSort(mid+1,hi);
    
    int i,j,k ;

    for(i=lo,j=mid+1,k=lo;k<=hi;k++){
        if(i==mid+1){
            temp[k] = num[j++];
        }
        else if(j==hi+1){
            temp[k] = num[i++];
        }
        else if(num[i]<num[j]){
            temp[k] = num[i++];
        }
        else{
            temp[k] = num[j++];
        }
    }

    for (int k = lo; k <= hi; k++)
    {
        cout<<temp[k]<<" ";
        num[k] = temp[k];
    }
    cout<<endl ;
}

int main(){
    srand(time(0));
    for(int i=0;i<10;i++){
        num[i] = rand()%100;
    }

    MergeSort(0,9);

    for(int i=0;i<10;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    return 0;
}