/*
 * FileTypeBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_FILETYPEBOX_H_
#define ISOBMFF_FILETYPEBOX_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"

using namespace std;

class FileTypeBox : public Box {
public:
	FileTypeBox();
	virtual ~FileTypeBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint32_t  GetMajorBrand();
	uint32_t  GetMinorVersion();
	uint32_t* GetCompatibleBrands();

private:
	uint32_t  m_major_brand;
	uint32_t  m_minor_version;
	uint32_t* m_compatible_brands;
};

#endif /* ISOBMFF_FILETYPEBOX_H_ */
