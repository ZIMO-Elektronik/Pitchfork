#include <gtest/gtest.h>
#include <pitchfork/pitchfork.hpp>

TEST(pitchfork,
     answer_to_the_ultimate_question_of_life_the_universe_and_everything) {
  EXPECT_EQ(
    pitchfork::
      answer_to_the_ultimate_question_of_life_the_universe_and_everything(),
    42);
}
