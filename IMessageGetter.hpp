[event_source(native)]
class IMessageGetter
{
    public:
    virtual void MessageListen()= 0;
    virtual string GetMessage()= 0;
    __event virtual void MessageCollected(string message);
};