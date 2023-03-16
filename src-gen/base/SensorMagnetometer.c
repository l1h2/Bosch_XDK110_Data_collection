/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2023-03-14 13:15:33
 */


#include <XDK_SensorHandle.h>
#include <BCDS_Magnetometer.h>
#include <BCDS_Retcode.h>
#include "MitaExceptions.h"

#ifndef BCDS_MODULE_ID
#define BCDS_MODULE_ID 0xCAFE
#endif

Retcode_T SensorMagnetometer_Setup(void)
{
	Retcode_T exception = RETCODE_OK;
	exception = Magnetometer_init(XdkMagnetometer_BMM150_Handle);
	if(exception != NO_EXCEPTION) return exception;
	return Magnetometer_setPresetMode(XdkMagnetometer_BMM150_Handle, MAGNETOMETER_BMM150_PRESETMODE_REGULAR);
	
	return NO_EXCEPTION;
}

Retcode_T SensorMagnetometer_Enable(void)
{
	
	return NO_EXCEPTION;
}

