/*
 * VideoMediaHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "VideoMediaHeaderBox.h"
#include "../misc/bin.h"

VideoMediaHeaderBox::VideoMediaHeaderBox() {
	// TODO Auto-generated constructor stub
	m_graphicmode = 0;
}

VideoMediaHeaderBox::~VideoMediaHeaderBox() {
	// TODO Auto-generated destructor stub
}

void VideoMediaHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);

	m_offset += bin_read_uint16(m_ptr + m_offset, &m_graphicmode);

	for(uint32_t i = 0; i < sizeof(m_opcolor) / sizeof(uint16_t); i++) {
		m_offset += bin_read_uint16(m_ptr + m_offset, &m_opcolor[i]);
	}
}

uint16_t VideoMediaHeaderBox::GetGraphicmode() {
	return m_graphicmode;
}

uint16_t* VideoMediaHeaderBox::GetOpcolor() {
	return m_opcolor;
}
