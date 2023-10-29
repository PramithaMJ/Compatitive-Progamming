#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
 
     string binary;
     getline(cin, binary);

    // for(int i=0;i<binary.length();i++){
    //     if(binary[i]=='.'){

    //         //index =  binary.find('.');

    //         index = i;

    //         string fbit = binary.substr(0, i);
    //         string sbit = binary.substr(i+1, binary.length()-1);
    //         cout<<fbit<<endl;
    //         cout<<sbit<<endl;
    //         //declare two number as one in fbits and sbit
    //         int fnum = bitset<3>(fbit).to_ulong();
    //     }
    // }
string fbit = binary.substr(0, 3);
string sbit = binary.substr(3, 3);

int fnum = bitset<3>(fbit).to_ulong();
int snum = bitset<3>(sbit).to_ulong();

bitset<3> fbits(fnum);
bitset<3> sbits(snum);

int first = bitset<3>(fbits).to_ulong();
int second = bitset<3>(sbits).to_ulong();

cout << first << second << "-";

string fbit2 = binary.substr(7, 3);
string sbit2 = binary.substr(10, 3);

int fnum2 = bitset<3>(fbit2).to_ulong();
int snum2 = bitset<3>(sbit2).to_ulong();

bitset<3> fbits2(fnum2);
bitset<3> sbits2(snum2);

int first2 = bitset<3>(fbits2).to_ulong();
int second2 = bitset<3>(sbits2).to_ulong();

cout << first2 << second2 << "-";





string fbit3 = binary.substr(14, 3);
string sbit3 = binary.substr(17, 3);

int fnum3 = bitset<3>(fbit3).to_ulong();
int snum3 = bitset<3>(sbit3).to_ulong();

bitset<3> fbits3(fnum3);
bitset<3> sbits3(snum3);

int first3 = bitset<3>(fbits3).to_ulong();
int second3 = bitset<3>(sbits3).to_ulong();

cout << first3 << second3 ;


    return 0; 
}