///
///	I'm building this based on the adelay controller available in the adelay sample code for vst3.
///
#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"


#if MAC
#include <TargetConditionals.h>
#endif

using namespace Steinberg;

namespace TofuPop
{
namespace Vst
{
	class ADelayController : public Steinberg::Vst::EditController //I dislike this sort of declaration. But it will just have to do. 
	{
		//Incase you don't know the factory pattern, I'd read up on it a bit. 
		//Just google "factory pattern", because it seems like we are using it here.

		//-----------------------------------------------------------
		// create function required for plug-in factory,
		// it will be called to create new instances of this controller
		//-----------------------------------------------------------
		static FUnknown* createInstance(void*) { return (IEditController*)new ADelayController(); }

		//---from IPluginBase--------
		tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE; //WHERE IS TRESULT DECLARED>?EMKFASDKLFASDL:FASD!!!


		//---from EditController-----
		//There was some ios code, go peek the source of the sample project if you want it.
		tresult PLUGIN_API setComponentState(IBStream* state) SMTG_OVERRIDE;
	};
}
}