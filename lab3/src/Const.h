#pragma once
#include <cstdint>

enum ToolType {
	Mute,
	Mix,
	Reverse,
	In,
	Out,
};

struct WAV_HEADER
{
	uint8_t chunkID[4] = {'R', 'I', 'F', 'F'};
	uint32_t chunkSize;
	uint8_t format[4] = {'W', 'A', 'V', 'E'};
	uint8_t subchunk1ID[4] = {'f', 'm', 't', ' '};
	uint32_t subchunk1Size = 16;
	uint16_t audioFormat = 1;
	uint16_t numOfChannels = 1;
	uint32_t samplesPedSec = 44100;
	uint32_t byteRate = 44100 * 2;
	uint16_t blockAlign = 2;
	uint16_t bitsPerSample = 16;
	uint8_t subchunk2ID[4] = {'d', 'a', 't', 'a'};
	uint32_t subchunk2Size;
};
