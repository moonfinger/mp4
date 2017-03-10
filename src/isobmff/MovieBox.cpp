/*
 * MovieBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "MovieBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

MovieBox::MovieBox() {
	// TODO Auto-generated constructor stub
	m_mvhd = NULL;
	m_parent = NULL;
}

MovieBox::~MovieBox() {
	// TODO Auto-generated destructor stub
	if(m_mvhd != NULL) {
		delete m_mvhd;
	}

	if(m_trak_list.size() > 0) {
		vector<TrackBox *>::iterator it = m_trak_list.begin();
		for(; it != m_trak_list.end(); ++it) {
			delete *it;
		}
	}
}

void MovieBox::Read(uint8_t* buf, int32_t len) {
	ReadBoxHeader(buf, len);

	uint8_t *ptr = m_ptr;
	int32_t offset = 0;

	uint32_t box_size, box_type;

	while(offset < len) {
		offset += bin_read_uint32(ptr + offset, &box_size);
		offset += bin_read_uint32(ptr + offset, &box_type);

		switch(box_type) {
		case box_mvhd: {
			MovieHeaderBox *mvhd = new MovieHeaderBox();
			mvhd->SetParent(this);
			mvhd->Read(ptr + (offset - 8), box_size);

			SetMovieHeaderBox(mvhd);
			break;
		}
		case box_trak: {
			TrackBox *trak = new TrackBox();
			trak->SetParent(this);
			trak->Read(ptr + (offset - 8), box_size);

			AddTrackBox(trak);
			break;
		}
		}

		offset += box_size;
	}
}

MovieHeaderBox* MovieBox::GetMoviewHeaderBox() {
	return m_mvhd;
}
void MovieBox::SetMovieHeaderBox(MovieHeaderBox* mvhd) {
	m_mvhd = mvhd;
}

vector<TrackBox *> MovieBox::GetTrackBoxList() {
	return m_trak_list;
}

void MovieBox::AddTrackBox(TrackBox* trak) {
	m_trak_list.push_back(trak);
}
