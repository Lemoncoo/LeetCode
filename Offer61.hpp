#ifndef Offer61_hpp
#define Offer61_hpp
#include <vector>
#include<iostream>
using  namespace::std;
#endif /* Offer61_hpp */
class Solution{
public:
    vector<int> allnums;
    bool exit(int x){
        for(auto num:allnums){
            if(num == x){
                return true;
            }
        }
        return false;
    }
    bool isStraight(vector<int>& nums){
        int count = 0,min = 13;
        allnums = nums;
        for(auto num :nums){
            if(num == 0)
                count++;
            if(num < min && num != 0)
                min = num;
        }
        min++;
        for(int i = 0;i < 4;i++){
            if(!exit(min)){
                if(count != 0){
                    count--;
                    min++;
                }
                else{
                    return false;
                }
            }else{
                min++;
            }
        }
        return true;
    }
    
    void Test(){
        vector<int> arr{1,5,3,2,0};
        cout<< isStraight(arr);
    }
};
