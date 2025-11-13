//Solve Towers of Hanoi problem for N disks.

#include <iostream>
using namespace std;

void TOH(int n,char source , char destination , char helper){
    
    if(n == 0){
        return;
    }
    TOH(n - 1 , source , helper , destination);
    cout<<"Move disk "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;
    TOH(n - 1 , helper , destination , source);

}

int main(){
    cout<<"Enter number of disks: ";
    int n;cin>>n;

    TOH(n, 'A', 'C', 'B');
    return 0;
}