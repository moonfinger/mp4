/*
 * NullMediaHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "NullMediaHeaderBox.h"

NullMediaHeaderBox::NullMediaHeaderBox() {
	// TODO Auto-generated constructor stub

}

NullMediaHeaderBox::~NullMediaHeaderBox() {
	// TODO Auto-generated destructor stub
}

void NullMediaHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);
}
