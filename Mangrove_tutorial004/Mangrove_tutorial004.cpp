/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-004' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial004.cpp - the 'Tutorial Example-004' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include <iostream>
#include <cstdlib>
#include "Mangrove_IO.h"
#include "Mangrove_Miscellanea.h"
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial004'</i> program.
/**
 * \file Mangrove_tutorial004.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial004'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_char2string(), mangrove_tds::Mangrove_string2char(), mangrove_tds::Mangrove_uchar2string(), mangrove_tds::Mangrove_string2uchar(), mangrove_tds::Mangrove_short2string(), 
 * mangrove_tds::Mangrove_string2short(), mangrove_tds::Mangrove_ushort2string(), mangrove_tds::Mangrove_string2ushort(), mangrove_tds::Mangrove_int2string(), mangrove_tds::Mangrove_string2int(), mangrove_tds::Mangrove_uint2string(), 
 * mangrove_tds::Mangrove_string2uint(), mangrove_tds::Mangrove_long2string(), mangrove_tds::Mangrove_string2long(), mangrove_tds::Mangrove_ulong2string(), mangrove_tds::Mangrove_string2ulong(), mangrove_tds::Mangrove_float2string(), 
 * mangrove_tds::Mangrove_string2float(), mangrove_tds::Mangrove_double2string(), mangrove_tds::Mangrove_string2double() 
 */
int main(void)
{
	string str;

	/* This is the 'Mangrove_tutorial004' tutorial, where the mutual conversions between the strings and the values, described by several C++ built-in types, are validated (ASCII format). */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial004' Tutorial");
	cout.flush();
	
	/* TASK #1 - validating the mutual conversion between a string and a value, described by the C++ 'character (char)' built-in type. */
	str.clear();
	char c=('a');
	cout<<"\tConverting the 'character (char)' C++ built-in value '"<<(int)c<<"' ("<<c<<") as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_char2string(c,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'character (char)' C++ built-in value (satisfying the ASCII encoding) ... ";
	char c1=Mangrove_string2char(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'character (char)' C++ built-in value is '"<<(int)c1<<"' ("<<c1<<")."<<endl;
	if(c==c1) cout<<"\tThe conversion process is correct, and the 'character (char)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'character (char)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - validating the mutual conversion between a string and a value, described by the C++ 'unsigned character (uchar)' built-in type. */
	uchar uc=('#');
	str.clear();
	cout<<"\tConverting the 'unsigned char (uchar)' C++ built-in value '"<<(uint)uc<<"' ("<<uc<<") as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_uchar2string(uc,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'unsigned char (uchar)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	uchar uc1=Mangrove_string2uchar(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'unsigned char (uchar)' C++ built-in value is '"<<(uint)uc1<<"' ("<<uc1<<")."<<endl;
	if(uc==uc1) cout<<"\tThe conversion process is correct, and the 'unsigned char (uchar)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'unsigned char (uchar)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #3 - validating the mutual conversion between a string and a value, described by the C++ 'short integer (short)' built-in type. */
	str.clear();
	short s=-125;
	cout<<"\tConverting the 'short integer (short)' C++ built-in value "<<s<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_short2string(s,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'short integer (short)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	short s1=Mangrove_string2short(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'short integer (short)' C++ built-in value is "<<s1<<"."<<endl;
	if(s==s1) cout<<"\tThe conversion process is correct, and the 'short integer (short)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'short integer (short)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #4 - validating the mutual conversion between a string and a value, described by the C++ 'unsigned short integer (ushort)' built-in type. */
	str.clear();
	ushort us=1024;
	cout<<"\tConverting the 'unsigned short integer (ushort)' C++ built-in value "<<us<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_ushort2string(us,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'unsigned short integer (ushort)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	ushort us1=Mangrove_string2ushort(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'unsigned short integer (ushort)' C++ built-in value is "<<us1<<"."<<endl;
	if(us==us1) cout<<"\tThe conversion process is correct, and the 'unsigned short integer (ushort)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'unsigned short integer (ushort)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #5 - validating the mutual conversion between a string and a value, described by the C++ 'integer (int)' built-in type. */
	str.clear();
	int i=-36245;
	cout<<"\tConverting the 'integer (int)' C++ built-in value "<<i<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_int2string(i,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'integer (int)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	int i1=Mangrove_string2int(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'integer (int)' C++ built-in value is "<<i1<<"."<<endl;
	if(i==i1) cout<<"\tThe conversion process is correct, and the 'integer (int)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'integer (int)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #6 - validating the mutual conversion between a string and a value, described by the C++ 'unsigned integer (uint)' built-in type. */
	str.clear();
	uint ui=86245;
	cout<<"\tConverting the 'unsigned integer (uint)' C++ built-in value "<<ui<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_uint2string(ui,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'unsigned integer (uint)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	uint ui1=Mangrove_string2uint(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'unsigned integer (uint)' C++ built-in value is "<<ui1<<"."<<endl;
	if(ui==ui1) cout<<"\tThe conversion process is correct, and the 'unsigned integer (uint)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'unsigned integer (uint)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #7 - validating the mutual conversion between a string and a value, described by the C++ 'long integer (long)' built-in type. */
	str.clear();
	long l=-1234567;
	cout<<"\tConverting the 'long integer (long)' C++ built-in value "<<l<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_long2string(l,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'long integer (long)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	long l1=Mangrove_string2long(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'long integer (long)' C++ built-in value is "<<l1<<"."<<endl;
	if(l==l1) cout<<"\tThe conversion process is correct, and the 'long integer (long)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'long integer (long)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #8 - validating the mutual conversion between a string and a value, described by the C++ 'unsigned long integer (ulong)' built-in type. */
	str.clear();
	ulong ul=3423453;
	cout<<"\tConverting the 'unsigned long integer (ulong)' C++ built-in value "<<ul<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_ulong2string(ul,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'unsigned long integer (ulong)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	ulong ul1=Mangrove_string2ulong(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'unsigned long integer (ulong)' C++ built-in value is "<<ul1<<"."<<endl;
	if(ul==ul1) cout<<"\tThe conversion process is correct, and the 'unsigned long integer (ulong)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'unsigned long integer (ulong)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #9 - validating the mutual conversion between a string and a value, described by the C++ 'single precision floating-point (float)' built-in type. */
	str.clear();
	float f=-1936.27;
	cout<<"\tConverting the 'single precision floating-point (float)' C++ built-in value "<<f<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_float2string(f,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'single precision floating-point (float)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	float f1=Mangrove_string2float(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'single precision floating-point (float)' C++ built-in value is "<<f1<<"."<<endl;
	if(f==f1) cout<<"\tThe conversion process is correct, and the 'single precision floating-point (float)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'single precision floating-point (float)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK #10 - validating the mutual conversion between a string and a value, described by the C++ 'double precision floating-point (double)' built-in type. */
	str.clear();
	double d=-1e+32;
	cout<<"\tConverting the 'double precision floating-point (double)' C++ built-in value "<<d<<" as the corresponding string (satisfying the ASCII encoding) ... ";
	str=Mangrove_double2string(d,false);
	cout<<"ok"<<endl<<"\tThe resulting string of this conversion is '"<<str<<"'."<<endl;
	cout<<"\tRetroprojecting the existing string onto the corresponding 'double precision floating-point (double)' C++ built-in value (satisfying the ASCII encoding) ... ";
	cout.flush();
	double d1=Mangrove_string2double(str,false);
	cout<<"ok"<<endl<<"\tThe resulting 'double precision floating-point (double)' C++ built-in value is "<<d1<<"."<<endl;
	if(d==d1) cout<<"\tThe conversion process is correct, and the 'double precision floating-point (double)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\tThe conversion process is wrong, and the 'double precision floating-point (double)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
