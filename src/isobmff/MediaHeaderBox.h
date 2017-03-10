/*
 * MediaHeaderBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_MEDIAHEADERBOX_H_
#define ISOBMFF_MEDIAHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class MediaHeaderBox : public FullBox {
public:
	MediaHeaderBox();
	virtual ~MediaHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint64_t GetCreationTime();
	uint64_t GetModificationTime();
	uint32_t GetTimescale();
	uint64_t GetDuration();
	uint16_t GetLanguage();
	uint16_t GetPreDefined();

private:
	uint64_t m_creation_time;
	uint64_t m_modification_time;
	uint32_t m_timescale;
	uint64_t m_duration;
	uint16_t m_language;
	uint16_t m_pre_defined;
};

#endif /* ISOBMFF_MEDIAHEADERBOX_H_ */
