#include<iostream>
#include<cxxabi.h>

/* To compile, use the following command lines in the console:
 * cd [current directory]
 * g++ -o[out to file] [.cpp file]
 * ./[out to file]
*/

using namespace std;

[event_receiver(native)]
class IMessageDisplayer
{
    public:
     virtual void DisplayMessage() = 0;
     virtual void hookEvent(IMessageGetter* messageGetter);
};

[event_source(native)]
class IMessageGetter
{
    public:
    virtual void MessageListen()= 0;
    virtual string GetMessage()= 0;
    __event virtual void MessageCollected(string message);
};

class Happenstance : public IMessageDisplayer
{
    public:
        //CTOR
        Happenstance(){};
        
	void hookEvent(IMessageGetter* pMessageGetter)
	{
	    __hook(&IMessageGetter::Message, pMessageGetter, &Happenstance::DisplayMessage);
	}

    private:
	void DisplayMessage(string _Message)
        {
            cout << _Message;
            int status; // <-Nothing is done with status in this method, argument is used for error handling.
            char* demangled = abi::__cxa_demangle(typeid(Happenstance).name(),0,0,&status);
            cout << " <-Displayed by " << demangled << endl;
            free(demangled);
        }
};

class Rumormill : public IMessageGetter
{
    public:
        //CTOR
        Rumormill(string* pRequest){_pRequest = pRequest;};

        void MessageListen()
        {
            cout << *_pRequest << endl;

            char input[100];
            cin.getline(input,sizeof(input));
            _Message = input;
	    _raise this.MessageCollected(_Message);
        }
        string GetMessage()
        {
            return _Message;
        }
    private:
        string* _pRequest;
        string _Message;  
	~Rumormill()
	{
	    _pRequest = nullptr;
	}  
};

int main()
{
    string requestToUser = "Type your message here";

    IMessageGetter* pChattyCathy = new Rumormill(&requestToUser);
    IMessageDisplayer* pGreeter = new Happenstance();
    pGreeter->hookEvent(pChattyCathy);

    pChattyCathy->MessageListen();

    cout << "\t...by the way, " << chattyCathy->GetMessage() << " has " << chattyCathy->GetMessage().size() << " characters" << "\n";
    
    delete greeter;
    delete chattyCathy;
    return 0;
}
