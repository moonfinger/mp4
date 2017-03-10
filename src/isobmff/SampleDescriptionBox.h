/*
 * SampleDescriptionBox.h
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_SAMPLEDESCRIPTIONBOX_H_
#define ISOBMFF_SAMPLEDESCRIPTIONBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class SampleDescriptionBox : public FullBox {
public:
	SampleDescriptionBox();
	virtual ~SampleDescriptionBox();
};

#endif /* ISOBMFF_SAMPLEDESCRIPTIONBOX_H_ */
