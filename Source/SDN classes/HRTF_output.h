#pragma once


#include <Microphone.h>
#include <WaveGuide.h>
#include <Parameters.h>
#include <Eigen/Geometry>

//#if __has_include("BRTLibrary.h")
////#pragma comment(lib, "../../Libraries/BRTLibrary/include/third_party_libraries/libmysofa/lib/vs/x64/Release/mysofa.lib")
////#pragma comment(lib, "../../Libraries/BRTLibrary/include/third_party_libraries/libmysofa/lib/vs/x64/Release/zlibstatic.lib")
//#include <BRTLibrary.h>
//#endif

#ifdef _BRT_LIBRARY_

#define HRTFRESAMPLINGSTEP 15
namespace SDN
{
	class HRTF_output : public SDN::Microphone
	{
	public:
		HRTF_output();
		~HRTF_output() {};

		void init(double samplerate, int buffersize);

		void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation, juce::AudioBuffer<float>& sourceBuffer,
			int sampleIndex, int maxIndex, bool hasChanged, bool isRotating) override;

		bool setHRTF(std::string& newPath)
		{
			if (!isInit)
				initBRTEnv();

			std::shared_ptr<BRTServices::CHRTF>  temp_hrtf_loaded = std::make_shared<BRTServices::CHRTF>();
			bool result = sofaReader.ReadHRTFFromSofa(newPath, temp_hrtf_loaded, HRTFRESAMPLINGSTEP, BRTServices::TEXTRAPOLATION_METHOD::nearest_point);

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

		void initBRTEnv();

		Common::CGlobalParameters globalParameters;
		BRTBase::CBRTManager envManager;
		std::shared_ptr<BRTListenerModel::CListenerDirectHRTFConvolutionModel> envHRTFProcessor;
		std::shared_ptr<BRTBase::CListener> envListener;
		std::vector<std::shared_ptr<BRTSourceModel::CSourceOmnidirectionalModel>> envSources;
		Common::CTransform tempTransform;
		std::vector<CMonoBuffer<float>> envSourceBuffers;
		Common::CEarPair<CMonoBuffer<float>> bufferProcessed;
		BRTReaders::CSOFAReader sofaReader;
		std::shared_ptr<BRTServices::CHRTF> hrtf_loaded;
		bool newPos = true;
		bool isInit = false;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HRTF_output)
	};
}

#endif // _BRT_LIBRARY_