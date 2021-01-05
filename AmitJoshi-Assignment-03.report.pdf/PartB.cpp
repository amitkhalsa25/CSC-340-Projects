#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;
bool isvalidcc(const string&);
//Name:Amit Joshi
//ASMT03 Part B

int main() {
    //
    // PLEASE DO NOT CHANGE function main
    //

    vector<string> cardnumbers = {
     "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
     "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
    "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
    "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
    "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
    "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
    "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
    "5556551555555557", "6011316011016011"
 };
    int i;
    vector<string>::iterator itr;
    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
        cout << setw(2) << i << " "
            << setw(17) << *itr
            << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
    }
    return 0;
}
bool isvalidcc(const string& num) {
    int n = num.length();
    //validates that card has more than 13 and less than 16 digits
    if (num.length() >= 13 && num.length() <= 16) {
        //validates that the first int of the card matches that of the given cardtype
     if (num.at(0) == '4' || num.at(0) == '5' || num.at(0) == '6' || num.at(0) == '3') {
            // Set three integer values = 0;
            int odd = 0;
            int dub = 0;
            int sum = 0;
            //Thid loop will only take every second value from num
            for (int i = n - 2; i >= 0; i = i - 2) {
                //Began math operations
                dub = (num[i] - '0') * 2;
                dub = dub % 10 + (dub / 10) % 10;
                sum += dub;
            }
            for (int i = n - 1; i >= 0; i = i - 2) {
                odd = (num[i] - '0');
                sum += odd;
            }
            if (sum % 10 == 0)
                return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
