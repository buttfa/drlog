#ifndef __DRLOG_H__
#define __DRLOG_H__

#include <string>

namespace drlog {

class msg_info {
  public:
    std::string type;
    std::string msg;
    std::string file;
    std::string line;
    std::string function;
    std::string pretty_function;

    msg_info(std::string type, std::string msg) {
        this->type = type;
        this->msg = msg;
        this->file = "";
        this->line = "";
        this->function = "";
        this->pretty_function = "";
    };

    msg_info(std::string file, std::string line, std::string function,
             std::string pretty_function) {
        this->file = file;
        this->line = line;
        this->function = function;
        this->pretty_function = pretty_function;
    };
};

#define DR_INFO                                                                \
    drlog::msg_info(__FILE__, std::to_string(__LINE__), __FUNCTION__,          \
                    __PRETTY_FUNCTION__)

class logger {
  private:
    std::string format;

    std::string info_style;

    std::string note_style;
    std::string warn_style;
    std::string error_style;

    std::string log_style;
    std::string debug_style;

    std::string replace(drlog::msg_info info);

  public:
    logger();
    logger(std::string format);

    void set_format(std::string format);

    void info(std::string msg);
    void info(std::string msg, drlog::msg_info info);

    void note(std::string msg);
    void note(std::string msg, drlog::msg_info info);

    void warn(std::string msg);
    void warn(std::string msg, drlog::msg_info info);

    void error(std::string msg);
    void error(std::string msg, drlog::msg_info info);

    void log(std::string msg);
    void log(std::string msg, drlog::msg_info info);

    void debug(std::string msg);
    void debug(std::string msg, drlog::msg_info info);

    void set_info_style(std::string style);
    void set_note_style(std::string style);
    void set_warn_style(std::string style);
    void set_error_style(std::string style);
    void set_log_style(std::string style);
    void set_debug_style(std::string style);

    // void recovery_format();
    // void recovery_all_type_style();
};
} // namespace drlog

#endif