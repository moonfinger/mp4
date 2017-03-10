/*
 * TrackHeaderBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_TRACKHEADERBOX_H_
#define ISOBMFF_TRACKHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"
//#include "TrackBox.h"

using namespace std;

class TrackHeaderBox : public FullBox {
public:
	TrackHeaderBox();
	virtual ~TrackHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint64_t  GetCreationTime();
	uint64_t  GetModificationTime();
	uint32_t  GetTrackId();
	uint32_t  GetReserved0();
	uint64_t  GetDuration();
	uint32_t* GetReserved1();
	int16_t   GetLayer();
	int16_t   GetAlternateGroup();
	int16_t   GetVolume();
	uint16_t  GetReserved2();
	int32_t*  GetMatrix();
	uint32_t  GetWidth();
	uint32_t  GetHeight();

private:
	uint64_t m_creation_time;
	uint64_t m_modification_time;
	uint32_t m_track_id;
	uint32_t m_reserved_0;
	uint64_t m_duration;
	uint32_t m_reserved_1[2];
	int16_t  m_layer;
	int16_t  m_alternate_group;
	int16_t  m_volume;
	uint16_t m_reserved_2;
	int32_t  m_matrix[9];
	uint32_t m_width;
	uint32_t m_height;

//private:
//	TrackBox* m_parent;
};

#endif /* ISOBMFF_TRACKHEADERBOX_H_ */
