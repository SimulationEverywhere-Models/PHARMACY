/*******************************************************************
*
*  DESCRIPTION: class Consulting
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

#ifndef __CONSULTING_H
#define __CONSULTING_H
#include "atomic.h"  // class Atomic

class Distribution ;

class Consulting: public Atomic
{
public:
	Consulting( const string &name = "Consulting" ) ;	 

	~Consulting();					

	virtual string className() const
		{return "Consulting";}

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
};	// class Consulting


#endif   //__CONSULTING_H 
