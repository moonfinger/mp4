/*
 * MediaHeaderBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "MediaHeaderBox.h"
#include "../misc/bin.h"

MediaHeaderBox::MediaHeaderBox() {
	// TODO Auto-generated constructor stub
	m_creation_time = 0;
	m_modification_time = 0;
	m_timescale = 0;
	m_duration = 0;
	m_language = 0;
	m_pre_defined = 0;
}

MediaHeaderBox::~MediaHeaderBox() {
	// TODO Auto-generated destructor stub
}

void MediaHeaderBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);

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

	m_offset += bin_read_uint16(m_ptr + m_offset, &m_language);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_pre_defined);
}

uint64_t MediaHeaderBox::GetCreationTime() {
	return m_creation_time;
}

uint64_t MediaHeaderBox::GetModificationTime() {
	return m_modification_time;
}

uint32_t MediaHeaderBox::GetTimescale() {
	return m_timescale;
}

uint64_t MediaHeaderBox::GetDuration() {
	return m_duration;
}

uint16_t MediaHeaderBox::GetLanguage() {
	return m_language;
}

uint16_t MediaHeaderBox::GetPreDefined() {
	return m_pre_defined;
}
