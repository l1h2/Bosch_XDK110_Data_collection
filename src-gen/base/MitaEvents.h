/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2023-03-14 13:15:33
 */


#ifndef MITA_EVENTS_H
#define MITA_EVENTS_H

#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <BCDS_CmdProcessor.h>


extern CmdProcessor_T Mita_EventQueue;

Retcode_T HandleEveryXDK110Startup1(void* userParameter1, uint32_t userParameter2);

Retcode_T HandleEvery10Millisecond1(void* userParameter1, uint32_t userParameter2);

Retcode_T HandleEvery1Minute1(void* userParameter1, uint32_t userParameter2);


#endif