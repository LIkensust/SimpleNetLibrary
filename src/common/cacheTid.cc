#include "CurrentThread.h"
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
void SNL::CurrentThread::cacheTid() {
  if (t_cachedTid == 0) {
    t_cachedTid = static_cast<pid_t>(syscall(SYS_gettid));
    t_tidStringLength =
        snprintf(t_tidString, sizeof t_tidString, "%5d", t_cachedTid);
  }
}
