/**
 * You are given an array nums of integers that may contain duplicates values.
 * Your task is to figure out the frequency of each element appearing in the array 
 * and print the frequency count
 */

 #include <iostream>
 #include <vector>
 #include <map>
 using namespace std;

 void frequency(vector<int> &nums){
    int size = nums.size();
    map<int, int> myMap;
    // store the count of each element in map
    for(int i = 0; i < size; ++i){
        int elem = nums[i];
        myMap[elem] = myMap[elem] + 1;
    }
    map<int, int>:: iterator it;
    for(it = myMap.begin(); it != myMap.end(); ++it){
        cout << it -> first << " frequency is: " << it -> second << endl;
    }

 }

 int main(){
    vector<int> nums = {10, 20, 5, 5, 3, 4, 3, 10, 10, 10, 5, 5, 5, 1, 2, 3, 4, 6, 7};
    frequency(nums);

 }