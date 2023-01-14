#include <iostream>
#include <string>

using namespace std;

void SendSms(const string &number, const string &message)
{
    cout << "Sending to number " << number << " a sms-message: " << message << endl;
};
void SendEmail(const string &email, const string &message)
{
    cout << "Sending to email " << email << " a message: " << message << endl;
};

class INotifier
{
private:
    /* data */
public:
    void virtual Notify(const string &message) const = 0;
};

class SmsNotifier : public INotifier
{
private:
    string number_;

public:
    SmsNotifier(const string &number) : number_(number){};

    void Notify(const string &message) const override
    {
        SendSms(number_, message);
    }
};

class EmailNotifier : public INotifier
{
private:
    string email_;

public:
    EmailNotifier(const string &email) : email_(email){};

    void Notify(const string &message) const override
    {
        SendEmail(email_, message);
    }
};