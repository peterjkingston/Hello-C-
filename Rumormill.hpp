class Rumormill : public IMessageGetter
{
    public:
        //CTOR
        Rumormill(string* pRequest);

        void MessageListen();
        string GetMessage();
    private:
        string* _pRequest;
        string _Message;  
	~Rumormill();
};