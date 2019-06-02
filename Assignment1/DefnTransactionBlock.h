#include<iostream>
#include "./PicoSHA2/picosha2.h"
#include<cstring>
#include<fstream>
using namespace std;

class Transaction
{
    private:
        char payer[6], payee[6];
        int amount;
    public:
        void getData()
        {
            cout<<"\nPayer\t:  ";
            cin>>Transaction::payer;
            cout<<"\nPayee\t:  ";
            cin>>Transaction::payee;
            cout<<"\nAmount\t:  ";
            cin>>Transaction::amount;
        }
        string putPayer()
        {
            return Transaction::payer;
        }
        string putPayee()
        {
            return Transaction::payee;
        }
        int putAmount()
        {
            return Transaction::amount;
        }
        void putData()
        {
            cout<<"\nPayer :  ";
            cout<<Transaction::payer;
            cout<<"\n\nPayee :  ";
            cout<<Transaction::payee;
            cout<<"\n\nAmount :  ";
            cout<<Transaction::amount;
            cout<<"\n";
        }
};

class Block
{
    private:
        Transaction t[5];
        char p_hash[65], c_hash[65];
    public:
        void makeBlock(char p_hash[65], bool isGenesis)
        {
            for(int i = 0; i < 5; i++)
            {
                cout<<"\nTransaction "<<i+1<<":\n";
                Block::t[i].getData();
            }
            cout<<"\nCreating Block......";
            if(isGenesis)
            {
                strcat(Block::p_hash, "0000000000000000000000000000000000000000000000000000000000000000");
            }
            else
            {
                strcat(Block::p_hash, p_hash);
            }
            string toHash;
            for(int i = 0; i < 5; i++)
            {
                toHash.append(t[i].putPayer());
                toHash.append(t[i].putPayee());
                toHash.append(to_string(t[i].putAmount()));
            }
            toHash.append(Block::p_hash);
            char chash[65];
            strcpy(chash, picosha2::hash256_hex_string(toHash).c_str());
            strcpy(Block::c_hash, chash);
            cout<<"\nBlock Created.\n\nHash Pointer :\t"<<Block::c_hash;
            cout<<"\nBlock Created.\n\nHash Pointer :\t"<<chash;
            cout<<"\n";
        }
        string putHash()
        {
            return Block::c_hash;
        }
        void putInfo()
        {
            cout<<"\nBlock Hash : "<<Block::c_hash<<"\n";
            cout<<"\nPrevious Block Hash : "<<Block::p_hash<<"\n";
            for(int i = 1; i <=5; i++)
            {
                cout<<"\nTransaction : "<<i<<"\n";
                Block::t[i-1].putData();
            }
        }
};