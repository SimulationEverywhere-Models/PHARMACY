/*******************************************************************
*
*  DESCRIPTION: Atomic Model Checkin
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

#ifndef __CHECKIN_H
#define __CHECKIN_H

#include <list>
#include "atomic.h"     // class Atomic

class Checkin : public Atomic
{
public:
	Checkin( const string &name = "Checkin" );	//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class Checkin

// ** inline ** // 
inline
string Checkin::className() const
{
	return "Checkin" ;
}

#endif   //__CHECKIN_H
