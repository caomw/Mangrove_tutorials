/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-013' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial013.cpp - the 'Tutorial Example-013' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial013'</i> program.
/**
 * \file Mangrove_tutorial013.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial013'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause();
 */
int main(void)
{
	deque<bool> d0,d1,origd;
	vector<bool> v0,v1,origv;
	list<bool> l0,l1,origl;

	/* This is the 'Mangrove_tutorial013' tutorial, where the lists, the deques, and the arrays, containing several 'boolean (bool)' C++ built-in values, are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial013' Tutorial");
	cout.flush();
	
	/* TASK #1 - validating the deques, containing several 'boolean (bool)' C++ built-in values. */
	cout<<"\tCreating the new deque 'd0' of several 'boolean (bool)' C++ built-in values ... ";
	cout.flush();
	d0={true,true,true,false,false,true,false};
	cout<<"ok"<<endl;
	origd=deque<bool>(d0);
	cout<<"\tThe new deque 'd0' contains the following "<<d0.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(d0);
	cout<<"\tToggling (negating) and overwriting the 'boolean (bool)' C++ built-in values in the deque 'd0' ... ";
	Mangrove_toggle(d0);
	cout<<"ok"<<endl;
	cout<<"\tThe new deque 'd0' contains the following "<<d0.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(d0);
	cout<<"\tToggling (negating) the 'bool' values in the deque 'd0', and saving their updated versions on the new deque 'd1' ... ";
	cout.flush();
	Mangrove_toggle(d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe new deque 'd1' contains the following "<<d1.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(d1);
	if(d1==origd) cout<<"\tThe new deque 'd1' coincides with the original version of the deque 'd0' (with respect to the '==' operator)."<<endl;
	else cout<<"\tThe new deque 'd1' does not coincide with the original version of the deque 'd0' (with respect to the '==' operator)."<<endl;
	if(Mangrove_theSame(d1,origd)==true) cout<<"\tThe new deque 'd1' coincides with the original version of the deque 'd0' (with respect to the 'Mangrove_theSame()' template function)."<<endl<<endl;
	else cout<<endl<<"\tThe new deque 'd1' does not coincide with the original version of the deque 'd0' (with respect to the 'Mangrove_theSame()' template function)."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #2 - validating the lists, containing several 'boolean (bool)' C++ built-in values. */
	cout<<"\tCreating the new list 'l0' of several 'boolean (bool)' C++ built-in values ... ";
	cout.flush();
	l0={true,true,true,false};
	cout<<"ok"<<endl;
	origl=list<bool>(l0);
	cout<<"\tThe new list 'l0' contains the following "<<l0.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(l0);
	cout<<"\tToggling (negating) and overwriting the 'boolean (bool)' C++ built-in values in the list 'l0' ... ";
	Mangrove_toggle(l0);
	cout<<"ok"<<endl;
	cout<<"\tThe new list 'l0' contains the following "<<l0.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(l0);
	cout<<"\tToggling (negating) the 'bool' values in the list 'l0', and saving their updated versions on the new list 'l1' ... ";
	cout.flush();
	Mangrove_toggle(l0,l1);
	cout<<"ok"<<endl;
	cout<<"\tThe new list 'l1' contains the following "<<l1.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(l1);
	if(l1==origl) cout<<"\tThe new list 'l1' coincides with the original version of the list 'l0' (with respect to the '==' operator)."<<endl;
	else cout<<"\tThe new list 'l1' does not coincide with the original version of the list 'l0' (with respect to the '==' operator)."<<endl;
	if(Mangrove_theSame(l1,origl)==true) cout<<"\tThe new list 'l1' coincides with the original version of the list 'l0' (with respect to the 'Mangrove_theSame()' template function)."<<endl<<endl;
	else cout<<endl<<"\tThe new list 'l1' does not coincide with the original version of the list 'l0' (with respect to the 'Mangrove_theSame()' template function)."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #3 - validating the arrays, containing several 'boolean (bool)' C++ built-in values. */
	cout<<"\tCreating the new array 'v0' of several 'boolean (bool)' C++ built-in values ... ";
	cout.flush();
	v0={true,false,true,false};
	cout<<"ok"<<endl;
	origv=vector<bool>(v0);
	cout<<"\tThe new array 'v0' contains the following "<<v0.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(v0);
	cout<<"\tToggling (negating) and overwriting the 'boolean (bool)' C++ built-in values in the array 'v0' ... ";
	Mangrove_toggle(v0);
	cout<<"ok"<<endl;
	cout<<"\tThe new array 'v0' contains the following "<<v0.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(v0);
	cout<<"\tToggling (negating) the 'bool' values in the array 'v0', and saving their updated versions on the new array 'v1' ... ";
	cout.flush();
	Mangrove_toggle(v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe new array 'v1' contains the following "<<v1.size()<<" 'boolean (bool)' C++ built-in values: ";
	Mangrove_exportHybrid(v1);
	if(v1==origv) cout<<"\tThe new array 'v1' coincides with the original version of the array 'v0' (with respect to the '==' operator)."<<endl;
	else cout<<"\tThe new array 'v1' does not coincide with the original version of the array 'v0' (with respect to the '==' operator)."<<endl;
	if(Mangrove_theSame(v1,origv)==true) cout<<"\tThe new array 'v1' coincides with the original version of the array 'v0' (with respect to the 'Mangrove_theSame()' template function)."<<endl<<endl;
	else cout<<endl<<"\tThe new array 'v1' does not coincide with the original version of the array 'v0' (with respect to the 'Mangrove_theSame()' template function)."<<endl<<endl;
	cout.flush();
	
	/* TASK #4 - deallocating all auxiliary data structures in this tutorial. */
	cout<<"\tDeallocating all auxiliary data structures in this tutorial ... ";
	d0.clear();
	d1.clear();
	origd.clear();
	v0.clear();
	v1.clear();
	origv.clear();
	l0.clear();
	l1.clear();
	origl.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
