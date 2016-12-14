
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

  std::string Word::getWord(const std::vector<LETTER>& letters)
  {
    std::string word;
    for (auto& l : letters) {
      word += getLetter(l);
    }
    return word;
  }

  Word::Word(float randomSeed)
  {
    std::random_device rd;
    mGenerator = std::default_random_engine(rd());
    mDistribution = std::uniform_int_distribution<int>(0, 25);
    for (int i = 0; i < 6; ++i) {
      mWord.push_back(getRandomLetter());
    }
    auto word = getWord(mWord);
    
    std::cout << word << std::endl;
  }

  Word::LETTER Word::getRandomLetter()
  { 
    return (LETTER)mDistribution(mGenerator);
  }

}//end namespace ga