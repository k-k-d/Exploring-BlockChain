#include<iostream>
#include "./PicoSHA2/picosha2.h"
#include<string>
#include<fstream>
#include "DefnTransactionBlock.h"
using namespace std;

int main()
{
    Block b;
    string filen = "BLOCK_";
    int n = 0;
    do
    {
        ifstream file((filen.append(to_string(n))).append(".dat"), ios::binary);
        if(! file.is_open())break;
        file.read((char*)&b, sizeof(b));
        file.close();
        cout<<"\nBlock : "<<n<<"\n";
        b.putInfo();
        filen = "BLOCK_";
        n++;
    }while(true);
    return 0;
}
