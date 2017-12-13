#include "utils/FileUtils.h"
#include <stdio.h>

namespace FileUtils {

	static void ReadText(const char* filepath, unsigned char*& filecontent, unsigned long& size) {
		FILE* filePointer = fopen(filepath, "r");

		fseek(filePointer, 0, SEEK_END);
		size = ftell(filePointer) + 1;
		fseek(filePointer, 0, SEEK_SET);

		filecontent = new unsigned char[size];

		fread(filecontent, sizeof(unsigned char), size, filePointer);

		fclose(filePointer);
	}
}