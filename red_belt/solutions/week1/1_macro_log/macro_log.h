#include <sstream>
#include <string>
using namespace std;

class Logger
{
public:
    explicit Logger(ostream &output_stream) : os(output_stream)
    {
    }

    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file = value; }

    bool LogFile(string file)
    {
        file_ = file;
    }
    bool LogLine(int line)
    {
        line_ = line;
    }

    void Log(const string &message)
    {
        if (log_file && log_line)
        {
            os << file_ << ":" << line_ << " ";
        }
        if (log_file && !log_line)
        {
            os << file_ << " ";
        }
        if (!log_file && log_line)
        {
            os << "Line " << line_ << " ";
        }
        os << message << endl;
    };

private:
    ostream &os;
    bool log_line = false;
    bool log_file = false;
    string file_;
    int line_;
};
