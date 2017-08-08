#include "public.sdk/source/main/pluginfactoryvst3.h"
#include "adelaycontroller.h"
#include "adelayprocessor.h"
#include "adelayids.h"
#include "exampletest.h"
#include "version.h"	// for versioning


#define stringPluginName "ADelay"

BEGIN_FACTORY_DEF("TofuPop Recordings",
				  "https://TofuPop.com",
				  "mailto:admin@tofupop.com")

	DEF_CLASS2(INLINE_UID_FROM_FUID(TofuPop::Vst::ADelayProcessorUID),
		PClassInfo::kManyInstances,
		kVstAudioEffectClass,
		stringPluginName,
		Vst::kDistributable,
		"Fx|Delay",
		FULL_VERSION_STR,		// Plug-in version (to be changed)
		kVstVersionString,
		TofuPop::Vst::ADelayProcessor::createInstance)

	DEF_CLASS2(INLINE_UID_FROM_FUID(TofuPop::Vst::ADelayControllerUID),
		PClassInfo::kManyInstances,
		kVstComponentControllerClass,
		stringPluginName "Controller",	// controller name (could be the same than component name)
		0,						// not used here
		"",						// not used here
		FULL_VERSION_STR,		// Plug-in version (to be changed)
		kVstVersionString,
		TofuPop::Vst::ADelayController::createInstance)

	// add Test Factory
	DEF_CLASS2(INLINE_UID_FROM_FUID(TofuPop::Vst::ADelayTestFactory::cid),
		PClassInfo::kManyInstances,
		kTestClass,
		stringPluginName "Test Factory",
		0,
		"",
		"",
		"",
		TofuPop::Vst::ADelayTestFactory::createInstance)

	END_FACTORY

	bool InitModule() { return true; }
bool DeinitModule() { return true; }