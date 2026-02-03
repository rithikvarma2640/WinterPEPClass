/**
 *  Intersection of two arrays
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printIntersection(vector<int>& nums1, vector<int>& nums2){
    map<int, int> myMap;
    // insert nums1 elements in map
    for(int val1: nums1){
        myMap[val1]++;
    }
    // insert nums2 elements in map
    for(int val2: nums2){
        myMap[val2]++;
    }

    //iterate on the map and check if freq > 1
    for(auto it: myMap){
        // it is a pair, it.first and it.second is valid
        if(it.second > 1){
            cout << it.first << " ";
        }
    }
    cout << endl;

    myMap[10] = 99;
    myMap[11] = 111;
    cout << "size: " << myMap.size() << endl;
    auto it = myMap.find(12);
    if(it != myMap.end()){
        cout << "erasing: " << endl;
        myMap.erase(it);
    }else{
        cout << "key not found" << endl;
    }
    cout << "size after erase: " << myMap.size() << endl;
}

void printIntersectionContainDuplicates(vector<int> &nums1, vector<int> &nums2){
    map<int, int> myMap;
    // store the elems of nums1
    for(int val1: nums1){
        myMap[val1]++;
    }

    // iterate on the nums2 check if it is present in map or not
    // if present, push it into ans array and at the same time, remove it from the map
    // to avoid duplicates
    vector<int> output;
    for(int val2: nums2){
        auto it = myMap.find(val2);
        if(it != myMap.end()){
            output.push_back(val2);
            //erase val2 from map
            myMap.erase(it);
        }
    }
    // print the output array
    for(int value: output){
        cout << value << " ";
    }
}

int main(){
    vector<int> nums1 = {1, 2, 2, 1, 3, 3, 3};
    vector<int> nums2 = {2, 2, 3, 3, 3};
    //printIntersection(nums1, nums2);
    printIntersectionContainDuplicates(nums1, nums2);
}