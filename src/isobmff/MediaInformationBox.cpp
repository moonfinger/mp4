/*
 * MediaInformationBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "MediaInformationBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

MediaInformationBox::MediaInformationBox() {
	// TODO Auto-generated constructor stub
	m_vmhd = NULL;
	m_smhd = NULL;
	m_hmhd = NULL;
	m_dinf = NULL;
}

MediaInformationBox::~MediaInformationBox() {
	// TODO Auto-generated destructor stub
	if(m_vmhd) delete m_vmhd;
	if(m_smhd) delete m_smhd;
	if(m_hmhd) delete m_hmhd;
	if(m_dinf) delete m_dinf;
}

void MediaInformationBox::Read(uint8_t* buf, int32_t len) {
	ReadBoxHeader(buf, len);
	m_parent = static_cast<TrackBox *>(GetParent());

	uint8_t *ptr = m_ptr;
	int32_t offset = 0;
	int32_t size = len - m_offset;

	uint32_t box_size, box_type;

	while(offset < size) {
		offset += bin_read_uint32(ptr + offset, &box_size);
		offset += bin_read_uint32(ptr + offset, &box_type);

		switch(box_type) {
		case box_vmhd: {
			VideoMediaHeaderBox* vmhd = new VideoMediaHeaderBox();
			vmhd->SetParent(this);
			vmhd->Read(ptr + (offset - 8), box_size);

			SetVideoMediaHeaderBox(vmhd);
			break;
		}
		case box_smhd: {
			SoundMediaHeaderBox* smhd = new SoundMediaHeaderBox();
			smhd->SetParent(this);
			smhd->Read(ptr + (offset - 8), box_size);

			SetSoundMediaHeaderBox(smhd);
			break;
		}
		case box_hmhd: {
			HintMediaHeaderBox* hmhd = new HintMediaHeaderBox();
			hmhd->SetParent(this);
			hmhd->Read(ptr + (offset - 8), box_size);

			SetHintMediaHeaderBox(hmhd);
			break;
		}
		case box_dinf: {
			DataInformationBox* dinf = new DataInformationBox();
			dinf->SetParent(this);
			dinf->Read(ptr + (offset - 8), box_size);

			SetDataInformationBox(dinf);
			break;
		}
		default:
			break;
		}

		offset += box_size;
	}
}

VideoMediaHeaderBox* MediaInformationBox::GetVideoMediaHeaderBox() {
	return m_vmhd;
}

void MediaInformationBox::SetVideoMediaHeaderBox(VideoMediaHeaderBox* vmhd) {
	m_vmhd = vmhd;
}

SoundMediaHeaderBox* MediaInformationBox::GetSoundMediaHeaderBox() {
	return m_smhd;
}

void MediaInformationBox::SetSoundMediaHeaderBox(SoundMediaHeaderBox* smhd) {
	m_smhd = smhd;
}

HintMediaHeaderBox* MediaInformationBox::GetHintMediaHeaderBox() {
	return m_hmhd;
}

void MediaInformationBox::SetHintMediaHeaderBox(HintMediaHeaderBox* hmhd) {
	m_hmhd = hmhd;
}

DataInformationBox* MediaInformationBox::GetDataInformationBox() {
	return m_dinf;
}

void MediaInformationBox::SetDataInformationBox(DataInformationBox* dinf) {
	m_dinf = dinf;
}
