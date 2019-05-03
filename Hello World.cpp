#include<iostream>
#include "Happenstance.hpp"
#include "Rumormill.hpp"

/* To compile, use the following command lines in the console:
 * cd [current directory]
 * g++ -o[out to file] [.cpp file]
 * ./[out to file]
*/

using namespace std;

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
