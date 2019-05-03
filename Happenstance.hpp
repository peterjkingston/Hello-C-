class Happenstance : public IMessageDisplayer
{
    public:
        Happenstance();
       	void hookEvent(IMessageGetter* pMessageGetter);

    private:
	void DisplayMessage(string _Message);
};