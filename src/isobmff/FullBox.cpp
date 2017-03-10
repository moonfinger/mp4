/*
 * FullBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "FullBox.h"
#include "../misc/bin.h"

FullBox::FullBox() {
	// TODO Auto-generated constructor stub
	m_version = 0;
}

FullBox::~FullBox() {
	// TODO Auto-generated destructor stub
}

void FullBox::ReadFullBoxHeader(uint8_t *buf, int32_t len) {
	ReadBoxHeader(buf, len);

	m_offset += bin_read_uint8(m_ptr + m_offset, &m_version);
	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(m_flags), m_flags);
}

uint8_t FullBox::GetVersion() {
	return m_version;
}

uint8_t* FullBox::GetFlags() {
	return m_flags;
}
