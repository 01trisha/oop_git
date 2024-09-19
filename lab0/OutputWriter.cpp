#include "OutputWriter.h"

using namespace std;

OutputWriter::OutputWriter(string fileName, list<wstring> wordList, list<pair<wstring, int>> sortedList)
{
	outputFileName = fileName;
	words = wordList;
	sortedWords = sortedList;
}

void OutputWriter::CreateOutputFile()
{
	outputFile.open(outputFileName);

	if (!outputFile.is_open())
	{
		cout << "Failed to create file: " << outputFileName << endl;
		exit(EXIT_FAILURE);
	}
}

void OutputWriter::PrintAnswer()
{
	// Setting the locale for correct Unicode output (UTF-8)
	outputFile.imbue(locale(""));

	// Output CSV header
	outputFile << "Word;Frequency;Frequency in %" << endl;

	// Output sorted data to a CSV file
	for (const auto& pair : sortedWords)
	{
		double wordFrequency = 1.0 * pair.second / words.size() * 100.0;
		outputFile << pair.first << L";" << pair.second << L";" << wordFrequency << L"%" << endl;
	}

	cout << "CSV file created successfully" << endl;
}

void OutputWriter::CloseOutputFile()
{
	outputFile.close();
}
