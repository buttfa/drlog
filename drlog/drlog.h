#ifndef __DRLOG_H__
#define __DRLOG_H__

#include <string>

namespace drlog {

// class msg_info {
//   public:
//     std::string type;
//     std::string file;
//     std::string line;
//     std::string function;
//     std::string pretty_function;

//     msg_info(std::string file, std::string line, std::string function,
//              std::string pretty_function) {
//         this->file = file;
//         this->line = line;
//         this->function = function;
//         this->pretty_function = pretty_function;
//     };
// };

// #define DR_INFO                                                                \
//     drlog::msg_info(__FILE__, to_string(__LINE__), __FUNCTION__,               \
//                     __PRETTY_FUNCTION__)

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
    logger();
    logger(std::string format);

    void set_format(std::string format);

    void set_info_style(std::string style);
    void info(std::string msg);
    // void info(std::string msg, drlog::msg_info info);

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

    // void recovery_format();
    // void recovery_all_style();
};
} // namespace drlog

#endif