/*
 * TrackBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "TrackBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

TrackBox::TrackBox() {
	// TODO Auto-generated constructor stub
	m_tkhd = NULL;
//	m_mdia = NULL;
//	m_parent = NULL;
}

TrackBox::~TrackBox() {
	// TODO Auto-generated destructor stub
	if(m_tkhd != NULL) {
		delete m_tkhd;
	}
}

void TrackBox::Read(uint8_t* buf, int32_t len) {
	ReadBoxHeader(buf, len);

//	m_parent = static_cast<MovieBox *>(GetParent());

	uint8_t *ptr = m_ptr;
	int32_t offset = 0;

	uint32_t box_size, box_type;

	while(offset < len) {
		offset += bin_read_uint32(ptr + offset, &box_size);
		offset += bin_read_uint32(ptr + offset, &box_type);

		switch(box_type) {
		case box_tkhd: {
			TrackHeaderBox *tkhd = new TrackHeaderBox();
			tkhd->SetParent(this);
			tkhd->Read(ptr + (offset - 8), box_size);

			SetTrackHeaderBox(tkhd);
			break;
		}

		case box_mdia: {
			MediaInformationBox* mdia = new MediaInformationBox();
			mdia->SetParent(this);
			mdia->Read(ptr + (offset - 8), box_size);

//			SetMediaInformationBox(mdia);
			break;
		}

		default:
			break;
		}

		offset += box_size;
	}
}

TrackHeaderBox* TrackBox::GetTrackHeaderBox() {
	return m_tkhd;
}

void TrackBox::SetTrackHeaderBox(TrackHeaderBox* tkhd) {
	m_tkhd = tkhd;
}

//MediaInformationBox* TrackBox::GetMediaInformationBox() {
//	return m_mdia;
//}
//
//void TrackBox::SetMediaInformationBox(MediaInformationBox* mdia) {
//	m_mdia = mdia;
//}
