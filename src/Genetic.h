// ============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// ===========================================================================

#pragma once

#include "Family.h"
#include <algorithm>
#include <memory>

namespace ga {

  class Genetic 
  {
  public:
    Genetic(std::string targetWord);

    void run(int iters);

  private:
    std::shared_ptr<Family> mFamily;
    std::vector<Word::LETTER> mTarget;

    const float mMutationRate = .15f;
    const float mKeepRate = .5f;

  };


}//end namespace ga