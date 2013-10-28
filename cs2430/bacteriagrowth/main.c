/*
 * main.c
 *
 *  Created on: Oct 26, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 *
 * Bacteria growth problem solution.
 *
 * At twenty minutes the number of bacteria doubles:
 *   2 bacteria become 2^2, or 4 bacteria.
 *
 * At forty minutes the number of bacteria doubles again:
 *   4 bacteria become 4^2, or 8 bacteria.
 *
 * The bacteria only double every forty minutes and we aren't given any more detailed information. So 
 * we find that the size of the colony is defined by:
 *
 * 2 * 2^(elapsed_time / 20 minutes)
 *
 * Again review the following table:
 * Elapsed Time | Colony Size
 * -------------|-------------------------------------------------------------
 *         0 min| 2*2^(0/20)  = 2*2^0 = 2*1 = 2
 *        20 min| 2*2^(20/20) = 2*2^1 = 2*2 = 4
 *        40 min| 4*2^(40/20) = 2*2^2 = 2*4 = 8
 *           ...|...
 *
 * Formula to determine time it takes for colony of two bacteria to reach 1,000,000 based on doubling 
 * in size every twenty minutes is:
 *
 * 1000000 = 2 * 2^(total_time/20)
 *
 * To solve for total_time we rearrange it to read:
 *
 * Step 1. 1000000/2 = 2^(total_time/20)
 * Step 2. 500000 = 2^(total_time/20)
 * Step 3. log_2(500000) = total_time/20
 * Step 4. log_2(500000) * 20 = total_time
 *  or
 * total_time = 20 * log_2(500000)
 */

#include <tgmath.h>
#include <stdio.h>

int main(int argv, char * argc[])
{
  const double minutesWhenColonyDoubles = 20.0;
  const double maxSizeAtDeathOfPatient = 1000000; /* 1 million */
  const double minutesWhenBacteriaColonyReachesOneMillion = (minutesWhenColonyDoubles * (log(maxSizeAtDeathOfPatient/2) / log(2)));
  const double minutesWhenAntidoteMustBeAdministered = (2.0 /* hours */ * 60.0 /* minutes per hour */);
  const double maxTimeAntidoteMustBeAdministeredBy = (minutesWhenBacteriaColonyReachesOneMillion - minutesWhenAntidoteMustBeAdministered);
  const double maxTimeHours = floor(maxTimeAntidoteMustBeAdministeredBy / 60.0);
  const double maxTimeMinutes = floor(maxTimeAntidoteMustBeAdministeredBy - (maxTimeHours * 60.0));
  const double maxTimeSeconds = floor(((maxTimeAntidoteMustBeAdministeredBy - (maxTimeHours * 60.0)) - maxTimeMinutes) * 60);
  
  printf("Minutes until colony reaches 1,000,000: %.2f, which is about %.5f hours\n", minutesWhenBacteriaColonyReachesOneMillion, (minutesWhenBacteriaColonyReachesOneMillion / 60.0));
  printf("The antidote, which takes two hours to work, must be administered within two hours the colony reaching 1 million in size: %.2f minutes after infection\n", maxTimeAntidoteMustBeAdministeredBy);
  printf("That is it must be admiministered no later than %.2f hours (%i hrs, %i minutes, %i seconds) after infection, or the patient will die.\n", (maxTimeAntidoteMustBeAdministeredBy / 60.0), (long)maxTimeHours, (long)maxTimeMinutes, (long)maxTimeSeconds);
  
  return 0;
}
