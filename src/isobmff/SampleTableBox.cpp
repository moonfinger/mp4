/*
 * SampleTableBox.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#include "SampleTableBox.h"

SampleTableBox::SampleTableBox() {
	// TODO Auto-generated constructor stub
	m_stsd = NULL;
	m_parent = NULL;
}

SampleTableBox::~SampleTableBox() {
	// TODO Auto-generated destructor stub
	if(m_stsd) delete m_stsd;
}

