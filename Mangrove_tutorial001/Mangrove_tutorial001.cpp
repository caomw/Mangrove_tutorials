/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-001' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
 *                                                                           				    
 * David Canino (canino.david@gmail.com)
 *
 * Main website for the experimental version 3.0 (GitHub) of the 'Mangrove TDS Library': http://mangrovetds.github.io
 *
 * The 'Tutorial Examples' are distributed independently on the 'Mangrove TDS Library' on the GitHub repository: 'http://github.com/davidcanino/Mangrove_tutorials'
 *
 * Last update: March 2017
 *                                                                    
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                           
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for
 * more details.
 *
 * Mangrove_tutorial001.cpp - the 'Tutorial Example-001' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_platform.h"
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial001'</i> program.
/**
 * \file Mangrove_tutorial001.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */
 
/// The <i>main function</i> for the <i>'Mangrove_tutorial001'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see checkPointerValidity(), isQTDebugModeEnabled(), isBigEndian(), isLittleEndian(), getMemoryAmount(), getCurrentMemoryAmount(), getPeakMemoryUsage(), getBoostLibrariesVersion(), mangrove_tds::Mangrove_idle(), mangrove_tds::Mangrove_exportCopyrightDisclaimer(), 
 * mangrove_tds::Mangrove_fromQt2Cplustring()
 */
int main(void)
{
	int v[5],a=-5;
	bool b;

	/* TASK #1 - Now, we validate several functions in the 'Mangrove_platform.h' and in the 'Mangrove_Miscellanea.h' file, starting from the 'Mangrove_exportCopyrightDisclaimer()' and the 'checkPointerValidity()' functions. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial001' Tutorial");
	cout<<"\tChecking the validity of the 'NULL' pointer ... ";
	b=checkPointerValidity((void*)NULL);
	cout<<"ok. ";
	if(b) cout<<"It is a 'valid' pointer."<<endl;
	else cout<<"It is not a 'valid' pointer."<<endl;
	cout<<"\tChecking the validity of the 'nullptr' pointer ... ";
	b=checkPointerValidity((void*)nullptr);
	cout<<"ok. ";
	if(b) cout<<"It is a 'valid' pointer."<<endl;
	else cout<<"It is not a 'valid' pointer."<<endl;
	cout<<"\tChecking the validity of the pointer to the array 'v' (containing 5 'int' C++ built-in values) ... ";
	b=checkPointerValidity(v);
	cout<<"ok. ";
	if(b) cout<<"It is a 'valid' pointer."<<endl<<endl;
	else cout<<"It is not a 'valid' pointer."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - Now, we validate the 'Mangrove_idle()' template function, as well as the 'Mangrove_IdleClass' template class and the 'Mangrove_IdleStruct' template struct. */
	cout<<"\tPerforming the echo-service (based on the 'mangrove_tds::Mangrove_idle()' template function) for the 'int' C++ built-in value '"<<a<<"': "<<Mangrove_idle(a)<<"."<<endl;
	cout<<"\tPerforming the echo-service (based on the 'mangrove_tds::Mangrove_IdleStruct' template struct) for the 'int' C++ built-in value '"<<a<<"': "<<Mangrove_IdleStruct<int>().idle(a)<<"."<<endl;
	cout<<"\tPerforming the echo-service (based on the 'mangrove_tds::Mangrove_IdleClass' template class) for the 'int' C++ built-in value '"<<a<<"': "<<Mangrove_IdleClass<int>().idle(a)<<"."<<endl<<endl;
	cout.flush();
	
	/* TASK #3 - Now, we validate the 'getBoostLibrariesVersion()', the 'getQTLibraryVersion()', and the 'isQTDebugModeEnabled()' functions. */
	cout<<"\tThe version of the Boost Libraries, currently in use: "<<getBoostLibrariesVersion()<<endl<<endl;
	cout<<"\tThe version of the QT Library, currently in use: "<<getQTLibraryVersion()<<endl;
	if(isQTDebugModeEnabled()) cout<<"\tThe QT library in use is currently including the 'debug' symbols."<<endl;
	else cout<<"\tThe QT library in use is not currently including the 'debug' symbols."<<endl;
	cout<<"\tThe conversion of a QT string produces the Standard C++ string: '"<<Mangrove_fromQt2Cplustring(QString("QT string"))<<"'."<<endl<<endl;
	cout.flush();
	
	/* TASK #4 - Now, we validate the 'isBigEndian()', the 'isLittleEndian()', the 'getMemoryAmount()', the 'getCurrentMemoryAmount()', and the 'getPeakMemoryUsage()' functions. */
	if(isBigEndian()) cout<<"\tThe current platform is a big-endian machine."<<endl;
	if(isLittleEndian()) cout<<"\tThe current platform is a little-endian machine."<<endl;
	cout<<"\tThe RAM amount in the current platform is "<<getMemoryAmount()<<" bytes."<<endl;
	cout<<"\tThe current program is currently using "<<getCurrentMemoryAmount()<<" bytes from the RAM."<<endl;
	cout<<"\tThe RAM peak, used by this program, is "<<getPeakMemoryUsage()<<" bytes."<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
