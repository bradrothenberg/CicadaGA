
// ============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// ===========================================================================


#include "Word.h"
#include <iostream>

namespace ga {
  
  std::string Word::getLetter(LETTER letter)
  {
    switch (letter) {
      case ga::Word::A:
        return "a";
      case ga::Word::B:
        return "b";
      case ga::Word::C:
        return "c";
      case ga::Word::D:
        return "d";
      case ga::Word::E:
        return "e";
      case ga::Word::F:
        return "f";
      case ga::Word::G:
        return "g";
      case ga::Word::H:
        return "h";
      case ga::Word::I:
        return "i";
      case ga::Word::J:
        return "j";
      case ga::Word::K:
        return "k";
      case ga::Word::L:
        return "l";
      case ga::Word::M:
        return "m";
      case ga::Word::N:
        return "n";
      case ga::Word::O:
        return "o";
      case ga::Word::P:
        return "p";
      case ga::Word::Q:
        return "q";
      case ga::Word::R:
        return "r";
      case ga::Word::S:
        return "s";
      case ga::Word::T:
        return "t";
      case ga::Word::U:
        return "u";
      case ga::Word::V:
        return "v";
      case ga::Word::W:
        return "w";
      case ga::Word::X:
        return "x";
      case ga::Word::Y:
        return "y";
      case ga::Word::Z:
        return "z";
      default:
        break;
    }
    return " ";
  }

  ga::Word::LETTER Word::getLetter(const char& letter) {
    switch ( letter ) {
      case 'a':
        return ga::Word::A;
      case 'b':
        return ga::Word::B;
      case 'c':
        return ga::Word::C;      
      case 'd':
        return ga::Word::D;
      case 'e':
        return ga::Word::E;
      case 'f':
        return ga::Word::F;
      case 'g':
        return ga::Word::G;
      case 'h':
        return ga::Word::H;
      case 'i':
        return ga::Word::I;
      case 'j':
        return ga::Word::J;
      case 'k':
        return ga::Word::K;
      case 'l':
        return ga::Word::L;
      case 'm':
        return ga::Word::M;
      case 'n':
        return ga::Word::N;
      case 'o':
        return ga::Word::O;
      case 'p':
        return ga::Word::P;
      case 'q':
        return ga::Word::Q;
      case 'r':
        return ga::Word::R;
      case 's':
        return ga::Word::S;
      case 't':
        return ga::Word::T;
      case 'u':
        return ga::Word::U;
      case 'v':       
        return ga::Word::V;
      case 'w':
        return ga::Word::W;
      case 'x':
        return ga::Word::X;
      case 'y':
        return ga::Word::Y;
      case 'z':
        return ga::Word::Z;
      default:
        break;
    }
  }

  std::string Word::getWord(const std::vector<LETTER>& letters)
  {
    std::string word;
    for (auto& l : letters) {
      word += getLetter(l);
    }
    return word;
  }

  std::vector<ga::Word::LETTER> Word::getLetters(std::string word) {
    std::vector<LETTER> letters;
    for ( auto& w : word ) {
      letters.push_back(getLetter(w));
    }
    return letters;
  }

  Word::Word(int length, int randomSeed)
  {
    mGenerator = std::default_random_engine(randomSeed);
    mDistribution = std::uniform_int_distribution<int>(0, 25);
    for (int i = 0; i < length; ++i) {
      mLetters.push_back(getRandomLetter());
    }
  }

  Word::LETTER Word::getRandomLetter()
  { 
    return (LETTER)mDistribution(mGenerator);
  }

  std::vector<float> Word::getFitness(const std::vector<Word::LETTER>& target) const {
    std::vector<float> fitness;
    //loop through each letter & see how close you are:
    int idx = 0;
    for ( auto& l : mLetters ) {
      auto dist = ( 26.f - std::fabs((float)l - (float)target[idx]) ) / 26.f;
      fitness.push_back(dist);
      idx++;
    }
    return fitness;
  }

  void Word::printWord() {
    auto word = getWord(mLetters);
    std::cout << word << std::endl;
  }

}//end namespace ga