/*
 * MovieHeaderBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_MOVIEHEADERBOX_H_
#define ISOBMFF_MOVIEHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"
// #include "MovieBox.h"

using namespace std;

class MovieHeaderBox : public FullBox {
public:
	MovieHeaderBox();
	virtual ~MovieHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint64_t  GetCreationTime();
	uint64_t  GetModificationTime();
	uint32_t  GetTimescale();
	uint64_t  GetDuration();
	int32_t   GetRate();
	int16_t   GetVolume();
	uint8_t*  GetReserved0();
	uint32_t* GetReserved1();
	int32_t*  GetMatrix();
	uint8_t*  GetPreDefined();
	uint32_t  GetNextTrackId();

private:
	uint64_t m_creation_time;
	uint64_t m_modification_time;
	uint32_t m_timescale;
	uint64_t m_duration;
	int32_t  m_rate;
	int16_t  m_volume;
	uint8_t  m_reserved_0[2];
	uint32_t m_reserved_1[2];
	int32_t  m_matrix[9];
	uint8_t  m_pre_defined[24];
	uint32_t m_next_track_id;

private:
	// MovieBox* m_parent;
};

#endif /* ISOBMFF_MOVIEHEADERBOX_H_ */
