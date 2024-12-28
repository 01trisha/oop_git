#pragma once
#include <cstdint>
#include <string>
#include <map>

enum class ToolType {
    MUTE,
    MIX,
    REVERSE,
    IN,
    OUT
};

const std::map<std::string, ToolType> toolTypeMap = {
    {"mute", ToolType::MUTE},
    {"mix", ToolType::MIX},
    {"reverse", ToolType::REVERSE},
    {"in", ToolType::IN},
    {"out", ToolType::OUT}
};


struct WAV_HEADER
{
	//начало riff цепочки
	uint8_t chunkID[4] = {'R', 'I', 'F', 'F'};
	//оставшийся размер цепочки, начиная с этой позиции
	uint32_t chunkSize;
	//формат файла wav
	uint8_t format[4] = {'W', 'A', 'V', 'E'};
	//чанк содержащий информацию о формате аудио-данных
	uint8_t subchunk1ID[4] = {'f', 'm', 't', ' '};
	uint32_t subchunk1Size = 16;
	//PCM без кодирования
	uint16_t audioFormat = 1;
	//количество каналов = 1(монозвук)
	uint16_t numOfChannels = 1;
	//частота дискретизации 
	uint32_t samplesPedSec = 44100;
	//количество байт, переданных за секунду воспроизведения
	uint32_t byteRate = 44100 * 2;
	//количество байт для одного сэмпла, включая все каналы
	uint16_t blockAlign = 2;
	//разрядность семла(количество бит в сэмпле)
	uint16_t bitsPerSample = 16;
	//сами wav-данные
	uint8_t subchunk2ID[4] = {'d', 'a', 't', 'a'};
	//количество байт в области данных
	uint32_t subchunk2Size;
};
