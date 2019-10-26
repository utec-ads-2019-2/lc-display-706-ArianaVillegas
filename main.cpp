#include <iostream>

using namespace std;

bool numbers[10][7]={{1,1,1,0,1,1,1},
                     {0,0,1,0,0,1,0},
                     {1,0,1,1,1,0,1},
                     {1,0,1,1,0,1,1},
                     {0,1,1,1,0,1,0},
                     {1,1,0,1,0,1,1},
                     {1,1,0,1,1,1,1},
                     {1,0,1,0,0,1,0},
                     {1,1,1,1,1,1,1},
                     {1,1,1,1,0,1,1}};

void printHorizontal(int s,string n, int digit){
    for(int i=0;i<n.size();++i) {
        if(i) cout << ' ';
        cout << ' ';
        if (numbers[int(n[i])-48][digit]) for (int i = 0; i < s; ++i) cout << '-';
        else for (int i = 0; i < s; ++i) cout << ' ';
        cout << ' ';
    }
}

void printVertical(int s,string n, int digit){
    for(int i=0;i<s;++i){
        for(int j=0;j<n.size();++j) {
            if(j) cout << ' ';
            if (numbers[int(n[j])-48][digit]) cout << '|';
            else cout << ' ';
            for (int i = 0; i < s; ++i) cout << ' ';
            if (numbers[int(n[j])-48][digit + 1]) cout << '|';
            else cout << ' ';
        }
        cout << "\n";
    }
}

void printNumber(int s,string n){
    printHorizontal(s,n,0); cout << "\n";
    printVertical(s,n,1);
    printHorizontal(s,n,3); cout << "\n";
    printVertical(s,n,4);
    printHorizontal(s,n,6); cout << "\n\n";
}

int main() {
    unsigned int s;
    string n; cin>>s>>n;
    while(s || n[0]!='0') {
        printNumber(s, n);
        cin>>s>>n;
    }
    return 0;
}