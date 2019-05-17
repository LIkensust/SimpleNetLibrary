#pragma once
#include "Types.h"
#include <exception>

namespace SNL {
class Execption : public std::exception {
public:
  Execption(string what);
  ~Execption() noexcept override = default;

  // Use default copy-ctor and operator=.

  const char *what() const noexcept override { return message_.c_str(); }

  const char *stackTrace() const noexcept { return stack_.c_str(); }

private:
  string message_;
  string stack_;
};
} // namespace SNL
