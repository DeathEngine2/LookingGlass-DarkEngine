/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/hsrc/RCS/mksunits.h $
 * $Revision: 1.2 $
 * $Author: JAEMZ $
 * $Date: 1999/04/08 11:54:20 $
 *
 * Physics units and constants in MKS units
 *
 */

#ifndef _MKSUNITS_H
#define _MKSUNITS_H

#pragma once

// Units are all expressed in terms of SI or MKS units. (angles in radians)
// Full names are used except where acronyms are traditional and 
// non ambiguous, where they are all caps, hence: kMPH

const float kPi=3.14159265;

// Distance Units
const float kMeter=1.0;
const float kFoot=(0.3048* kMeter);
const float kYard=(3.0*kFoot);
const float kMile=(5280.0*kFoot);
const float kNauticalMile=(6000.0*kFoot);
const float kKilometer=(1000.0*kMeter);
const float kCentimeter=(kMeter/100.0);

// Volumes
const float kCubicMeter=1.0;
const float kCubicInch=(1.639e-5*kCubicMeter);
const float kGallon=(231.0*kCubicInch);
const float kCC=(1e-6);        // 1 millionth of a cubic meter
const float kLiter=(1e-3);     // 1 thousandth of a cubic meter

// Time Units
const float kSecond=1.0;
const float kMinute=(60.0*kSecond);
const float kHour=(60.0*kMinute);

// Speed Units
const float kMPH=(kMile/kHour);
const float kKnot=(kNauticalMile/kHour);
const float kFPM=(kFoot/kMinute);

// Angles
const float kDegree=(kPi/180.0);

// Angular velocity  
const float kRPM=(2.0*kPi/kMinute);

// Force Units
const float kNewton=1.0;
const float kPound=(4.448*kNewton);
const float kLBS=kPound;
const float kTon=(2000.0*kPound);        // Ton

// Pressure Units (base is newtons per meter squared)
const float kPascal=1.0;
const float kAtmosphere=(1.013e5*kPascal);
const float kPSI=(6.895e3);
const float kInchesMercury=(3.386e3);

// Energy Units
const float kJoule=1.0;
const float kErg=(1.0e-7*kJoule);

// Power Units
const float kWatt=1.0;
const float kHP=(745.7*kWatt);
 
// Temperature Units
//#define Kelvin   1.0

// Thermodynamic Units
//#define mole   1.0 


// Random physical constants
// Acceleration at the earth's surface ( m / s^2 )
const float kGravity=-9.8;

// Gas Constant
// 8.31 Joule/(mole*Kelvin)
const float kRGas=8.31;  

// Fuel density ( kg/liter)
const float kFuelDensity=.6;

// Density of water (kg/liter)
const float kWaterDensity=1;

const float k2Pi=(kPi*2.0);
const float kHalfPi(kPi*.5);

#endif


