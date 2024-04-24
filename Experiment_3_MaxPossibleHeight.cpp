#include<bits/stdc++.h>
using namespace std;
int main(){
    
    cout<<"stack equaizier program"<<endl;
    
    cout<<"enter the height of all three stacks n1,n2,n3:";
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    
    cout<<endl<<"enter the elements of stack 1 :";
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    
     cout<<endl<<"enter the elements of stack 2 :";
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    
     cout<<endl<<"enter the elements of stack 3 :";
    int arr3[n3];
    for(int i=0;i<n3;i++){
        cin>>arr3[i];
    }
    
    stack<int>s1;
    stack<int>s2;
    stack<int>s3;

    int sum1=0;
    for(int i=0;i<n1;i++){
        sum1+=arr1[i];
        s1.push(sum1);

    }
        
    int sum2=0;
    for(int i=0;i<n2;i++){
        sum2+=arr2[i];
        s2.push(sum2);

    }
    
    int sum3=0;
    for(int i=0;i<n3;i++){
        sum3+=arr3[i];
        s3.push(sum3);
    }
    
    while (!s1.empty() && !s2.empty() && !s3.empty() &&
    !(s1.top() == s2.top() && s2.top() == s3.top() && s1.top()==s3.top())){
     
        if (s1.top() >= s2.top() && s1.top() >= s3.top()) {
        s1.pop();
        }
        
        else if (s2.top() >= s1.top() && s2.top() >= s3.top()){
        s2.pop();
        }
        
        else{
        s3.pop();
         }
     }
     cout<<s2.top();
    
}
