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
*  DATE: 25/10/2007
*
*******************************************************************/

/** include files **/
#include "filling.h"  // class Filling
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Filling
********************************************************************/
Filling::Filling( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, done( addInputPort( "done" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 12, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Filling::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Filling::externalFunction( const ExternalMessage &msg )
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
Model &Filling::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Filling::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
