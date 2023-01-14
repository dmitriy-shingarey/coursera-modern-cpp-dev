#include "sending_notifications.h"
#include <string>

int main(int argc, char const *argv[])
{
    SmsNotifier mySmsSender("+49-123-1234-1234");
    mySmsSender.Notify("Hello! Call me back!");

    EmailNotifier myEmailSender("test@test.com");
    myEmailSender.Notify("Hello! Write me back!");
    return 0;
}
