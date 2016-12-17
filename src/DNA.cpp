// =============================================================================
// Copyright 2016 Adriana + Bradley All Rights Reserved.
// =============================================================================

#include "DNA.h"

  DNA::DNA(int iLength, double mutationRate) {
    std::random_device rdt;
    std::mt19937 mtt(rdt());

    //random value within ascii characters
    std::uniform_int_distribution<int> distt(32, 128);

    //Populate this new array with random char values
    for ( int i = 0; i < iLength; ++i ) {
      mGenes.push_back((char)distt(mtt));
    }

    //Init fitness and mutation values
    mFitness = 0.0f, mMutation = mutationRate;
  }

  DNA::DNA(std::shared_ptr<DNA> parent1, std::shared_ptr<DNA> parent2) {
    std::random_device rdt;
    std::mt19937 mtt(rdt());

    //random value within gene size
    std::uniform_int_distribution<int> distt(0, parent1->GetGeneSize());

    /*Set a midpoint for deciding which parent to take gene from.
    Alternatively this could be done by doing 50/50 chance
    on each gene */
    int m = distt(mtt);

    //Begin filling cGenes array
    for ( int i = 0; i < parent1->GetGeneSize(); ++i ) {
      if ( i > m ) {
        mGenes.push_back(parent1->GetGeneAt(i));
      }
      else {
        mGenes.push_back(parent2->GetGeneAt(i));
      }
    }

    //Initiate fitness and mutation
    mFitness = 0.0f, mMutation = parent1->GetMutationRate();
  }

  void DNA::SetFitness(std::string sTarget) {
    if ( sTarget != "" ) {
      int score = 0;
      for ( int i = 0; i < mGenes.size(); ++i ) {
        if ( mGenes[i] == sTarget.at(i) ) {
          ++score;
        }
      }
      mFitness = ((double)score) / sTarget.size();
    }
  }

  void DNA::Mutate() {
    std::random_device rdt;
    std::mt19937 mtt(rdt());

    //random value 0 - 1
    std::uniform_real_distribution<double> distt(0, 1);

    //random char value
    std::uniform_int_distribution<int> distt2(32, 128);

    for ( int i = 0; i < mGenes.size(); ++i ) {
      double t = distt(mtt);
      if ( t < mMutation ) {
        mGenes[i] = distt2(mtt);
      }
    }
  }

