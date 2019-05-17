#pragma once
#include "StringPiece.h"
#include "Types.h"
#include "noncopyable.h"

#include <assert.h>
#include <string.h>

namespace SNL {
namespace detail {
const int KSmallBuffer = 4000;
const int KLargeBuffer = 4000 * 1000;

template <int SIZE> class FixedBuffer : noncopyable {};
} // namespace detail
} // namespace SNL
