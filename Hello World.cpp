#include<iostream>
#include<cxxabi.h>

/* To compile, use the following command lines in the console:
 * cd [current directory]
 * g++ -o[out to file] [.cpp file]
 * ./[out to file]
*/

using namespace std;

class IMessageDisplayer
{
    public:
     virtual void DisplayMessage() = 0;
};

class IMessageGetter
{
    public:
    virtual void MessageListen()= 0;
    virtual string GetMessage()= 0;
};

class Happenstance : public IMessageDisplayer
{
    public:
        //CTOR
        Happenstance(IMessageGetter* messageGetter)
        {
            _Message = messageGetter->GetMessage();
        }
        
        void DisplayMessage()
        {
            cout << _Message;
            int status;
            char * demangled = abi::__cxa_demangle(typeid(Happenstance).name(),0,0,&status);
            cout << " <-Displayed by " << demangled << endl;
            free(demangled);
        }   

    private:
        string _Message;
};

class Rumormill : public IMessageGetter
{
    public:
        //CTOR
        Rumormill(string request){_Request = request;};

        void MessageListen()
        {
            cout << _Request << endl;

            char input[100];
            cin.getline(input,sizeof(input));
            _Message = input;
        }
        string GetMessage()
        {
            return _Message;
        }
    private:
        string _Request;
        string _Message;    
};

int main()
{
    string greet = "Type your message here";
    IMessageGetter* chattyCathy = new Rumormill(greet);
    chattyCathy->MessageListen();
    IMessageDisplayer* greeter = new Happenstance(chattyCathy);
    
    for(int i = 0; i < 5; i++){
        greeter->DisplayMessage();
    }
    cout << "\t...by the way, " << chattyCathy->GetMessage() << " has " << chattyCathy->GetMessage().size() << " characters" << "\n";
    
    delete greeter;
    delete chattyCathy;
    return 0;
}


