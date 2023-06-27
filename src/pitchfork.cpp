// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

/// Pitchfork
///
/// \file   pitchfork.cpp
/// \author Vincent Hamp
/// \date   30/04/2021

#include "deep_thought.hpp"

// Include a C library
extern "C" {
#include <salsa20/ecrypt-sync.h>
}

namespace pitchfork {

#if !defined(Pitchfork_ASSERT)
static_assert(false);
#endif

// Create an object from the C library
ECRYPT_ctx ctx;

/// Number 42
///
/// \return Answer to the ultimate question of life
int answer_to_the_ultimate_question_of_life_the_universe_and_everything() {
  return deep_thought_available() ? 42 : 43;
}

}  // namespace pitchfork