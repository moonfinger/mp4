/*
 * MovieHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "MovieHeaderBox.h"
#include "../misc/bin.h"

MovieHeaderBox::MovieHeaderBox() {
	m_creation_time = 0;
	m_modification_time = 0;
	m_timescale = 0;
	m_duration = 0;
	m_rate = 0;
	m_volume = 0;
//	m_reserved_0 = NULL;
//	m_reserved_1 = NULL;
//	m_matrix = NULL;
//	m_pre_defined = NULL;
	m_next_track_id = 0;
	m_parent = NULL;
}

MovieHeaderBox::~MovieHeaderBox() {
	// TODO Auto-generated destructor stub
}

void MovieHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);
//	m_parent = static_cast<MovieBox *>(GetParent());

	if(GetVersion() == 1) {
		m_offset += bin_read_uint64(m_ptr + m_offset, &m_creation_time);
		m_offset += bin_read_uint64(m_ptr + m_offset, &m_modification_time);
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_timescale);
		m_offset += bin_read_uint64(m_ptr + m_offset, &m_duration);
	} else {
		m_offset += bin_read_uint32(m_ptr + m_offset, (uint32_t *)&m_creation_time);
		m_offset += bin_read_uint32(m_ptr + m_offset, (uint32_t *)&m_modification_time);
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_timescale);
		m_offset += bin_read_uint32(m_ptr + m_offset, (uint32_t *)&m_duration);
	}

	m_offset += bin_read_int32(m_ptr + m_offset, &m_rate);
	m_offset += bin_read_int16(m_ptr + m_offset, &m_volume);
	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(m_reserved_0), m_reserved_0);

	for(uint32_t i = 0; i < sizeof(m_reserved_1) / sizeof(uint32_t); i++) {
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_1[i]);
	}

	for(uint32_t i = 0; i < sizeof(m_matrix) / sizeof(int32_t); i++) {
		m_offset += bin_read_int32(m_ptr + m_offset, &m_matrix[i]);
	}

	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(m_pre_defined), m_pre_defined);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_next_track_id);
}

uint64_t MovieHeaderBox::GetCreationTime() {
	return m_creation_time;
}

uint64_t MovieHeaderBox::GetModificationTime() {
	return m_modification_time;
}

uint32_t MovieHeaderBox::GetTimescale() {
	return m_timescale;
}

uint64_t MovieHeaderBox::GetDuration() {
	return m_duration;
}

int32_t MovieHeaderBox::GetRate() {
	return m_rate;
}

int16_t MovieHeaderBox::GetVolume() {
	return m_volume;
}

uint8_t* MovieHeaderBox::GetReserved0() {
	return m_reserved_0;
}

uint32_t* MovieHeaderBox::GetReserved1() {
	return m_reserved_1;
}

int32_t* MovieHeaderBox::GetMatrix() {
	return m_matrix;
}

uint8_t* MovieHeaderBox::GetPreDefined() {
	return m_pre_defined;
}

uint32_t MovieHeaderBox::GetNextTrackId() {
	return m_next_track_id;
}
