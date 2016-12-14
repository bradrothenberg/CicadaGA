
#include "Word.h"

//main function:
void main(char* argb, char* argc) {
  //setup random number generator:
  std::default_random_engine gen(.1f);
  std::uniform_real_distribution<float> dis(0.f, 1.f);
  
  std::vector<ga::Word> words;
  for (auto i = 0; i < 100; ++i) {
    words.push_back(ga::Word(dis(gen)));
    }
}