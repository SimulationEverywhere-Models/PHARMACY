/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Babak Simaie
*
*  STUDENT#: 3928012
*
*  EMAIL: bsimaie
*
*  DATE: 26/10/2007
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "checkin.h"      // class Checkin
#include "checkfile.h"        // class Checkfile
#include "filling.h"        // class Filling
#include "consulting.h"        // class Consulting



void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Checkin>() , "Checkin" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Checkfile>() , "Checkfile" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Filling>(), "Filling" ) ;  
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Consulting>(), "Consulting" ) ; 
} 

