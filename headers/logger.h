#pragma once
#include <string>

namespace logger {
  enum level {
    ERROR = 0,
    WARNING = 1,
    INFO = 2,
    DEBUG = 3,
    TRACE = 4,
  };

  inline std::string COLOR_RED = "\e[0;31m";
  inline std::string COLOR_CYAN = "\e[0;36m";
  inline std::string COLOR_YELLOW = "\e[0;33m";

  void log(level lv, const std::string& message);
}

