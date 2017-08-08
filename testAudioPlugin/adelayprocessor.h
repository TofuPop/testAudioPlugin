//Steinber comments marked with [Stein]

#pragma once
#include "public.sdk/source/vst/vstaudioeffect.h"

using namespace Steinberg; // calling stuff like this isn't a good idea, definetly when it shares names with our namespace.
using namespace Steinberg::Vst; // this practice is messy and bad. 
namespace TofuPop
{
namespace Vst // having our own Vst namespace may be a bad idea. We should consider a different name.
{
	class ADelayProcessor : public AudioEffect //gotta figure out where this one is define.
	{
	public:
		ADelayProcessor();
		//----------------------------------------------------
		tresult PLUGIN_API initialize (FUnknown* context) SMTG_OVERRIDE; // not really sure what this FUnknown is. likely in the steinberg namespace.
		tresult PLUGIN_API setBusArrangements(SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts) SMTG_OVERRIDE; // this one is likely pretty important, come back later.

		tresult PLUGIN_API setActive (TBool state) SMTG_OVERRIDE; 
		tresult PLUGIN_API process (ProcessData& data) SMTG_OVERRIDE; 
		//----------------------------------------------------
		tresult PLUGIN_API setState(IBStream* state) SMTG_OVERRIDE; 
		tresult PLUGIN_API getState(IBStream* state) SMTG_OVERRIDE; // I feel like this one is pretty self explanatory. Grab the state of the stream, make sure the stream is open.

		static FUnknown* createInstance(void*) { return (IAudioProcessor*)new ADelayProcessor(); }

	protected:
		ParamValue mDelay;
		float** mBuffer;
		int32 mBufferPos;
		bool mBypass;


	};
}
}