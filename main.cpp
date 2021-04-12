// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;

void FindMid(const vector<int>& temperature_list){
    vector<int> indexes;
    double mid = 0;
    for (auto num : temperature_list) {
        mid += num;
    }
    mid = mid / temperature_list.size();
    for (int i = 0; i < temperature_list.size(); i++) {
        if (temperature_list[i] > mid) {
            indexes.push_back(i);
        }
    }
    cout << indexes.size() << endl;
    for (auto num : indexes) {
        cout << num << " ";
    }
}

int main()
{  
    int a;
    cin >> a;
    vector<int> temperature(a);
    for (int& b : temperature) {
        cin >> b;
    }
    FindMid(temperature);
    return 0;
}

