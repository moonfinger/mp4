/*
 * SoundMediaHeaderBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_SOUNDMEDIAHEADERBOX_H_
#define ISOBMFF_SOUNDMEDIAHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class SoundMediaHeaderBox : public FullBox {
public:
	SoundMediaHeaderBox();
	virtual ~SoundMediaHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	int16_t  GetBalance();
	uint16_t GetReserved0();

private:
	int16_t  m_balance;
	uint16_t m_reserved_0;
};

#endif /* ISOBMFF_SOUNDMEDIAHEADERBOX_H_ */
