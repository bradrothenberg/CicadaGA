// ============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// ===========================================================================

#include "Family.h"
#include <numeric>
#include <algorithm>

namespace ga {

  Family::Family(int length, int size, int seed)
  {
    mGenerator = std::default_random_engine(seed);
    mDistribution = std::uniform_int_distribution<int>(0, 10000000);

    for ( auto i = 0; i < 100; ++i ) {
      mWords.push_back(ga::Word(length, mDistribution(mGenerator)));
    }
  }

  Family::Family(std::vector<Word>&& words) 
  {
    mWords = std::move(words);
  }

  float Family::getOverallFitness(const targetWord& target) const
  {
    float totalVal{ 0.f };
    for ( auto& w : mWords ) {
      auto fitVals = w.getFitness(target);
      auto summedVal = std::accumulate(fitVals.begin(), fitVals.end(), 0.f) / (float)fitVals.size();
      totalVal += summedVal;
    }
    return totalVal /= (float)mWords.size();
  }

  std::vector<ga::Word> Family::getFittestWords(const targetWord& target,
                                                float percentage /*= .5f*/) const 
  {
    //Store fitness vals & then sort by size
    std::vector<std::pair<float,const Word*>> fitnessVals;
    for ( auto& w : mWords ) {
      auto fitVals = w.getFitness(target);
      auto summedVal = std::accumulate(fitVals.begin(), fitVals.end(), 0.f);
      fitnessVals.push_back(std::make_pair(summedVal, &w));
    }
    std::sort(begin(fitnessVals), end(fitnessVals), []
    (const std::pair<float, const Word*>& a, const std::pair<float, const Word*>& b)
    {
      return a.first < b.first;
    });
    int count = (int)mWords.size()*percentage;

    std::vector<ga::Word> wordsOut;
    for ( auto i = 0; i < count; ++i ) {
      wordsOut.push_back(*fitnessVals[i].second);
    }
    return wordsOut;
  }

  ga::Family Family::breed(const Family& fam, 
                                   const targetWord& target, 
                                   float percentage /*= .5f*/) const 
  {
    auto words1 = getFittestWords(target, 1.0);
    auto words2 = getFittestWords(target, 1.0);
    std::vector<Word> words;
    for ( auto i = 0; i < words1.size(); ++i ) {
      auto& w1 = words1[i];
      auto& w2 = words2[i];

      words.push_back(w1.breed(w2));
    }
    return ga::Family(std::move(words));
  }

}//end namespace ga