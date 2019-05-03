#include<iostream>
#include "Rumormill.hpp"
#include "IMessageGetter.hpp"

using namespace std;

Rumormill::Rumormill(string* pRequest){_pRequest = pRequest;};

void Rumormill::MessageListen()
        {
            cout << *_pRequest << endl;

            char input[100];
            cin.getline(input,sizeof(input));
            _Message = input;
	    _raise this.MessageCollected(_Message);
        }

string Rumormill::GetMessage()
        {
            return _Message;
        }

Rumormill::~Rumormill()
	{
	    _pRequest = nullptr;
	}  
};