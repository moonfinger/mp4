/*
 * HintMediaHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "HintMediaHeaderBox.h"
#include "../misc/bin.h"

HintMediaHeaderBox::HintMediaHeaderBox() {
	// TODO Auto-generated constructor stub
	m_max_pdu_size = 0;
	m_avg_pdu_size = 0;
	m_max_bitrate = 0;
	m_avg_bitrate = 0;
	m_reserved_0 = 0;
}

HintMediaHeaderBox::~HintMediaHeaderBox() {
	// TODO Auto-generated destructor stub
}

void HintMediaHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);

	m_offset += bin_read_uint16(m_ptr + m_offset, &m_max_pdu_size);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_avg_pdu_size);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_max_bitrate);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_avg_bitrate);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_0);
}

uint16_t HintMediaHeaderBox::GetMaxPduSize() {
	return m_max_pdu_size;
}

uint16_t HintMediaHeaderBox::GetAvgPduSize() {
	return m_avg_pdu_size;
}

uint32_t HintMediaHeaderBox::GetMaxBitrate() {
	return m_max_bitrate;
}

uint32_t HintMediaHeaderBox::GetAvgBitrate() {
	return m_avg_bitrate;
}

uint32_t HintMediaHeaderBox::GetReserved0() {
	return m_reserved_0;
}
