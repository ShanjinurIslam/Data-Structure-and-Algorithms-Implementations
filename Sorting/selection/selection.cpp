#include <iostream>
#include <algorithm>

using namespace std ;

int main(){
    int arr[] = {93,12,33,44,55,1,2};
    for(int i=0;i<5;i++){
        for(int j=i+1;j<6;j++){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}