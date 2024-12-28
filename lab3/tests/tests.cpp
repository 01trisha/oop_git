#include <gtest/gtest.h>
#include "../src/Config.h"

using namespace std;

TEST(ConfigTest, ConstructorTest) {
	char* argv[] = { (char*)"program_name", (char*)"-c", (char*)"config.txt", (char*)"output.wav", (char*)"input1.wav", (char*)"input2.wav" };
	int argc = sizeof(argv) / sizeof(argv[0]);

	View testView(argc, argv);
	Config config(testView);

	EXPECT_EQ(testView.getOutputFile(), config.getView().getOutputFile());
	EXPECT_EQ(testView.getOutputFile(), config.getProcessor().getOutputFile());
}

TEST(ViewTest, NoArguments) {
	char* argv[] = { (char*)"program_name" };

	View view(1, argv);

	EXPECT_TRUE("Error: wrong program arguments. To see help use '-h'");
}

TEST(ViewTest, HelpFlag) {
	char* argv[] = { (char*)"program_name", (char*)"-h" };

	View view(2, argv);

	EXPECT_TRUE(view.help());
}

TEST(ViewTest, WrongArguments) {
	char* argv[] = { (char*)"program_name", (char*)"incorrect_flag" };
	testing::internal::CaptureStdout();

	View view(2, argv);

	string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Error: wrong program arguments.") != string::npos);
}

TEST(ViewTest, CorrectArguments) {
	char* argv[] = { (char*)"program_name", (char*)"-c", (char*)"config.txt", (char*)"output.wav", (char*)"input.wav" };

	View view(5, argv);

	EXPECT_EQ(view.getConfig(), "config.txt");
	EXPECT_EQ(view.getOutputFile(), "output.wav");
	EXPECT_EQ(view.getInputFile(), "input.wav");
}

TEST(ProcessorTest, DefaultConstructor) {
	Processor processor;

	EXPECT_EQ(processor.getOutputFile(), "");
	EXPECT_EQ(processor.getInputFile(), "");
}

TEST(ProcessorTest, ConstructorWithView) {
	char *argv[] = { (char*)"program", (char*)"-c", (char*)"config.txt", (char*)"output.wav", (char*)"input.wav", (char*)"mix1.wav", (char*)"mix2.wav" };
	int argc = sizeof(argv) / sizeof(argv[0]);

	View view(argc, argv);

	EXPECT_EQ(view.getOutputFile(), "output.wav");
	EXPECT_EQ(view.getInputFile(), "input.wav");

	Processor processor(view);

	EXPECT_EQ(processor.getOutputFile(), "output.wav");
	EXPECT_EQ(processor.getInputFile(), "input.wav");
}

class ProcessorConvertingTest : public ::testing::Test
{
protected:
	void TearDown() override {
		remove("result1.wav");
		remove("result2.wav");
		remove("result3.wav");
		remove("result4.wav");
	}
};

TEST_F(ProcessorConvertingTest, ConvertingTest) {
	ifstream input1("input1.wav", ios::binary);
	ifstream input2("input2.wav", ios::binary);

	Processor processor;
	ofstream outputMute("result1.wav", ios::binary);

	ifstream inputMix("result1.wav", ios::binary);
	ofstream outputMix("result2.wav", ios::binary);

	processor.handle(ToolType::MIX, inputMix, outputMix, {"15", "20"}, {"input2.wav"});

	ifstream inputReverse("result2.wav", ios::binary);
	ofstream outputReverse("result3.wav", ios::binary);

	processor.handle(ToolType::REVERSE, inputReverse, outputReverse, {"25", "30"}, {"input2.wav"});

	ifstream inputMute2("result3.wav", ios::binary);
	ofstream outputMute2("result4.wav", ios::binary);

	processor.handle(ToolType::MUTE, inputMute2, outputMute2, {"9", "10"}, {"input2.wav"});

	ifstream result1("result4.wav", ios::binary);
	ifstream result2("../output.wav", ios::binary);

	int16_t data1, data2;
	while (result1.read(reinterpret_cast<char*>(&data1), sizeof(data1))
		&& result2.read(reinterpret_cast<char*>(&data2), sizeof(data2))) {
		ASSERT_EQ(data1, data2);
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
