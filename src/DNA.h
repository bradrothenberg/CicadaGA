// =============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// =============================================================================

#pragma once
#include <memory>
#include <iostream> 
#include <string> 
#include <random> 

class DNA {
public:
  //Create from random
  DNA(int iLength, double mutationRate);

  //Create from parents
  DNA(std::shared_ptr<DNA> parent1, std::shared_ptr<DNA> parent2);

  //Grab the private mutation rate value
  double GetMutationRate() { return mMutation;}

  //Grab the private fitness value
  double GetFitness() { return mFitness;}

  //Set the fitness based on the passed target
  void SetFitness(std::string sTarget);

  //Get gene sequence as string
  std::string GetGeneString() {
    return std::string{ mGenes.begin(), mGenes.end() };
  }

  //Get size of gene array
  int GetGeneSize() {
    return mGenes.size();
  }

  //Get gene at
  char GetGeneAt(int i) {
    return mGenes[i];
  }

  //Mutate genes
  void Mutate();

private:
  std::vector<char> mGenes;
  double mFitness, mMutation;
};
