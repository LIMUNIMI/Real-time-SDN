#pragma once


#include <Microphone.h>
#include <WaveGuide.h>
#include <Parameters.h>
#include <Eigen/Geometry>

#if __has_include("BRTLibrary.h")
#pragma comment(lib, "../../../BRTLibrary-main/include/third_party_libraries/libmysofa/lib/vs/x64/Release/mysofa.lib")
#pragma comment(lib, "../../../BRTLibrary-main/include/third_party_libraries/libmysofa/lib/vs/x64/Release/zlibstatic.lib")
#include <BRTLibrary.h>
#endif

#ifdef _BRT_LIBRARY_

#define HRTFRESAMPLINGSTEP 15

class HRTF_output: public Microphone
{
public:
	HRTF_output();
	~HRTF_output() {};

	void init(double samplerate, int buffersize);

	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation, AudioBuffer<float>& sourceBuffer,
		int sampleIndex, int maxIndex, bool hasChanged, bool isRotating) override;

	bool setHRTF(std::string& newPath)
	{
		std::shared_ptr<BRTServices::CHRTF>  temp_hrtf_loaded = std::make_shared<BRTServices::CHRTF>();
		bool result = sofaReader.ReadHRTFFromSofa(newPath, temp_hrtf_loaded, HRTFRESAMPLINGSTEP);

		if (result) 
		{
			envListener->RemoveHRTF();
			result &= envListener->SetHRTF(temp_hrtf_loaded);
			if (!result)
				envListener->SetHRTF(hrtf_loaded);
			else
				hrtf_loaded = temp_hrtf_loaded;
		}

		return result;
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

#endif // _BRT_LIBRARY_