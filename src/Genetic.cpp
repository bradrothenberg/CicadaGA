// ============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// ===========================================================================

#include "Genetic.h"
#include "Family.h"
#include <iostream>


namespace ga {

  Genetic::Genetic(std::string targetWord)
  {
    mTarget = Word::getLetters(targetWord);
  }

  void Genetic::run(int iters) {
    mCurrentVal = 0.f;
    //setup random number generator:
    std::default_random_engine gen(.1f);
    std::uniform_int_distribution<int> dis(0, 10000000);

    std::vector<ga::Family> families;
    for ( auto i = 0; i < iters; ++i ) {
      families.push_back(ga::Family(mTarget.size(), iters, dis(gen)));
    }
   
    for ( auto i = 0; i < 100000; ++i ) {
      auto newFams = step(families);
      families = std::move(newFams);
      std::cout << "Current Val: " << std::to_string(mCurrentVal) << std::endl;
    }
  }

  std::vector<ga::Family> Genetic::step(const std::vector<ga::Family>& families)
  {
    std::vector<std::pair<float, const ga::Family*>> fitnessVals;

    for ( auto& f : families ) {
      auto summedVal = f.getOverallFitness(mTarget);
      fitnessVals.push_back(std::make_pair(summedVal, &f));
      if ( summedVal > mCurrentVal ) {
        mCurrentVal = summedVal;
      }
    }
    std::sort(begin(fitnessVals), end(fitnessVals), []
    (const std::pair<float, const Family*>& a, const std::pair<float, const Family*>& b)
    {
      return a.first < b.first;
    });
    std::vector<Word> bestWords;
    for ( auto& f : fitnessVals ) {
      auto fWords = f.second->getFittestWords(mTarget, .1f);
      bestWords.push_back(fWords[0]);
    }
    bestWords.front().printWord();

    mFamily = std::make_shared<Family>(std::move(bestWords));
    std::vector<ga::Family> famsOut;
    for ( auto& f : fitnessVals ) {
      famsOut.push_back(mFamily->breed(*f.second, mTarget));
    }
    return famsOut;
  }

}//end namespace ga