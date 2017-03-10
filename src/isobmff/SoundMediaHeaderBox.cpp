/*
 * SoundMediaHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "SoundMediaHeaderBox.h"
#include "../misc/bin.h"

SoundMediaHeaderBox::SoundMediaHeaderBox() {
	// TODO Auto-generated constructor stub
	m_balance = 0;
	m_reserved_0 = 0;
}

SoundMediaHeaderBox::~SoundMediaHeaderBox() {
	// TODO Auto-generated destructor stub
}

void SoundMediaHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);

	m_offset += bin_read_int16(m_ptr + m_offset, &m_balance);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_reserved_0);
}

int16_t SoundMediaHeaderBox::GetBalance() {
	return m_balance;
}

uint16_t SoundMediaHeaderBox::GetReserved0() {
	return m_reserved_0;
}
