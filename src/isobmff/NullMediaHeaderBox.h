/*
 * NullMediaHeaderBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_NULLMEDIAHEADERBOX_H_
#define ISOBMFF_NULLMEDIAHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class NullMediaHeaderBox : public FullBox {
public:
	NullMediaHeaderBox();
	virtual ~NullMediaHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);
};

#endif /* ISOBMFF_NULLMEDIAHEADERBOX_H_ */
