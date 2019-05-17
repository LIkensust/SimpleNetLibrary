#include "Execption.h"
#include "CurrentThread.h"

namespace SNL {
Execption::Execption(string msg)
    : message_(std::move(msg)), stack_(CurrentThread::stackTrace(false)) {
} // stackTrace(false) means demangle

} // namespace SNL
