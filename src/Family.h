// ============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// ===========================================================================

#pragma once

#include "Word.h"

namespace ga {

  class Family 
  {
  public:
      Family(int length, int size, int seed);
      Family(std::vector<Word>&& words);

      float getOverallFitness(const std::vector<Word::LETTER>& target);
      std::vector<Word> getFittestWords(const std::vector<Word::LETTER>& target, float percentage = .5f)const;

  private:
    std::vector<Word> mWords;

    std::default_random_engine mGenerator;
    std::uniform_int_distribution<int> mDistribution;

  };


}//end namespace ga