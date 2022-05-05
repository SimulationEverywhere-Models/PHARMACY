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
*  DATE: 25/10/2007
*
*******************************************************************/

/** include files **/
#include "checkin.h"  // class Checkin
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Checkin
********************************************************************/
Checkin::Checkin( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, done( addInputPort( "done" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Checkin::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Checkin::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		elements.push_back( msg.value() ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}

	if(( msg.port() == done ) && ( elements.size()>1 ))
	{
		elements.pop_front() ;
		if( !elements.empty() )
			holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Checkin::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Checkin::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
