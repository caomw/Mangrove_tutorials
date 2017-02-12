/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-006' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial006.cpp - the 'Tutorial Example-006' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include <iostream>
#include <cstdlib>
#include "Mangrove_Miscellanea.h"
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial006</i> program.
/**
 * \file Mangrove_tutorial006.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial006</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	double d,d1,d2;
	MANGROVE_BYTES_SEQUENCE ss,sss;
	unsigned int n;

	/* Now, we validate the binary words (see the 'MANGROVE_BYTE' and the 'MANGROVE_BYTES_SEQUENCE' aliases), plus other functions in the 'Mangrove_Miscellanea.h' file. */
	Mangrove_exportCopyrightDisclaimer ("Mangrove_tutorial006");
	d=22.55;
	d1=d;
	d2=0.0;
	cout<<"\tFirst, we consider the value 'd'="<<d<<" of the 'double' C++ built-in type. Then, the value 'd' is converted implicitly into the corresponding binary word 'w', defined as follows:"<<endl;
	Mangrove_debug((MANGROVE_BYTES_SEQUENCE)&d,sizeof(d));
	cout<<endl;
	cout.flush();
	Mangrove_reverseOrder( (MANGROVE_BYTES_SEQUENCE)&d1,sizeof(d1));
	cout<<endl<<"\tThe C++ 'double' value 'd1', corresponding to the reversed bytes sequence 's' of the binary word 'w', is "<<d1<<endl;
	Mangrove_reverseOrder( (MANGROVE_BYTES_SEQUENCE)&d1,sizeof(d1));
	cout<<"\tThe new C++ 'double' value 'd1' after performing another reverse operation on the bytes sequence 's' is "<<d1<<endl;
	if(d==d1) cout<<"\tAll reverse operations are correct, and the result is equal to the C++ 'double' value 'd'="<<d<<endl<<endl;
	else cout<<"\tSomething went wrong while performing the reverse operations. The result is different from the C++ 'double' value 'd'="<<d<<endl<<endl;
	cout.flush();
	ss=nullptr;
	cout<<"\tConverting explicitly the C++ 'double' value 'd1'="<<d1<<" as the corresponding binary word 's' ... ";
	Mangrove_toBytesSequence(d1,&ss,n);
	cout<<"ok"<<endl;
	cout<<"\tThe corresponding binary word 's' with "<<n<<" bytes is the following:"<<endl;
	Mangrove_debug(ss,n);
	cout<<endl<<endl<<"\tConverting explicitly the binary word 's' as the new C++ 'double' value 'd2' ... ";
	cout.flush();
	Mangrove_toTemplateValue(ss,sizeof(d2),d2);
	cout<<"ok"<<endl;
	if(d==d2) cout<<"\tThe conversion operation is correct, and the result is 'd2'="<<d2<<" (equal to the C++ 'double' value 'd'="<<d<<")"<<endl<<endl;
	else cout<<"\tSomething went wrong while performing the conversion operation. The result is different from the C++ 'double' value'd'="<<d<<endl<<endl;
	cout.flush();
	cout<<"\tThe current content of the binary word 's' with "<<n<<" bytes is the following:"<<endl;
	Mangrove_debug(ss,n);
	cout<<endl<<endl<<"\tCreating a new copy of the binary word 's' (with "<<n<<" bytes) ... ";
	cout.flush();
	sss=nullptr;
	Mangrove_copyBytesSequence(ss,sizeof(d),&sss);
	cout<<"ok"<<endl<<"\tThe new copy of the binary word 's' (with "<<n<<" bytes) is the following:"<<endl;
	Mangrove_debug(sss,sizeof(d));
	cout<<endl<<endl;
	cout.flush();
	cout<<"\tDeallocating the auxiliary variables, used in this tutorial ... ";
	cout.flush();
	if(sss!=nullptr) delete sss;
	sss=nullptr;
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
