/*
 * SampleEntry.h
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_SAMPLEENTRY_H_
#define ISOBMFF_SAMPLEENTRY_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"

using namespace std;

class SampleEntry : public Box {
public:
	SampleEntry();
	virtual ~SampleEntry();

protected:
	void ReadEntryHeader(uint8_t *buf, int32_t len);

protected:
	uint8_t* GetReserved0();
	uint16_t GetDataReferenceIndex();

protected:
	uint8_t m_reserved_0[6];
	uint16_t m_data_reference_index;
};

class AudioSampleEntry : public SampleEntry {
public:
	AudioSampleEntry();
	virtual ~AudioSampleEntry();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint32_t* GetReserved1();
	uint16_t  GetChannelcount();
	uint16_t  GetSamplesize();
	uint16_t  GetPreDefined();
	uint16_t  GetReserved2();
	uint32_t  GetSamplerate();

private:
	uint32_t m_reserved_1[2];
	uint16_t m_channelcount;
	uint16_t m_samplesize;
	uint16_t m_pre_defined;
	uint16_t m_reserved_2;
	uint32_t m_samplerate;
};


class CleanApertureBox : public Box {
public:
	CleanApertureBox();
	virtual ~CleanApertureBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint32_t GetCleanApertureWidthN();
	uint32_t GetCleanApertureWidthD();
	uint32_t GetCleanApertureHeightN();
	uint32_t GetCleanApertureHeightD();
	uint32_t GetHorizOffN();
	uint32_t GetHorizOffD();
	uint32_t GetVertOffN();
	uint32_t GetVertOffD();

private:
	uint32_t m_clean_aperture_width_n;
	uint32_t m_clean_aperture_width_d;
	uint32_t m_clean_aperture_height_n;
	uint32_t m_clean_aperture_height_d;
	uint32_t m_horiz_off_n;
	uint32_t m_horiz_off_d;
	uint32_t m_vert_off_n;
	uint32_t m_vert_off_d;
};

class PixelAspectRatioBox : public Box {
public:
	PixelAspectRatioBox();
	virtual ~PixelAspectRatioBox();

public:
	void Read(uint32_t *buf, int32_t len);

public:
	uint32_t GetHSpacing();
	uint32_t GetVSpacing();

private:
	uint32_t m_h_spacing;
	uint32_t m_v_spacing;
};

class VideoSampleEntry : public SampleEntry {
public:
	VideoSampleEntry();
	virtual ~VideoSampleEntry();

public:
	void Read(uint8_t *buf, int32_t len);

private:
	uint16_t m_pre_defined_0;
	uint16_t m_reserved_1;
	uint32_t m_pre_defined_1[3];
	uint16_t m_width;
	uint16_t m_height;
	uint32_t m_horizresolution;
	uint32_t m_vertresolution;
	uint32_t m_reserved_2;
	uint16_t m_fram_count;
	string   m_compressorname;
	uint16_t m_depth;
	int16_t  m_pre_defined_2;

private:
	CleanApertureBox* m_clap;
	PixelAspectRatioBox* m_pasp;
};

class HintSampleEntry : public SampleEntry {
public:
	HintSampleEntry();
	virtual ~HintSampleEntry();

public:
	void Read(uint8_t *buf, int32_t len);

private:
	uint8_t *m_data;
};

class MetaDataSampleEntry : public SampleEntry {

};


#endif /* ISOBMFF_SAMPLEENTRY_H_ */
