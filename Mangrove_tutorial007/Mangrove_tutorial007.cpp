/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-007' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial007.cpp - the 'Tutorial Example-007' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Mangrove_IO.h"
#include "Mangrove_Miscellanea.h"
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial007</i> program.
/**
 * \file Mangrove_tutorial007.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial007'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::MANGROVE_DATA_ENCODING_TYPE, mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_exportChar(), mangrove_tds::Mangrove_exportUchar(), mangrove_tds::Mangrove_exportShort(), mangrove_tds::Mangrove_exportUshort(), 
 * mangrove_tds::Mangrove_exportInt(), mangrove_tds::Mangrove_exportUint(), mangrove_tds::Mangrove_exportLong(), mangrove_tds::Mangrove_exportUlong(), mangrove_tds::Mangrove_exportFloat(), mangrove_tds::Mangrove_exportDouble(), mangrove_tds::Mangrove_readChar(),
 * mangrove_tds::Mangrove_readUchar(), mangrove_tds::Mangrove_readShort(), mangrove_tds::Mangrove_readUshort(), mangrove_tds::Mangrove_readInt(), mangrove_tds::Mangrove_readUint(), mangrove_tds::Mangrove_readLong(), mangrove_tds::Mangrove_readUlong(),
 * mangrove_tds::Mangrove_readFloat(), mangrove_tds::Mangrove_readDouble(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile()
 */
int main(void)
{
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutorial007' tutorial, where the serialization operations, involving several values, that are described by the C++ built-in types (satisfying the ASCII encoding), are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial007' Tutorial");
	cout.flush();
	
	/* TASK #1 - exporting several values, described by the C++ built-in types, on a specific file  (satisfying the ASCII encoding). */
	cout<<"\tExporting several values, described the C++ built-in types, on the 'ascii_values.txt' file (satisfying the ASCII encoding):"<<endl<<endl;
	cout.flush();
	out.open("ascii_values.txt");
	
	/* TASK #1.1 - exporting a value, described by the 'character (char)' C++ built-in type. */
	char c=('a');
	cout<<"\t\tExporting the 'character (char)' C++ built-in value 'c'='"<<c<<"' ... ";
	Mangrove_exportChar(c,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.2 - exporting a value, described by the 'unsigned character (uchar)' C++ built-in type. */
	uchar uc=('#');
	cout<<"\t\tExporting the 'unsigned character (uchar)' C++ built-in value 'uc'='"<<uc<<"' ... ";
	Mangrove_exportUchar(uc,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.3 - exporting a value, described by the 'short integer (short)' C++ built-in type. */
	short s=-125;
	cout<<"\t\tExporting the 'short integer (short)' value 's'="<<s<<" ... ";
	Mangrove_exportShort(s,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.4 - exporting a value, described by the 'unsigned short integer (ushort)' C++ built-in type. */
	ushort us=1024;
	cout<<"\t\tExporting the 'unsigned short integer (ushort)' value 'us'="<<us<<" ... ";
	Mangrove_exportUshort(us,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.5 - exporting a value, described by the 'integer (int)' C++ built-in type. */
	int i=-36245;
	cout<<"\t\tExporting the 'integer (int)' value 'i'="<<i<<" ... ";
	Mangrove_exportInt(i,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.6 - exporting a value, described by the 'unsigned integer (uint)' C++ built-in type. */
	uint ui=86245;
	cout<<"\t\tExporting the 'unsigned integer (uint)' value 'ui'="<<ui<<" ... ";
	Mangrove_exportUint(ui,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.7 - exporting a value, described by the 'long integer (long)' C++ built-in type. */
	long l=-1234567;
	cout<<"\t\tExporting the 'long integer (long)' value 'l'="<<l<<" ... ";
	Mangrove_exportLong(l,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.8 - exporting a value, described by the 'unsigned long integer (ulong)' C++ built-in type. */
	ulong ul=3423453;
	cout<<"\t\tExporting the 'unsigned long integer (ulong)' value 'ul'="<<ul<<" ... ";
	Mangrove_exportUlong(ul,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.9 - exporting a value, described by the 'single precision floating-point (float)' C++ built-in type. */
	float f=-1936.27;
	cout<<"\t\tExporting the 'single precision floating-point (float)' value 'f'="<<f<<" ... ";
	Mangrove_exportFloat(f,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* TASK #1.10 - exporting a value, described by the 'double precision floating-point (double)' C++ built-in type. */
	double d=-1E+32;
	cout<<"\t\tExporting the 'double precision floating-point (double)' value 'd'="<<d<<" ... ";
	Mangrove_exportDouble(d,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl<<endl;
	cout.flush();
	out.close();
	
	/* TASK #2 - reading and parsing several values, described by the C++ built-in types, from a specific file  (satisfying the ASCII encoding). */
	cout<<"\tReading and parsing several values, described the C++ built-in types, from the 'ascii_values.txt' file (satisfying the ASCII encoding):"<<endl<<endl;
	cout.flush();
	in.open("ascii_values.txt");
	
	/* TASK 2.1 - reading and parsing a new value 'c1', described by the 'character (char)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'c1', described by the 'character (char)' C++ built-in type ... ";
	char c1=Mangrove_readChar(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'c1', described by the 'character (char)' C++ built-in type, is '"<<(char)c1<<"'."<<endl;
	if(c==c1) cout<<"\t\tThe conversion process is correct, and the 'character (char)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'character (char)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.2 - reading and parsing a new value 'uc1', described by the 'unsigned character (uchar)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'uc1', described by the 'unsigned character (uchar)' C++ built-in type ... ";
	uchar uc1=Mangrove_readUchar(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'uc1', described by the 'unsigned char (uchar)' C++ built-in type, is '"<<(uchar)uc1<<"'."<<endl;
	if(uc==uc1) cout<<"\t\tThe conversion process is correct, and the 'unsigned character (uchar)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'unsigned character (uchar)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.3 - reading and parsing a new value 's1', described by the 'short integer (short)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 's1', described by the 'short integer (short)' C++ built-in type ... ";
	short s1=Mangrove_readShort(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 's1', described by the 'short integer (short)' C++ built-in type, is "<<s1<<"."<<endl;
	if(s==s1) cout<<"\t\tThe conversion process is correct, and the 'short integer (short)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'short integer (short)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.4 - reading and parsing a new value 'us1', described by the 'unsigned short integer (ushort)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'us1', described by the 'unsigned short integer (ushort)' C++ built-in type ... ";
	ushort us1=Mangrove_readUshort(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'us1', described by the 'unsigned short integer (ushort)' C++ built-in type, is "<<us1<<"."<<endl;
	if(us==us1) cout<<"\t\tThe conversion process is correct, and the 'unsigned short integer (ushort)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'unsigned short integer (ushort)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.5 - reading and parsing a new value 'i1', described by the 'integer (int)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'i1', described by the 'integer (int)' C++ built-in type ... ";
	int i1=Mangrove_readInt(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'i1', described by the 'integer (int)' C++ built-in type, is "<<i1<<"."<<endl;
	if(i==i1) cout<<"\t\tThe conversion process is correct, and the 'integer (int)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'integer (int)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.6 - reading and parsing a new value 'ui1', described by the 'unsigned integer (uint)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'ui1', described by the 'unsigned integer (uint)' C++ built-in type ... ";
	uint ui1=Mangrove_readUint(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'ui1', described by the 'unsigned integer (uint)' C++ built-in type, is "<<ui1<<"."<<endl;
	if(ui==ui1) cout<<"\t\tThe conversion process is correct, and the 'unsigned integer (uint)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'unsigned integer (uint)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.7 - reading and parsing a new value 'l1', described by the 'long integer (long)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'l1', described by the 'long integer (long)' C++ built-in type ... ";
	long l1=Mangrove_readLong(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'l1', described by the 'long integer (long)' C++ built-in type, is "<<l1<<"."<<endl;
	if(l==l1) cout<<"\t\tThe conversion process is correct, and the 'long integer (long)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'long integer (long)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.8 - reading and parsing a new value 'ul1', described by the 'unsigned long integer (ulong)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'ul1', described by the 'unsigned long integer (ulong)' C++ built-in type ... ";
	ulong ul1=Mangrove_readUlong(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'ul1', described by the 'unsigned long integer (ulong)' C++ built-in type, is "<<ul1<<"."<<endl;
	if(ul==ul1) cout<<"\t\tThe conversion process is correct, and the 'unsigned long integer (ulong)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'unsigned long integer (ulong)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.9 - reading and parsing a new value 'f1', described by the 'single precision floating-point (float)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'f1', described by the 'single precision floating-point (float)' C++ built-in type ... ";
	float f1=Mangrove_readFloat(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'f1', described by the 'single precision floating-point (float)' C++ built-in type, is "<<f1<<"."<<endl;
	if(f==f1) cout<<"\t\tThe conversion process is correct, and the 'single precision floating-point (float)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'single precision floating-point (float)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	
	/* TASK 2.10 - reading and parsing a new value 'd1', described by the 'double precision floating-point (double)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'd1', described by the 'double precision floating-point (double)' C++ built-in type ... ";
	double d1=Mangrove_readDouble(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'd1', described by the 'double precision floating-point (double)' C++ built-in type, is "<<d1<<"."<<endl;
	if(d==d1) cout<<"\t\tThe conversion process is correct, and the 'double precision floating-point (double)' C++ built-in values of interest coincide."<<endl<<endl;
	else cout<<"\t\tThe conversion process is wrong, and the 'double precision floating-point (double)' C++ built-in values of interest do not coincide."<<endl<<endl;
	cout.flush();
	in.close();
	cout<<"\tRemoving the 'ascii_values.txt' file ... ";
	Mangrove_removeFile(string("ascii_values.txt"));
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
