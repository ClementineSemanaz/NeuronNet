#include "random.h"
#include <random> 

RandomNumbers::RandomNumbers(unsigned long int s) : seed (s)
{
	if (s==0)
	{
		std::random_device rd; 
		seed=rd();
	}
   rng = std::mt19937(seed); 
}

void 	RandomNumbers::uniform_double (std::vector< double > & numbers, double lower, double upper)
{
	std::uniform_real_distribution<double> dis(lower,upper); 
		for (size_t i=0; i<numbers.size(); ++i)
		{
			numbers[i]=dis(rng);
		}
}

double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> dis(lower,upper);
	return dis(rng);
}

void RandomNumbers::normal(std::vector<double>& numbers, double mean, double sd)
{
	std::normal_distribution<double> dis (mean, sd);
	for (size_t i=0; i<numbers.size(); ++i) 
		{
			numbers[i]=dis(rng);
		}
}

double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<double> dis (mean, sd);
	return dis(rng);
}

void RandomNumbers::poisson(std::vector<int>& numbers, double mean)
{
	std::poisson_distribution<> dis (mean);
	for (size_t i=0; i<numbers.size(); ++i) 
		{
			numbers[i]=dis(rng);
		}
}
   

int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<> dis (mean);
	return dis(rng);
}
