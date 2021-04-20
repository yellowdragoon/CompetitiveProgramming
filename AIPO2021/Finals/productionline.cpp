#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for (int i = a; i < b; i++)
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    int c, t, q, t2, sum, average;
    char y;
    cin >> c;
    vi line = {};
    int fails[c] = {0};
    REP(i, 0, c){
        cin >> t;
        line.push_back(t);
    }

    int totalfails = 0;

    cin >> q;

    REP(i, 0, q){
        sum = 0;
        cin >> y;
        if(y == 'F'){
            
            cin >> t;
            REP(i, 0, c){
                if(line[i] != 0){
                    t --;
                }
                if(t == -1){
                    line[i] = 0;
                    //cout << "fail at" << i << "\n";
                    break;
                }
            }

            

            totalfails ++;
        }
        else if(y == 'Q'){
            int min = 100;
            int numbertobesearched = 0;
            int index = 0;
            
            cin >> t >> t2;
            int tempy = t;
            REP(i, 0, c){
                if(line[i] != 0){
                    tempy --;
                }
                if(tempy == -1){
                    index = i;
                    break;
                }
            }
            //cout << "index start at: " << index << "\n";

            

            numbertobesearched = t2-t + 1;
            while(numbertobesearched != 0){
                if(index > line.size() - 1){
                    break;
                }
                if(line[index] == 0){
                    
                    index++;
                    continue;
                }
                else{
                    sum += line[index];
                    numbertobesearched --;
                    if(line[index] < min){
                        min = line[index];
                    }
                }
                index ++;
                //cout << "current sum: " << sum << "\n";
                
                
            }
            cout << sum << " " << min;
            if(i != q-1){
                cout << "\n";
            }
            


        }

        else{
            
            int temp = c;
            //cout <<"test";
            cin >> t;
            temp = t;
            REP(i, 0, c){
                if(line[i] != 0){
                    t --;
                }
                if(t == -1){
                    //cout << i << " ";
                    if(line[i - 1] == 0 || line[i + 1] == 0){
                        cout << "YES";
                    }
                    else{
                        cout << "NO";
                    }
                    
                        cout << "\n";
                        break;
                    
                    }
            }
            
        
        }
    }
    
    cin.tie(0);
    return 0;
}
