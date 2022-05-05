/*******************************************************************
*
*  DESCRIPTION: Atomic Model Filling
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

#ifndef __FILLING_H
#define __FILLING_H

#include <list>
#include "atomic.h"     // class Atomic

class Filling : public Atomic
{
public:
	Filling( const string &name = "Filling" );	//Default constructor

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

};	// class Filling

// ** inline ** // 
inline
string Filling::className() const
{
	return "Filling" ;
}

#endif   //__FILLING_H
