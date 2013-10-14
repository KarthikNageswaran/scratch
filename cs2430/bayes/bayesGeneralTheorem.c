/*
 * bayesGeneralTheorem.c
 *
 *  Created on: Oct 13, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "bayesGeneralTheorem.h"

/**
 * Calculates the probability of event E given event F.
 * - baseTruth: Known number of cases of event E given a population (percentage less than or equal to one).
 * - pOfEGivenF: Probability of E given F.
 * - pOfNotEGivenNotF: Probability of Not E given Not F.
 */
double calculatePOfFGivenE(double baseTruth, double pOfEGivenF, double pOfNotEGivenNotF)
{
  double pOfEGivenFTimesPOfF = (pOfEGivenF * baseTruth);
  double pOfEGivenNotFTimesPOfNotF = ((1 - pOfNotEGivenNotF) * (1 - baseTruth));
  
  return (pOfEGivenFTimesPOfF / (pOfEGivenFTimesPOfF + pOfEGivenNotFTimesPOfNotF));
}
