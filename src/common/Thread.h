#pragma once

#include "Atomic.h"
#include "CountDownLatch.h"
#include "Types.h"

#include <functional>
#include <memory>
#include <pthread.h>

namespace SNL {
class Thread : noncopyable {
public:
  typedef std::function<void()> ThreadFunc;
  // FIXME: make it movable in C++11
  explicit Thread(ThreadFunc, const string &name = string());
  ~Thread();
  void start();
  int join(); // return pthread_join()
  bool started() const { return started_; }

private:
  void setDefaultName();
  bool started_;
  bool joined_;
  pthread_t pthreadId_;
  pid_t tid_;
  ThreadFunc func_;
  string name_;
  CountDownLatch latch_;

  static AtomicInt32 numCreated_;
};
} // namespace SNL
