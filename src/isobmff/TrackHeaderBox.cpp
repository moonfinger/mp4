/*
 * TrackHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "TrackHeaderBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

TrackHeaderBox::TrackHeaderBox() {
	// TODO Auto-generated constructor stub
	m_creation_time = 0;
	m_modification_time = 0;
	m_track_id = 0;
	m_reserved_0 = 0;
	m_duration = 0;
//	m_reserved_1 = NULL;
	m_layer = 0;
	m_alternate_group = 0;
	m_volume = 0;
	m_reserved_2 = 0;
//	m_matrix = NULL;
	m_width = 0;
	m_height = 0;
//	m_parent = NULL;
}

TrackHeaderBox::~TrackHeaderBox() {
	// TODO Auto-generated destructor stub
}

void TrackHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);
//	m_parent = static_cast<TrackBox *>(GetParent());

	if(GetVersion() == 1) {
		m_offset += bin_read_uint64(m_ptr + m_offset, &m_creation_time);
		m_offset += bin_read_uint64(m_ptr + m_offset, &m_modification_time);
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_track_id);
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_0);
		m_offset += bin_read_uint64(m_ptr + m_offset, &m_duration);
	} else {
		m_offset += bin_read_uint32(m_ptr + m_offset, (uint32_t *)&m_creation_time);
		m_offset += bin_read_uint32(m_ptr + m_offset, (uint32_t *)&m_modification_time);
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_track_id);
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_0);
		m_offset += bin_read_uint32(m_ptr + m_offset, (uint32_t *)&m_duration);
	}

	for(uint32_t i = 0; i < sizeof(m_reserved_1) / sizeof(uint32_t); i++) {
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_1[i]);
	}

	m_offset += bin_read_int16(m_ptr + m_offset, &m_layer);
	m_offset += bin_read_int16(m_ptr + m_offset, &m_alternate_group);
	m_offset += bin_read_int16(m_ptr + m_offset, &m_volume);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_reserved_2);

	for(uint32_t i = 0; i < sizeof(m_matrix) / sizeof(int32_t); i++) {
		m_offset += bin_read_int32(m_ptr + m_offset, &m_matrix[i]);
	}

	m_offset += bin_read_uint32(m_ptr + m_offset, &m_width);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_height);
}

uint64_t TrackHeaderBox::GetCreationTime() {
	return m_creation_time;
}

uint64_t TrackHeaderBox::GetModificationTime() {
	return m_modification_time;
}

uint32_t TrackHeaderBox::GetTrackId() {
	return m_track_id;
}

uint32_t TrackHeaderBox::GetReserved0() {
	return m_reserved_0;
}

uint64_t TrackHeaderBox::GetDuration() {
	return m_duration;
}

uint32_t* TrackHeaderBox::GetReserved1() {
	return m_reserved_1;
}

int16_t TrackHeaderBox::GetLayer() {
	return m_layer;
}

int16_t TrackHeaderBox::GetAlternateGroup() {
	return m_alternate_group;
}

int16_t TrackHeaderBox::GetVolume() {
	return m_volume;
}

uint16_t TrackHeaderBox::GetReserved2() {
	return m_reserved_2;
}

int32_t* TrackHeaderBox::GetMatrix() {
	return m_matrix;
}

uint32_t TrackHeaderBox::GetWidth() {
	return m_width;
}

uint32_t TrackHeaderBox::GetHeight() {
	return m_height;
}
