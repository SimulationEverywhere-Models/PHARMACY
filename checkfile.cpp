/*******************************************************************
*
*  DESCRIPTION: Atomic Model Checkfile (use a distribution)
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

/** include files **/
#include <math.h>        // fabs( ... )
#include "checkfile.h"     // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Checkfile
* Description: constructor
********************************************************************/
Checkfile::Checkfile( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, done( addInputPort( "done" ) )
{
	try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: externalFunction
* Description: the Checkfile receives one job
********************************************************************/
Model &Checkfile::externalFunction( const ExternalMessage &msg )
{
	pid = (int)msg.value();
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Checkfile::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Checkfile::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, pid );
	sendOutput( msg.time(), done, pid );
	return *this;
}

Checkfile::~Checkfile()
{
	delete dist;
}
