#pragma once

#include "Point3d.h"
#include "Node.h"
#include "NormalPosition.h"
#include "WaveGuide.h"
#include "Microphone.h"
#include "Stereo.h"
#include "Mono.h"
#include "Ambisonic.h"
#include "HRTF_output.h"

//Listener node in the SDN architecture, can output mono, stereo or ambisonics
namespace SDN
{

	class Receiver : public Node, public NormalPosition, public NodeRotation
	{
	public:
		Receiver();
		~Receiver() { microphone.reset(); };

		//initialize all output instances to save performance during playback
		void init(Point3d normalPosition, int numsamples, int nOfConnections, double samplerate, Point3d dimensions);

		void process(juce::AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged);

		void updatePosition();
#ifdef _BRT_LIBRARY_
		bool setHRTF(std::string& newPath)
		{
			return hrtf->setHRTF(newPath);
		}
#endif

		void setOutputMode(int mode);

		std::vector<WaveGuide*> inWaveguides;

	private:

		//currently selected output mode 0-Mono 1-Stereo 2->6 Ambisonic
		int outModeIndex = 0;
	
		std::shared_ptr<SDN::Microphone> microphone;
		std::shared_ptr<SDN::Mono> mono;
		std::shared_ptr<SDN::Stereo> stereo;
		std::shared_ptr<SDN::Ambisonic> ambisonic;
	#ifdef _BRT_LIBRARY_
		std::shared_ptr<SDN::HRTF_output> hrtf;
	#endif

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Receiver);

	};

}