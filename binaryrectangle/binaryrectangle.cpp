// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int ans = 0;
        int N, M;
        cin >> N >> M;

        vector<string> line(N);
        for (int i = 0; i < N; ++i){
            cin >> line[i];
        }

        int l = -1;
        int first = string::npos;
        bool bound = false;

        for(int i = 0; i < N; i++){
            int ones = count(line[i].begin(), line[i].end(), '1');


            if(ones > 0){
                //if an oil field is bounded you cannot add other ones. That's a vertical contiguity check.
                if(bound){
                    ans = 0;
                    break;
                }
                int first_pos = line[i].find('1');
                int last_pos = line[i].find_last_of('1');

                //oil field starts here
                if(l == -1){
                    l = ones;
                    first = first_pos;
                    ans = 1;
                }

                //different number of ones or different starting position
                if(ones != l || first_pos != first){
                    ans = 0;
                    break;
                }

                //contiguity check
                if(last_pos - first_pos + 1 != ones){
                    ans = 0;
                    break;
                }
            }
            else{
                //oil field ends here
                if(ans == 1){
                    bound = true;
                }
            }
            
        }
        cout << ans << endl;
    }

    return 0;
}
