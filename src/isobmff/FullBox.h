/*
 * FullBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_FULLBOX_H_
#define ISOBMFF_FULLBOX_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"

using namespace std;

class FullBox : public Box {
public:
	FullBox();
	virtual ~FullBox();

protected:
	void ReadFullBoxHeader(uint8_t *buf, int32_t len);

protected:
	uint8_t  GetVersion();
	uint8_t* GetFlags();

private:
	uint8_t  m_version;
	uint8_t  m_flags[3];
};

#endif /* ISOBMFF_FULLBOX_H_ */
