/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-006' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial006.cpp - the 'Tutorial Example-006' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include <iostream>
#include <cstdlib>
#include "Mangrove_Miscellanea.h"
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial006'</i> program.
/**
 * \file Mangrove_tutorial006.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial006'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see checkPointerValidity(), mangrove_tds::MANGROVE_BYTE, mangrove_tds::MANGROVE_BYTES_SEQUENCE, mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_reverseOrder(), mangrove_tds::Mangrove_toBytesSequence(), 
 * mangrove_tds::Mangrove_toTemplateValue(), mangrove_tds::Mangrove_copyBytesSequence()
 */
int main(void)
{
	/* This is the 'Mangrove_tutorial006' tutorial, where the sequence of several bytes (i.e., the binary words) are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial006' Tutorial");
	cout.flush();
	
	/* TASK #1 - converting implicitly a 'double' C++ built-in value as a binary word. */
	double d=22.55;
	double d1=d;
	double d2=0.0;
	cout<<"\tThe 'double floating-point (double)' C++ built-in value 'd'="<<d<<" is converted implicitly into the corresponding binary word 'w', defined as follows:"<<endl;
	Mangrove_debug((MANGROVE_BYTES_SEQUENCE)&d,sizeof(d));
	Mangrove_reverseOrder( (MANGROVE_BYTES_SEQUENCE)&d1,sizeof(d1));
	cout<<endl<<"\tThe 'double floating-point (double)' C++ built-in value 'd1', corresponding to the reversed bytes sequence 's' of the binary word 'w', is "<<d1<<"."<<endl;
	Mangrove_reverseOrder( (MANGROVE_BYTES_SEQUENCE)&d1,sizeof(d1));
	cout<<"\tThe new 'double floating-point (double)' C++ built-in value 'd1', obtained after performing another reverse operation on the bytes sequence 's', is "<<d1<<"."<<endl;
	if(d==d1) cout<<"\tAll reverse operations are correct, and the result is equal to the 'double floating-point (double)' C++ built-in value 'd='"<<d<<"."<<endl<<endl;
	else cout<<"\tSomething went wrong while performing the reverse operations. The result is different from the 'double floating-point (double)' C++ built-in value 'd='"<<d<<"."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - converting explicitly a 'double' C++ built-in value as a binary word. */
	MANGROVE_BYTES_SEQUENCE ss=nullptr;
	uint n;
	cout<<"\tConverting explicitly the 'double floating-point (double)' C++ built-in value 'd1'="<<d1<<" as the corresponding binary word 's' ... ";
	Mangrove_toBytesSequence(d1,&ss,n);
	cout<<"ok"<<endl;
	Mangrove_debug(ss,n);
	cout<<endl<<"\tConverting explicitly the binary word 's' as the 'double floating-point (double)' C++ built-in value 'd2' ... ";
	cout.flush();
	Mangrove_toTemplateValue(ss,sizeof(d2),d2);
	cout<<"ok"<<endl;
	if(d==d2) cout<<"\tThe conversion operation is correct, and the result is 'd2'="<<d2<<", which is equal to the 'double floating-point (double)' C++ built-in value 'd'="<<d<<"."<<endl<<endl;
	else cout<<"\tSomething went wrong while performing the conversion operation. The result is different the 'double floating-point (double)' C++ built-in value 'd'="<<d<<"."<<endl<<endl;
	cout.flush();
	
	/* TASK #4 - copying the content of an existing binary word. */
	Mangrove_debug(ss,n);
	MANGROVE_BYTES_SEQUENCE sss=nullptr;
	cout<<"\tCreating a copy of the existing binary word ... ";
	Mangrove_copyBytesSequence(ss,sizeof(d),&sss);
	cout<<"ok"<<endl;
	Mangrove_debug(sss,n);
	cout<<endl;
	cout.flush();
	
	/* TASK #5 - deallocating all binary words, used in this tutorial. */
	cout<<"\tDeallocating all binary words in this tutorial ... ";
	if(checkPointerValidity(sss)==true) delete sss;
	sss=nullptr;
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
