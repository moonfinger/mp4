/*
 * MediaBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "MediaBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

MediaBox::MediaBox() {
	// TODO Auto-generated constructor stub
	m_mdhd = NULL;
	m_hdlr = NULL;
	m_minf = NULL;
}

MediaBox::~MediaBox() {
	// TODO Auto-generated destructor stub
	if(m_mdhd != NULL) {
		delete m_mdhd;
	}

	if(m_hdlr != NULL) {
		delete m_hdlr;
	}

	if(m_minf != NULL) {
		delete m_minf;
	}
}

void MediaBox::Read(uint8_t* buf, int32_t len) {
	ReadBoxHeader(buf, len);

	uint8_t *ptr = m_ptr;
	int32_t offset = 0;

	uint32_t box_size, box_type;

	while(offset < len) {
		offset += bin_read_uint32(ptr + offset, &box_size);
		offset += bin_read_uint32(ptr + offset, &box_type);

		switch(box_type) {
		case box_mdhd: {
			MediaHeaderBox *mdhd = new MediaHeaderBox();
			mdhd->Read(ptr + (offset - 8), box_size);

			SetMediaHeaderbox(mdhd);
			break;
		}
		case box_hdlr: {
			HandlerBox *hdlr = new HandlerBox();
			hdlr->Read(ptr + (offset - 8), box_size);

			SetHandlerBox(hdlr);
			break;
		}
		case box_minf: {
			MediaInformationBox *minf = new MediaInformationBox();

			SetMediaInformationBox(minf);
			break;
		}
		default:
			break;
		}

		offset += box_size;
	}
}

MediaHeaderBox* MediaBox::GetMediaHeaderBox() {
	return m_mdhd;
}

void MediaBox::SetMediaHeaderbox(MediaHeaderBox* mdhd) {
	m_mdhd = mdhd;
}

HandlerBox* MediaBox::GetHandlerBox() {
	return m_hdlr;
}

void MediaBox::SetHandlerBox(HandlerBox* hdlr) {
	m_hdlr = hdlr;
}

MediaInformationBox* MediaBox::GetMediaInformationBox() {
	return m_minf;
}

void MediaBox::SetMediaInformationBox(MediaInformationBox* minf) {
	m_minf = minf;
}
