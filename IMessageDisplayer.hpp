[event_receiver(native)]
class IMessageDisplayer
{
    public:
     virtual void DisplayMessage() = 0;
     virtual void hookEvent(IMessageGetter* messageGetter);
};