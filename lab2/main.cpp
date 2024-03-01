#include<iostream>
#include<cmath>
#include<set>
#include<conio.h>

using namespace std;

int main(){
    int p;
    cin >> p;
    int c_deductions = (p - 1) / 2;
    set<int> deductions;
    set<int> no_deductions;
    for(int i = 1; i < p; i++){
        no_deductions.insert(i);
    }
    for(int i = 1; i < p; i++){
        int h = (int)pow(i, 2)%p;
        deductions.insert(h);
        no_deductions.erase(h);
        if(deductions.size() == c_deductions)
            break;
    }

    cout << "Deductions" << endl;
    for(int i : deductions){
        cout << i << " ";
    }
    cout << '\n' << "No deductions" << endl;
    for(int i : no_deductions){
        cout << i << " ";
    }
    getch();
    return 0;
}



