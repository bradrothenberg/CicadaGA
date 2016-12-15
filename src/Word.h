// ============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// ===========================================================================


//Adriana + Bradley -- a class to represent a word
//

#pragma once
#include <vector>
#include <string>
#include <random>

namespace ga {

  //! Word
  // represents one word as a vector of LETTERS, all functions to 
  // convert teh word from analytical to actual included too.
  //
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
    static LETTER getLetter(const char& letter);
    static std::string getWord(const std::vector<LETTER>& letters);
    static std::vector<LETTER> getLetters(std::string word);
  public:
    Word(int length, int randomSeed);

    LETTER getRandomLetter();

    //Get the fitness of this word compared to the target:
    std::vector<float> getFitness(const std::vector<Word::LETTER>& target)const;

    void printWord();
  private:
    std::default_random_engine mGenerator;
    std::uniform_int_distribution<int> mDistribution;

    std::vector<LETTER> mLetters;
  };
}//end namespace ga
