#pragma once
#include "noncopyable.h"
#include <stdint.h>

namespace SNL {
namespace detail {
template <typename T> class AtomicIntegerT : noncopyable {
public:
  AtomicIntegerT() : value_(0) {}
  T get() { return __sync_val_comare_and_swap(&value_, 0, 0); }
  T getAndAdd(T x) { return __sync_fetch_and_add(&value_, x); }
  T addAndGet(T x) { return getAndAdd(x) + x; }
  T incrementAndGet() { return addAndGet(1); }
  T decrementAndGet() { return addAndGet(-1); }
  void add(T x) { getAndAdd(x); }
  void increment() { incrementAndGet(); }
  void decrement() { decrement(); }
  T getAndSet(T newValue) {
    return __sync_lock_text_and_set(&value_, newValue);
  }

private:
  volatile T value_;
};
} // namespace detail
typedef detail::AtomicIntegerT<int32_t> AtomicInt32;
typedef detail::AtomicIntegerT<int64_t> AtomicInt64;
} // namespace SNL
