/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2023-03-14 13:15:33
 */


#ifndef MITA_TIME_H
#define MITA_TIME_H

#include <BCDS_Retcode.h>


Retcode_T SetupTime(void);

Retcode_T EnableTime(void);

Retcode_T EveryHandleEvery10Millisecond1_Enable(void);
Retcode_T EveryHandleEvery1Minute1_Enable(void);


#endif