/*
 * MediaInformationBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_MEDIAINFORMATIONBOX_H_
#define ISOBMFF_MEDIAINFORMATIONBOX_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"
#include "TrackBox.h"
#include "VideoMediaHeaderBox.h"
#include "SoundMediaHeaderBox.h"
#include "HintMediaHeaderBox.h"
#include "DataInformationBox.h"

using namespace std;

class MediaInformationBox : public Box {
public:
	MediaInformationBox();
	virtual ~MediaInformationBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	VideoMediaHeaderBox* GetVideoMediaHeaderBox();
	void SetVideoMediaHeaderBox(VideoMediaHeaderBox* vmhd);
	SoundMediaHeaderBox* GetSoundMediaHeaderBox();
	void SetSoundMediaHeaderBox(SoundMediaHeaderBox* smhd);
	HintMediaHeaderBox* GetHintMediaHeaderBox();
	void SetHintMediaHeaderBox(HintMediaHeaderBox *hmhd);
	DataInformationBox* GetDataInformationBox();
	void SetDataInformationBox(DataInformationBox* dinf);

private:
	VideoMediaHeaderBox* m_vmhd;
	SoundMediaHeaderBox* m_smhd;
	HintMediaHeaderBox* m_hmhd;
	DataInformationBox* m_dinf;


};

#endif /* ISOBMFF_MEDIAINFORMATIONBOX_H_ */
