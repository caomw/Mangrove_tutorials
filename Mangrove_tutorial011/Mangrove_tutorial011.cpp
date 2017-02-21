/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-011' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
 *                                                                           				    
 * David Canino (canino.david@gmail.com)
 *
 * Main website for the experimental version 3.0 (GitHub) of the 'Mangrove TDS Library': http://mangrovetds.github.io
 *
 * The 'Tutorial Examples' are distributed independently on the 'Mangrove TDS Library' on the GitHub repository: 'http://github.com/davidcanino/Mangrove_tutorials'
 *
 * Last update: February 2017
 *                                                                    
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                           
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for
 * more details.
 *
 * Mangrove_tutorial011.cpp - the 'Tutorial Example-011' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial011</i> program.
/**
 * \file Mangrove_tutorial011.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */
 
/// The <i>main function</i> for the <i>Mangrove_tutorial011</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	deque<bool> d0,d1,orig;

	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, starting from the 'Mangrove_exportCopyrightDisclaimer()' function. Here, we mainly validate several functions for the deques of the 'bool' values. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial011");
	cout<<"\tCreating the new deque 'd0', formed by several 'bool' values, ... ";
	cout.flush();
	d0.push_back(true);
	d0.push_back(true);
	d0.push_back(true);
	d0.push_back(false);
	d0.push_back(false);
	d0.push_back(true);
	d0.push_back(false);
	cout<<"ok"<<endl;
	orig=deque<bool>(d0);
	cout<<"\tThe deque 'd0' contains "<<d0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) the 'bool' values in the deque 'd0' on itself ... ";
	Mangrove_toggle(d0);
	cout<<"ok"<<endl;
	cout<<"\tThe new deque 'd0' contains "<<d0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) and saving the 'bool' values in the deque 'd0' on the new deque 'd1' ... ";
	cout.flush();
	Mangrove_toggle(d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe existing deque 'd0' contains "<<d0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the existing deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout.flush();
	cout<<"\tThe new deque 'd1' contains "<<d1.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new deque 'd1' is: ";
	Mangrove_exportHybrid(d1);
	cout.flush();
	if(Mangrove_theSame(d1,orig)==true) cout<<endl<<"\tThe new deque 'd1' coincides with the original version of the deque 'd0'"<<endl<<endl;
	else cout<<endl<<"\tThe new deque 'd1' does not coincide with the original version of the deque 'd0'"<<endl<<endl;
	cout.flush();
	
	/* If we arrive here, then all is ok. */
	cout<<"\tDeallocating all deques of interest ... ";
	d0.clear();
	d1.clear();
	orig.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}