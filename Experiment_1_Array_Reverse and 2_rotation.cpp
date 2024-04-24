//Reverse an array
//Rotation an array

#include <iostream>
using namespace std;

void reverse(int arr[],int n){
    for(int i =0;i<n/2;i++){
       int temp = arr[i];
       arr[i]= arr[n-i-1];
       arr[n-i-1]= temp;
       
    }
    
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
}

void rotation(int arr[],int n, int rotation){
    int newArr[5];
    
    for(int i =0;i<n;i++){
        int newIndex= (i+n-rotation)%n;
        newArr[newIndex] = arr[i];
    }
    
    for(int i =0;i<n;i++)
    cout<<newArr[i]<<" ";
    
}





int main() {
   int arr[5]={1,2,3,4,5};
   reverse(arr,5);
   cout<<endl;
   
   int arr2[5]={2,3,4,5,6};
   
   rotation(arr2,5,2);
   
}
