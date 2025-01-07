#include "drlog.h"
#include <iostream>
using namespace std;

int main() {
    drlog::logger lg;
    lg.info("This is an info!");
    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");
    lg.log("This is a log!");
    lg.debug("This is a debug!");

    cout << "***********************************" << endl;

    lg.set_format("{TYPE}: {MESSAGE}");
    lg.set_debug_style("DEBUG");
    lg.set_info_style("INFO");
    lg.set_warn_style("WARN");
    lg.set_error_style("ERROR");
    lg.set_note_style("NOTE");
    lg.set_log_style("LOG");

    lg.info("This is an info!");
    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");
    lg.log("This is a log!");
    lg.debug("This is a debug!");

    cout << "***********************************" << endl;

    lg.recover_format();
    lg.recover_all_type_style();

    lg.info("This is an info!");
    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");
    lg.log("This is a log!");
    lg.debug("This is a debug!");

    return 0;
}