/*
 * FileTypeBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "FileTypeBox.h"

#include "../misc/bin.h"

FileTypeBox::FileTypeBox() {
	m_major_brand = 0;
	m_minor_version = 0;
	m_compatible_brands = NULL;
}

FileTypeBox::~FileTypeBox() {
	// TODO Auto-generated destructor stub
}

void FileTypeBox::Read(uint8_t *buf, int32_t len) {
	ReadBoxHeader(buf, len);

	m_offset += bin_read_uint32(m_ptr + m_offset, &m_major_brand);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_minor_version);

	int32_t compatible_brand_count = ((m_ptr + m_offset) - m_ptr) / sizeof(uint32_t);
	for(int32_t i = 0; i < compatible_brand_count; i++) {
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_compatible_brands[i]);
	}
}

uint32_t FileTypeBox::GetMajorBrand() {
	return m_major_brand;
}

uint32_t FileTypeBox::GetMinorVersion() {
	return m_minor_version;
}

uint32_t* FileTypeBox::GetCompatibleBrands() {
	return m_compatible_brands;
}
