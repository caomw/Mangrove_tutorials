/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-026' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial026.cpp - the 'Tutorial Example-026' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial026</i> program.
/**
 * \file Mangrove_tutorial026.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial026</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::MANGROVE_ENTITY_ID, mangrove_tds::MANGROVE_ENTITY_DIM, checkPointerValidity(), mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_RawFace, 
 * mangrove_tds::Mangrove_AuxiliaryRawFace, mangrove_tds::Mangrove_SerializableObject
 */
int main(void)
{
	ofstream out;
	ifstream in;
	Mangrove_RawFace r1,r1a;

	/* First, we export the header for the tutorial. Then, we validate the 'raw faces'. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial025");
	cout<<"\tCreating a not initialized 'raw face' 'r1' ... ";
	cout<<"ok"<<endl;
	if(r1.isSerializable()==true) cout<<"\tA generic 'raw face' is 'serializable' (including the 'raw face' 'r1')."<<endl;
	else cout<<"\tA generic 'raw face' is not 'serializable' (including the 'raw face' 'r1')."<<endl;
	cout<<"\tThe 'debug' representation of the 'raw face' 'r1' is:"<<endl;
	cout.flush();
	Mangrove_debug(&r1);
	cout<<endl<<"\tUpdating the content of the 'raw face' 'r1' ... ";
	r1.getReverseIndex()=2;
	r1.getIndex()=3;
	r1.getVertices()={1,2,3};
	r1.updateHashingValue();
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation of the updated 'raw face' 'r1' is:"<<endl;
	cout.flush();
	r1.debug();
	cout<<endl<<"\tExporting the 'compact' representation of the 'raw face' 'f1' on the 'raw_face.txt' file ... ";
	out.open("raw_face.txt");
	Mangrove_export(&r1,out);
	out.close();
	cout<<"ok"<<endl<<"\tReconstructing a new 'raw face' by reading and parsing the 'raw face' 'f1' from the 'raw_face.txt' file .. ";
	in.open("raw_face.txt");
	Mangrove_reconstruct(&r1a,in);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation of the reconstructed 'raw face' is:"<<endl;
	cout.flush();
	r1a.debug();
	cout<<endl;
	if(Mangrove_same_faces(r1,r1a)) cout<<"\tThe reconstructed 'raw face' is 'the same as' the existing 'raw face' 'r1', and their indexeded representation coincide position by position."<<endl;
	else cout<<"\tThe reconstructed 'raw face' is not 'the same as' the existing 'raw face' 'r1', and their indexeded representation do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r1,r1a)) cout<<"\tThe reconstructed 'raw face' is 'the same as' the existing 'raw face' 'r1', and their hashing values coincide."<<endl;
	else cout<<"\tThe reconstructed 'raw face' is not 'the same as' the existing 'raw face' 'r1', and their hashing values do not coincide."<<endl;
	cout<<endl;
	cout<<"\tRemoving the 'raw_face.txt' file ... ";
	Mangrove_removeFile("raw_face.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Creating a copy 'r2' of the 'raw face' 'r1'. */
	cout<<"\tCreating a copy 'r2' of the 'raw face' 'r1' ... ";
	Mangrove_RawFace *r2=nullptr;
	r2=new Mangrove_RawFace(r1);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation of the 'raw face' 'r2' is:"<<endl;
	cout.flush();
	Mangrove_debug(r2);
	cout<<endl;
	if(Mangrove_same_faces(r1,*r2)) cout<<"\tThe 'raw faces' 'r1' and 'r2' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'raw faces' 'r1' and 'r2' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r1,*r2)) cout<<"\tThe 'raw faces' 'r1' and 'r2' are 'the same', and their hashing values coincide."<<endl<<endl;
	else cout<<"\tThe 'raw faces' 'r1' and 'r2' are not 'the same', and their hashing values do not coincide."<<endl<<endl;
	cout.flush();
	
	/* Creating a copy 'r3' of the 'raw face' 'r2'. */
	cout<<"\tCreating a copy 'r3' of the 'raw face' 'r2' ... ";
	Mangrove_RawFace r3(r2);
	cout<<"ok"<<endl;
	if(Mangrove_same_faces(*r2,r3)) cout<<"\tThe 'raw faces' 'r2' and 'r3' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'raw faces' 'r2' and 'r3' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(*r2,r3)) cout<<"\tThe 'raw faces' 'r2' and 'r3' are 'the same', and their hashing values coincide."<<endl<<endl;
	else cout<<"\tThe 'raw faces' 'r2' and 'r3' are not 'the same', and their hashing values do not coincide."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Creating another 'raw face' 'r4'. */
	cout<<"\tCreating another 'raw face' 'r4' with the same indexed representation of the 'raw face' 'r3' (but without updating the hashing value) ... ";
	Mangrove_RawFace r4;
	for(auto it : r3.getCVertices() ) r4.getVertices().push_back(it);
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r4.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r4.getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r4.getHashingValue()<<endl<<endl;
	if(Mangrove_same_faces(r4,r3)) cout<<"\tThe 'raw faces' 'r3' and 'r4' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'raw faces' 'r3' and 'r4' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r4,r3)) cout<<"\tThe 'raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide."<<endl;
	else cout<<"\tThe 'raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide."<<endl;
	if(Mangrove_compare_faces(r4,r3)) cout<<"\tThe 'raw face' 'r4' is 'strictly less than' the 'raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	else cout<<"\tThe 'raw face' 'r4' is not 'strictly less than' the 'raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'raw face' 'r4' is 'strictly less than' the 'raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	else cout<<"\tThe 'raw face' 'r4' is not 'strictly less than' the 'raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Modifying the 'raw face' 'r4' in order to validate the comparison functions! */
	cout<<"\tUpdating the indexed representation of the 'raw face' 'r4' and its hashing value ... ";
	r4.getVertices()={1,2,4};
	r4.updateHashingValue();
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r4.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r4.getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r4.getHashingValue()<<endl<<endl;
	cout<<"\tRetrieving the 'indexed representation' of the 'raw face' 'r3': ";
	if(r3.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r3.getCVertices());
	cout<<"\tRetrieving the hashing value of the 'raw face' 'r3': "<<r3.getHashingValue()<<endl<<endl;
	cout.flush();
	if(Mangrove_same_faces(r4,r3)) cout<<"\tThe 'raw faces' 'r3' and 'r4' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'raw faces' 'r3' and 'r4' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r4,r3)) cout<<"\tThe 'raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide."<<endl;
	else cout<<"\tThe 'raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide."<<endl;
	if(Mangrove_compare_faces(r4,r3)) cout<<"\tThe 'raw face' 'r4' is 'strictly less than' the 'raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	else cout<<"\tThe 'raw face' 'r4' is not 'strictly less than' the 'raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'raw face' 'r4' is 'strictly less than' the 'raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	else cout<<"\tThe 'raw face' 'r4' is not 'strictly less than' the 'raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	cout.flush();
	
	/* Deallocating all 'raw faces'. */
	cout<<"\tDeallocating all 'raw faces' in this test ... ";
	cout.flush();
	r1.clear();
	r1a.clear();
	if(r2!=nullptr) delete r2;
	r2=nullptr;
	r3.clear();
	r4.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
