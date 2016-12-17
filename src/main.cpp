
#include "dna.h"

//main function:
int main(char* argb, char* argc) {
  //Random device
  std::random_device rd;
  std::mt19937 mt(rd());

  //DNA population containers
  std::vector<std::shared_ptr<DNA>> population;
  std::vector<std::shared_ptr<DNA>> pool;

  //Variables
  int geneLength = 0, populationSize;
  double mutationRate = 0.01;
  std::string tempString, target;

  //Display
  std::cout << "Genetic Algorithm C++ from Nature of Code" <<  std::endl;

  //Get initial Population from user.
  std::cout << "Enter Population Size (int): ";
  std::getline(std::cin, tempString);
  populationSize = std::stoi(tempString);
  std::cout << "Selected Population Size (int): " << populationSize << std::endl;

  //Get initial mutation rate from user.
  std::cout << "Enter Mutation Rate (double, eg: 0.01): ";
  std::getline(std::cin, tempString);
  if ( tempString.empty() ) {
    mutationRate = .01;
  }
  else {
    mutationRate = std::stod(tempString);
  }
  std::cout << "Selected Mutation Rate (double): " << mutationRate << std::endl;
  tempString = "";

  //Get the target string.
  std::cout << "Type a sentence for the target: ";
  std::getline(std::cin, target);
  std::cout << std::endl;

  //Initialize loop trackers.
  geneLength = target.size();
  bool bReachedGoal = false;
  unsigned long lGeneration = 1;

  //Initiate population
  for ( int i = 0; i < populationSize; ++i ) {
    std::shared_ptr<DNA> temp(new DNA(geneLength, mutationRate));
    population.push_back(temp);
  }

  //Begin the Circle Of Life™
  while ( !bReachedGoal ) {

    //Print Info
    std::cout << "Generation: " << lGeneration << std::endl;

    //Determine fitness and print highest and gene
    for ( auto it = population.begin(); it != population.end(); ++it ) {
      (*it)->SetFitness(target);
    }
    double highest = 0;
    int index = 0;
    for ( auto it = population.begin(); it != population.end(); ++it ) {
      if ( (*it)->GetFitness() > highest ) {
        highest = (*it)->GetFitness();
        index = it - population.begin();
      }
    }

    //Output results, and check if target has been met.
    std::cout << "Highest Fitness: " << highest * 100.0 << "% with gene sequence: "
      << population.at(index)->GetGeneString() << std::endl;
    if ( highest == 1 ) {
      bReachedGoal = true;
      std::cout << "\nFinished. Press enter to exit the program." << std::endl;
      std::cin.ignore();
    }

    //Fill out mating pool
    pool.clear();
    for ( auto it = population.begin(); it != population.end(); ++it ) {
      int n = (*it)->GetFitness() * 100;
      for ( int i = 0; i < n; ++i ) {

        /*Create a new shared_ptr i number of times based on
        the fitness. */
        pool.push_back((*it));
      }
    }

    /* Clear old population
    (not realistic but deal, other options are removing x number with worst fitness or adding an age parameter etc..)*/
    population.clear();

    //Mate pairs to recreate population
    std::uniform_int_distribution<int> dist2(0, pool.size() - 1);

    //Refill population to same size as it was with new DNA
    for ( int i = 0; i < populationSize; ++i ) {

      //Init iterators
      int x = 0;
      int y = 0;

      //Set random value based on size of pool container
      x = dist2(mt);
      y = dist2(mt);

      //Make sure not to use the same parent twice
      while ( pool[x] == pool[y] ) {
        y = dist2(mt);
      }

      //Create new DNA based on parents
      std::shared_ptr<DNA> temp(new DNA(pool.at(x), pool.at(y)));

      //Add mutation
      temp->Mutate();

      //Place new DNA in population container
      population.push_back(temp);
    }

    //Increase generation
    ++lGeneration;
  }
  return 0;
}