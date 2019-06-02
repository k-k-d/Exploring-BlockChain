#include<iostream>
#include "./PicoSHA2/picosha2.h"
#include<string>
#include<fstream>
#include "DefnTransactionBlock.h"
using namespace std;

int main()
{
    ofstream file;
    bool isGenesis = true;
    int cont = 0;
    int n = 0;
    char hash[65];
    string filen = "BLOCK_";
    string h;
    do
    {
        Block b;
        b.makeBlock(hash, isGenesis);
        isGenesis = false;
        h = b.putHash();
        strcpy(hash, h.c_str());
        file.open((filen.append(to_string(n))).append(".dat"), ios::binary);
        file.write((char*)&b, sizeof(b));
        file.close();
        cout<<"\nEnter 0 to Exit or 1 to Continue with 5 further Transactions\n";
        cin>>cont;
        filen = "BLOCK_";
        n++;
    } while (cont);
    return 0;
}