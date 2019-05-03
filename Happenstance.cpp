#include<iostream>
#include<cxxabi.h>
#include "Happenstance.hpp"
#include "IMessageDisplayer.hpp"

using namespace std;

Happenstance::Happenstance(){};

void Happenstance::hookEvent(IMessageGetter* pMessageGetter)
{
    __hook(&IMessageGetter::Message, pMessageGetter, &Happenstance::DisplayMessage);
};

void Happenstance::DisplayMessage(string_Message)
{
      cout << _Message;
      int status; // <-Nothing is done with status in this method, argument is used for error handling.
      char* demangled = abi::__cxa_demangle(typeid(Happenstance).name(),0,0,&status);
      cout << " <-Displayed by " << demangled << endl;
      free(demangled);
};