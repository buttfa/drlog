#ifndef __DRLOG_H__
#define __DRLOG_H__

#include <string>

namespace drlog {

#define TYPE
#define MESSAGE

#define YEAR
#define MONTH
#define DAY
#define HOUR
#define MINUTE
#define SECOND
#define TIMESTAMP

class logger {
  private:
    std::string format;

    std::string info_style;

    std::string note_style;
    std::string warn_style;
    std::string error_style;

    std::string log_style;
    std::string debug_style;

    std::string replace(std::string type, std::string msg);

  public:
    // logger();
    logger(std::string format);

    void set_info_style(std::string style);
    void info(std::string msg);

    void set_note_style(std::string style);
    void note(std::string msg);
    void set_warn_style(std::string style);
    void warn(std::string msg);
    void set_error_style(std::string style);
    void error(std::string msg);

    void set_log_style(std::string style);
    void log(std::string msg);
    void set_debug_style(std::string style);
    void debug(std::string msg);

    void set_format(std::string format);

    // void recovery_format();
    // void recovery_all_style();
};
} // namespace drlog

#endif