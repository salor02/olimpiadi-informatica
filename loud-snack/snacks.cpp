// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    ofstream cout("output.txt");

    int N, X;
    cin >> N >> X;

    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    // insert your code here

    int minutes = 0;

    sort(L.begin(), L.end());

    int i = 0;
    int size = L.size() - 1;
    for(i; i < size; i++){
        if(L.at(i) + L.at(i + 1) <= X ) i++;
        minutes++;
    }

    if(i == size) minutes++;

    cout << minutes << endl; // print the result
    return 0;
}
