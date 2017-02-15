/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-007' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 
/// The <i>main function</i> for the <i>Mangrove_tutorial007</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::MANGROVE_DATA_ENCODING_TYPE, mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_exportChar(), mangrove_tds::Mangrove_exportUchar(), mangrove_tds::Mangrove_exportShort(), mangrove_tds::Mangrove_exportUshort(), 
 * mangrove_tds::Mangrove_exportInt(), mangrove_tds::Mangrove_exportUint(), mangrove_tds::Mangrove_exportLong(), mangrove_tds::Mangrove_exportUlong(), mangrove_tds::Mangrove_exportFloat(), mangrove_tds::Mangrove_exportDouble(), mangrove_tds::Mangrove_readChar(),
 * mangrove_tds::Mangrove_readUchar(), mangrove_tds::Mangrove_readShort(), mangrove_tds::Mangrove_readUshort(), mangrove_tds::Mangrove_readInt(), mangrove_tds::Mangrove_readUint(), mangrove_tds::Mangrove_readLong(), mangrove_tds::Mangrove_readUlong(),
 * mangrove_tds::Mangrove_readFloat(), mangrove_tds::Mangrove_readDouble()
 */
int main(void)
{
	char c,c1;
	unsigned char uc,uc1;
	short s,s1;
	unsigned short us,us1;
	int i,i1;
	unsigned int ui,ui1;
	long l,l1;
	unsigned long ul,ul1;
	float f,f1;
	double d,d1;
	ofstream out;
	ifstream in;
	
	/* First, we export the copyright disclaimer. Then, we validate the serialization operations, involving the C++ built-in types (satisfying the ASCII encoding). */
	Mangrove_exportCopyrightDisclaimer ("Mangrove_tutorial007");
	cout<<"\tExporting several values of the C++ built-in types on the 'ascii_values.txt' file (satisfying the ASCII encoding)"<<endl<<endl;
	cout.flush();
	out.open("ascii_values.txt");
	
	/* Now, we start from a value of the 'char' C++ built-in type. */
	c=('a');
	cout<<"\t\tExporting the C++ 'char' value 'c'='"<<c<<"' ... ";
	Mangrove_exportChar(c,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'unsigned char (uchar)' C++ built-in type. */
	uc=('#');
	cout<<"\t\tExporting the C++ 'unsigned char (uchar)' value 'uc'='"<<uc<<"' ... ";
	Mangrove_exportUchar(uc,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'short' C++ built-in type. */
	s=-125;
	cout<<"\t\tExporting the C++ 'short' value 's'="<<s<<" ... ";
	Mangrove_exportShort(s,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'unsigned short (ushort)' C++ built-in type. */
	us=1024;
	cout<<"\t\tExporting the C++ 'unsigned short (ushort)' value 'us'="<<us<<" ... ";
	Mangrove_exportUshort(us,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'int' C++ built-in type. */
	i=-245;
	cout<<"\t\tExporting the C++ 'int' value 'i'="<<i<<" ... ";
	Mangrove_exportInt(i,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'unsigned int (uint)' C++ built-in type. */
	ui=3056;
	cout<<"\t\tExporting the C++ 'unsigned int (uint)' value 'ui'="<<ui<<" ... ";
	Mangrove_exportUint(ui,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'long' C++ built-in type. */
	l=-2455;
	cout<<"\t\tExporting the C++ 'long' value 'l'="<<l<<" ... ";
	Mangrove_exportLong(l,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'unsigned long (ulong)' C++ built-in type. */
	ul=342345;
	cout<<"\t\tExporting the C++ 'unsigned long (ulong)' value 'ul'="<<ul<<" ... ";
	Mangrove_exportUlong(ul,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'float' C++ built-in type. */
	f=-1936.27;
	cout<<"\t\tExporting the C++ 'float' value 'f'="<<f<<" ... ";
	Mangrove_exportFloat(f,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl;
	cout.flush();
	
	/* Now, we export a value of the 'double' C++ built-in type. */
	d=-1e+32;
	cout<<"\t\tExporting the C++ 'double' value 'd'="<<d<<" ... ";
	Mangrove_exportDouble(d,MANGROVE_FORMAT_ASCII,out);
	cout<<"ok"<<endl<<endl;
	cout.flush();
	out.close();
	c1=0;
	uc1=0;
	s1=0;
	us1=0;
	i1=0;
	ui1=0;
	l1=0;
	ul1=0;
	f1=0;
	d1=0;
	
	/* Reading and parsing the values of the C++ built-in types (just exported) from the 'ascii_values.txt' file (satisfying the ASCII encoding). */
	cout<<"\tReading and parsing the values of the C++ built-in types (just exported) from the 'ascii_values.txt' file (satisfying the ASCII encoding)"<<endl<<endl;
	cout.flush();
	in.open("ascii_values.txt");
	
	/* Now, we read and parse a new value of the 'char' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'c1' of the 'char' C++ built-in type ... ";
	c1=Mangrove_readChar(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'c1' of the 'char' C++ built-in type is 'c1'='"<<(char)c1<<"'"<<endl;
	if(c==c1) cout<<"\t\tThis operation is correct, since the new C++ 'char' value 'c1' coincides with the original C++ 'char' value 'c'='"<<(char)c<<"'"<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'char' value 'c1' does not coincide with the original C++ 'char' value 'c'='"<<(char)c<<"'"<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'unsigned char (uchar)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'uc1' of the 'unsigned char (uchar)' C++ built-in type ... ";
	uc1=Mangrove_readUchar(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'uc1' of the 'unsigned char (uchar)' C++ built-in type is 'uc1'='"<<(unsigned char)uc1<<"'"<<endl;
	if(uc==uc1) cout<<"\t\tThis operation is correct, since the new C++ 'unsigned char (uchar)' value 'uc1' coincides with the original C++ 'unsigned char (uchar)' value 'uc'='"<<(unsigned char)uc<<"'"<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'unsigned char (uchar)' value 'uc1' does not coincide with the original C++ 'unsigned char (uchar)' value 'uc'='"<<(unsigned char)uc<<"'"<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'short' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 's1' of the 'short' C++ built-in type ... ";
	s1=Mangrove_readShort(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 's1' of the 'short' C++ built-in type is 's1'="<<s1<<endl;
	if(s==s1) cout<<"\t\tThis operation is correct, since the new C++ 'short' value 's1' coincides with the original C++ 'short' value 's'="<<s<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'short' value 's1' does not coincide with the original C++ 'short' value 's'="<<s<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'unsigned short (ushort)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'us1' of the 'unsigned short (ushort)' C++ built-in type ... ";
	us1=Mangrove_readUshort(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'us1' of the 'unsigned short (ushort)' C++ built-in type is 'us1'="<<us1<<endl;
	if(us==us1) cout<<"\t\tThis operation is correct, since the new C++ 'unsigned short (ushort)' value 'us1' coincides with the original C++ 'unsigned short (ushort)' value 'us'="<<us<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'unsigned short (ushort)' value 'us1' does not coincide with the original C++ 'unsigned short (ushort)' value 'us'="<<us<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'int' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'i1' of the 'int' C++ built-in type ... ";
	i1=Mangrove_readInt(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'i1' of the 'int' C++ built-in type is 'i1'="<<i1<<endl;
	if(i==i1) cout<<"\t\tThis operation is correct, since the new C++ 'int' value 'i1' coincides with the original C++ 'int' value 'i'="<<i<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'int' value 'i1' does not coincide with the original C++ 'int' value 'i'="<<i<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'unsigned int (uint)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'ui1' of the 'unsigned int (uint)' C++ built-in type ... ";
	ui1=Mangrove_readUint(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'ui1' of the 'unsigned int (uint)' C++ built-in type is 'ui1'="<<ui1<<endl;
	if(ui==ui1) cout<<"\t\tThis operation is correct, since the new C++ 'unsigned int (uint)' value 'ui1' coincides with the original C++ 'unsigned int (uint)' value 'ui'="<<ui<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'unsigned int (uint)' value 'ui1' does not coincide with the original C++ 'unsigned int (uint)' value 'ui'="<<ui<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'long' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'l1' of the 'long' C++ built-in type ... ";
	l1=Mangrove_readLong(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'l1' of the 'long' C++ built-in type is 'l1'="<<l1<<endl;
	if(l==l1) cout<<"\t\tThis operation is correct, since the new C++ 'long' value 'l1' coincides with the original C++ 'long' value 'l'="<<l<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'long' value 'l1' does not coincide with the original C++ 'long' value 'l'="<<l<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'unsigned long (ulong)' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'ul1' of the 'unsigned long (ulong)' C++ built-in type ... ";
	ul1=Mangrove_readUlong(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'ul1' of the 'unsigned long (ulong)' C++ built-in type is 'ul1'="<<ul1<<endl;
	if(ul==ul1) cout<<"\t\tThis operation is correct, since the new C++ 'unsigned long (ulong)' value 'ul1' coincides with the original C++ 'unsigned long (ulong)' value 'ul'="<<ul<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'unsigned long (ulong)' value 'ul1' does not coincide with the original C++ 'unsigned long (ulong)' value 'ul'="<<ul<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'float' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'f1' of the 'float' C++ built-in type ... ";
	f1=Mangrove_readFloat(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'f1' of the 'float' C++ built-in type is 'f1'="<<f1<<endl;
	if(f==f1) cout<<"\t\tThis operation is correct, since the new C++ 'float' value 'f1' coincides with the original C++ 'float' value 'f'="<<f<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'float' value 'f1' does not coincide with the original C++ 'float' value 'f'="<<f<<endl<<endl;
	cout.flush();
	
	/* Now, we read and parse a new value of the 'double' C++ built-in type. */
	cout<<"\t\tReading and parsing a new value 'd1' of the 'double' C++ built-in type ... ";
	d1=Mangrove_readDouble(MANGROVE_FORMAT_ASCII,in);
	cout<<"ok"<<endl;
	cout<<"\t\tThe new value 'd1' of the 'double' C++ built-in type is 'd1'="<<d1<<endl;
	if(d==d1) cout<<"\t\tThis operation is correct, since the new C++ 'double' value 'd1' coincides with the original C++ 'double' value 'd'="<<d<<endl<<endl;
	else cout<<"\t\tThis operation is wrong, since the new C++ 'double' value 'd1' does not coincide with the original C++ 'double' value 'd'="<<d<<endl<<endl;
	cout.flush();
	in.close();
	cout<<"\tRemoving the 'ascii_values.txt' file ... ";
	Mangrove_removeFile("ascii_values.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
