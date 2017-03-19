/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-024' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial024.cpp - the 'Tutorial Example-024' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/

#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial024'</i> program.
/**
 * \file Mangrove_tutorial024.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial024'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::MANGROVE_ENTITY_DIM, mangrove_tds::MANGROVE_ENTITY_ID, mangrove_tds::MANGROVE_TARTAGLIA_TRIANGLE, mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_pause(),
 * mangrove_tds::Mangrove_computeTartagliaTriangle(), mangrove_tds::Mangrove_getLocationsNumber4TartagliaTriangles(), mangrove_tds::Mangrove_destroyLocation4TartagliaTriangle(), mangrove_tds::Mangrove_destroyLocations4TartagliaTriangles(),
 * mangrove_tds::Mangrove_debugTartagliaTriangles(), mangrove_tds::Mangrove_exportTartagliaTriangles(), mangrove_tds::Mangrove_reconstructTartagliaTriangles()
 */
int main(void)
{
	MANGROVE_ENTITY_DIM d=5;
	uint pos;
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutorial024' tutorial, where the Tartaglia's Triangles and the functions for their manipulation are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial024' Tutorial");
	cout.flush();
	
	/* TASK #1 - requesting a location for computing a new Tartaglia's Triangle, and exporting its 'debug' representation on the standard output stream. */
	cout<<"\tRequesting a location in the 'tartaglia_triangles' deque for constructing the Tartaglia's Triangle of order "<<(uint)d<<" ... ";
	Mangrove_computeTartagliaTriangle(d,pos);
	cout<<"ok"<<endl;
	cout<<"\tThe location #"<<pos<<" in the 'tartaglia_triangles' deque is assigned for the new Tartaglia's Triangle."<<endl;
	Mangrove_debugTartagliaTriangle(pos);
	cout<<"\t#locations in the 'tartaglia_triangles' deque is "<<Mangrove_getLocationsNumber4TartagliaTriangles()<<"."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - validating the serialization operators/functions on the Tartaglia's Triangles. */
	cout<<"\tExporting the 'compact' representation for the location #"<<pos<<" in the 'tartaglia_triangles' deque on the 'compact_tartaglia_triangle.txt' file ... ";
	out.open("compact_tartaglia_triangle.txt");
	out<<tartaglia_triangles[pos];
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tDeallocating the location #"<<pos<<" in the 'tartaglia_triangles' deque ... ";
	Mangrove_destroyLocation4TartagliaTriangle(pos);
	cout<<"ok"<<endl;
	Mangrove_debugTartagliaTriangle(tartaglia_triangles[pos]);
	cout<<"\t#locations in the 'tartaglia_triangles' deque is "<<Mangrove_getLocationsNumber4TartagliaTriangles()<<"."<<endl;
	cout<<"\tReconstructing the location #"<<pos<<" in the 'tartaglia_triangles' deque by reading and parsing its 'compact' representation from the 'compact_tartaglia_triangle.txt' file ... ";
	in.open("compact_tartaglia_triangle.txt");
	in>>tartaglia_triangles[pos];
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debugTartagliaTriangle(pos);
	cout<<"\t#locations in the 'tartaglia_triangles' deque is "<<Mangrove_getLocationsNumber4TartagliaTriangles()<<"."<<endl<<endl;
	cout<<"\tRemoving the 'compact_tartaglia_triangle.txt' file ... ";
	Mangrove_removeFile("compact_tartaglia_triangle.txt");
	cout<<"ok"<<endl<<endl;
	Mangrove_pause();
	
	/* TASK #3 - validating other operations on the Tartaglia's Triangles. */
	for(MANGROVE_ENTITY_DIM d=2;d<5;d++)
	{
		cout<<"\tRequesting a location in the 'tartaglia_triangles' deque for constructing the Tartaglia's Triangle of order "<<(uint)d<<" ... ";
		Mangrove_computeTartagliaTriangle(d,pos);
		cout<<"ok"<<endl;
		cout<<"\tThe location #"<<pos<<" in the 'tartaglia_triangles' deque is assigned for the new Tartaglia's Triangle."<<endl<<endl;
		cout.flush();
	}
	
	/* Now, we export the 'debug' representation of all locations in the 'tartaglia_triangles' deque on the standard output stream. Then, we try to to reconstruct these locations after exporting their 'compact' representation on a given file. */
	Mangrove_debugTartagliaTriangles();
	pos=2;
	cout<<"\tDeallocating the location #"<<pos<<" in the 'tartaglia_triangles' deque ... ";
	Mangrove_destroyLocation4TartagliaTriangle(pos);
	cout<<"ok"<<endl;
	Mangrove_debugTartagliaTriangles();
	cout<<"\tExporting the 'compact' representations of all locations in the 'tartaglia_triangles' deque on the 'compact_tartaglia_triangles.txt' file ... ";
	out.open("compact_tartaglia_triangles.txt");
	Mangrove_exportTartagliaTriangles(out);
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tDeallocating all Tartaglia's Triangles in the 'tartaglia_triangles' deque ... ";
	Mangrove_destroyLocations4TartagliaTriangles();
	cout<<"ok"<<endl;
	Mangrove_debugTartagliaTriangles();
	cout<<"\tReconstructing all Tartaglia's Triangles in the 'tartaglia_triangles' deque by reading and parsing their 'compact' representations from the 'compact_tartaglia_triangles.txt' file ... ";
	in.open("compact_tartaglia_triangles.txt");
	Mangrove_reconstructTartagliaTriangles(in);
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debugTartagliaTriangles();
	cout<<"\tRemoving the 'compact_tartaglia_triangles.txt' file ... ";
	Mangrove_removeFile("compact_tartaglia_triangles.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	
	/* TASK #3 - deallocating all Tartaglia's Triangles in the system. */
	cout<<"\tDeallocating all Tartaglia's Triangles in the 'tartaglia_triangles' deque ... ";
	Mangrove_destroyLocations4TartagliaTriangles();
	cout<<"ok"<<endl;
	cout<<"\t#locations in the 'tartaglia_triangles' deque is "<<Mangrove_getLocationsNumber4TartagliaTriangles()<<"."<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;	
}
