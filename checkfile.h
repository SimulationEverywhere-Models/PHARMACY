/*******************************************************************
*
*  DESCRIPTION: class Checkfile 
*
*  AUTHOR: Babak Simaie
*
*  STUDENT#: 3928012
*
*  EMAIL: bsimaie@gmail.com
*
*  DATE: 26/10/2007
*
*******************************************************************/

#ifndef __CHECKFILE_H
#define __CHECKFILE_H
#include "atomic.h"  // class Atomic

class Distribution ;

class Checkfile: public Atomic
{
public:
	Checkfile( const string &name = "Checkfile" ) ;	 

	~Checkfile();					

	virtual string className() const
		{return "Checkfile";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Port &done ;
	Distribution *dist ;
	int pid ;

	Distribution &distribution()
			{return *dist;}
};	// class Checkfile


#endif   //__CHECKFILE_H 
