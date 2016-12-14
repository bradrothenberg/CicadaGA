//Adriana + Bradley -- a class to represent a word
//

#pragma once
#include <vector>
#include <string>
#include <random>

namespace ga {
  class Word {
  public:
    enum LETTER {
      A,
      B,
      C,
      D,
      E,
      F,
      G,
      H,
      I,
      J,
      K,
      L,
      M,
      N,
      O,
      P,
      Q,
      R,
      S,
      T,
      U,
      V,
      W,
      X,
      Y,
      Z
    };
    static std::string getLetter(LETTER letter);
    static std::string getWord(const std::vector<LETTER>& letters);
  public:
    Word(float randomSeed);

    LETTER getRandomLetter();
  private:
    std::default_random_engine mGenerator;
    std::uniform_int_distribution<int> mDistribution;

    std::vector<LETTER> mWord;
  };
}//end namespace ga
