#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int rows, cols;
    

    cin >> rows >> cols;
    

    vector<vector<char>> matrix(rows, vector<char>(cols));
    

 
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    
   unordered_map<string,pair<string,int>>mp;
    
 
    for (int i = 0; i < rows; ++i) {
        string str1;
        for (int j = 0; j < cols; ++j) {
            str1 += matrix[i][j];
        }
        mp[str1]={"row",i};
    }
    

    for (int j = 0; j < cols; ++j) {
        string str2;
        for (int i = 0; i < rows; ++i) {
            str2 += matrix[i][j];
        }
        mp[str2]={"col",j};
    }
    
    string str;
    cin>>str;
    
    bool ok = 0;
    for(auto it:mp){
        if(ok){
            continue;
        }
        if(it.first.find(str)!= string::npos){
         cout<<"Substring found!!!"<<endl;  
         cout<<""<<it.second.first<<" "<<it.second.second<<endl;
         cout<<it.first.find(str)<<" "<< it.first.find(str)+str.length()-1<<endl;
         ok = 1;
         
        }
        
    }


    if(!ok){
        cout<<"String not found"<<endl;
    }

    
    return 0;
}