#include <iostream>
#include <map>
using namespace std;

int main(){
    // create the map
    map<int, int> myMap;
    map<string, int> myMap1;
    map<string, bool> myMap2;

    myMap[0] = 1; // O(logN) time
    myMap[1] = 2;

    myMap1.insert({"Himanshu", 10}); // O(logN) time
    myMap2["Ayush"] = false;

    myMap[2];
    myMap1["Hello"];
    myMap1["Hello"] = 2;

    // create the iterator of map
    map<string, int>:: iterator it;
    for(it = myMap1.begin(); it != myMap1.end(); ++it){
        cout << it -> first << " " << it -> second;
        cout << endl;
    }

    cout << "Printing myMap2: " << endl;
    map<string, bool> :: iterator it1;
    for(auto it1 = myMap2.begin(); it1 != myMap2.end(); it1++){
        cout << it1 -> first << " " << it1 -> second << endl;
    }

    cout << "Printing myMap using range based loop: " << endl;
    for(auto it2: myMap){
        cout << it2.first << " " << it2.second << endl;
    }

}

