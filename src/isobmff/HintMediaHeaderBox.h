/*
 * HintMediaBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_HINTMEDIAHEADERBOX_H_
#define ISOBMFF_HINTMEDIAHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class HintMediaHeaderBox : public FullBox {
public:
	HintMediaHeaderBox();
	virtual ~HintMediaHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint16_t GetMaxPduSize();
	uint16_t GetAvgPduSize();
	uint32_t GetMaxBitrate();
	uint32_t GetAvgBitrate();
	uint32_t GetReserved0();

private:
	uint16_t m_max_pdu_size;
	uint16_t m_avg_pdu_size;
	uint32_t m_max_bitrate;
	uint32_t m_avg_bitrate;
	uint32_t m_reserved_0;
};

#endif /* ISOBMFF_HINTMEDIAHEADERBOX_H_ */
