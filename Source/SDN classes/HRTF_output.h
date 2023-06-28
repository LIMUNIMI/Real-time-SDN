#pragma once

#include <Microphone.h>
#include <WaveGuide.h>
#include <Parameters.h>
#include <Eigen/Geometry>
#include <BRTLibrary.h>

#define HRTFRESAMPLINGSTEP 15
#define HRTF_BUFFER_SIZE 512

class HRTF_output: public Microphone
{
public:
	HRTF_output();
	~HRTF_output() {};

	void init(double samplerate, int buffersize);

	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& sourceBuffer,
		int sampleIndex, int maxIndex, bool hasChanged) override;

	//bugs randomly on HRTF switch
	void setHRTF(std::string& newPath)
	{
		envListener->RemoveHRTF();
		hrtf_loaded = std::make_shared<BRTServices::CHRTF>();
		bool result = sofaReader.ReadHRTFFromSofa(newPath, hrtf_loaded, HRTFRESAMPLINGSTEP);

		if (result) 
		{
			envListener->SetHRTF(hrtf_loaded);
		}
	}

private:

	Common::CGlobalParameters globalParameters;
	BRTBase::CBRTManager envManager;
	std::shared_ptr<BRTListenerModel::CListenerHRTFbasedModel> envListener;
	std::vector<std::shared_ptr<BRTSourceModel::CSourceSimpleModel>> envSources;
	Common::CTransform tempTransform;
	std::vector<CMonoBuffer<float>> envSourceBuffers;
	Common::CEarPair<CMonoBuffer<float>> bufferProcessed;
	BRTReaders::CSOFAReader sofaReader;
	std::shared_ptr<BRTServices::CHRTF> hrtf_loaded;
	bool newPos = true;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HRTF_output)
};
