/*
 * SampleEntry.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#include "SampleEntry.h"
#include "../misc/bin.h"

SampleEntry::SampleEntry() {
	// TODO Auto-generated constructor stub
	m_data_reference_index = 0;
}

SampleEntry::~SampleEntry() {
	// TODO Auto-generated destructor stub
}

void SampleEntry::ReadEntryHeader(uint8_t* buf, int32_t len) {
	ReadBoxHeader(buf, len);

	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(m_reserved_0), m_reserved_0);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_data_reference_index);
}

uint8_t* SampleEntry::GetReserved0() {
	return m_reserved_0;
}

uint16_t SampleEntry::GetDataReferenceIndex() {
	return m_data_reference_index;
}

AudioSampleEntry::AudioSampleEntry() {
	m_channelcount = 0;
	m_samplesize = 0;
	m_pre_defined = 0;
	m_reserved_2 = 0;
	m_samplerate = 0;
}

AudioSampleEntry::~AudioSampleEntry() {
}

void AudioSampleEntry::Read(uint8_t* buf, int32_t len) {
	ReadEntryHeader(buf, len);

	for(uint32_t i = 0; i < sizeof(m_reserved_1) / sizeof(uint32_t); i++) {
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_1[i]);
	}

	m_offset += bin_read_uint16(m_ptr + m_offset, &m_channelcount);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_samplesize);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_pre_defined);
	m_offset += bin_read_uint16(m_ptr + m_offset, &m_reserved_2);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_samplerate);
}

uint32_t* AudioSampleEntry::GetReserved1() {
	return m_reserved_1;
}

uint16_t AudioSampleEntry::GetChannelcount() {
	return m_channelcount;
}

uint16_t AudioSampleEntry::GetSamplesize() {
	return m_samplesize;
}

uint16_t AudioSampleEntry::GetPreDefined() {
	return m_pre_defined;
}

uint16_t AudioSampleEntry::GetReserved2() {
	return m_reserved_2;
}

uint32_t AudioSampleEntry::GetSamplerate() {
	return m_samplerate;
}

CleanApertureBox::CleanApertureBox() {
	m_clean_aperture_width_n = 0;
	m_clean_aperture_width_d = 0;
	m_clean_aperture_height_n = 0;
	m_clean_aperture_height_d = 0;
	m_horiz_off_n = 0;
	m_horiz_off_d = 0;
	m_vert_off_n = 0;
	m_vert_off_d = 0;
}

CleanApertureBox::~CleanApertureBox() {
}

void CleanApertureBox::Read(uint8_t* buf, int32_t len) {
}

uint32_t CleanApertureBox::GetCleanApertureWidthN() {
	return m_clean_aperture_width_n;
}

uint32_t CleanApertureBox::GetCleanApertureWidthD() {
	return m_clean_aperture_width_d;
}

uint32_t CleanApertureBox::GetCleanApertureHeightN() {
	return m_clean_aperture_height_n;
}

uint32_t CleanApertureBox::GetCleanApertureHeightD() {
	return m_clean_aperture_height_d;
}

uint32_t CleanApertureBox::GetHorizOffN() {
	return m_horiz_off_n;
}

uint32_t CleanApertureBox::GetHorizOffD() {
	return m_horiz_off_d;
}

uint32_t CleanApertureBox::GetVertOffN() {
	return m_vert_off_n;
}

uint32_t CleanApertureBox::GetVertOffD() {
	return m_vert_off_d;
}

PixelAspectRatioBox::PixelAspectRatioBox() {
	m_h_spacing = 0;
	m_v_spacing = 0;
}

PixelAspectRatioBox::~PixelAspectRatioBox() {
}

void PixelAspectRatioBox::Read(uint32_t* buf, int32_t len) {
}

uint32_t PixelAspectRatioBox::GetHSpacing() {
	return m_h_spacing;
}

uint32_t PixelAspectRatioBox::GetVSpacing() {
	return m_v_spacing;
}

VideoSampleEntry::VideoSampleEntry() {
	m_pre_defined_0 = 0;
	m_reserved_1 = 0;
	m_width = 0;
	m_height = 0;
	m_horizresolution = 0;
	m_vertresolution = 0;
	m_reserved_2 = 0;
	m_fram_count = 0;
	m_depth = 0;
	m_pre_defined_2 = 0;
	m_clap = NULL;
	m_pasp = NULL;
}

VideoSampleEntry::~VideoSampleEntry() {
}

void VideoSampleEntry::Read(uint8_t* buf, int32_t len) {
}

HintSampleEntry::HintSampleEntry() {
	m_data = NULL;
}

HintSampleEntry::~HintSampleEntry() {
}

void HintSampleEntry::Read(uint8_t* buf, int32_t len) {
}
