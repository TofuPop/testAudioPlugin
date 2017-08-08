
#include "exampletest.h"
#include "adelaycontroller.h"
#include "adelayprocessor.h"
#include "base/source/fstring.h"
#include "public.sdk/source/vst/testsuite/vsttestsuite.h"

// This is the only one that's really giving me any trouble!

namespace TofuPop
{

		DEF_CLASS_IID(ITest)
		DEF_CLASS_IID(ITestSuite)
		DEF_CLASS_IID(ITestFactory)

		namespace Vst {
		DEF_CLASS_IID(IPlugProvider)

			//-----------------------------------------------------------------------------
			FUID ADelayTestFactory::cid(0x60277237, 0x74CC4303, 0xB6737CA6, 0xEDD0F811);

		//-----------------------------------------------------------------------------
		tresult PLUGIN_API ADelayTestFactory::createTests(FUnknown* context, ITestSuite* parentSuite)
		{
			FUnknownPtr<IPlugProvider> plugProvider(context);
			if (plugProvider)
			{
				parentSuite->addTest("ExampleTest", owned(new ADelayTest(plugProvider)));
			}
			return kResultTrue;
		}

		//-----------------------------------------------------------------------------
		//-----------------------------------------------------------------------------
		//-----------------------------------------------------------------------------
		ADelayTest::ADelayTest(IPlugProvider* plugProvider)
			: plugProvider(plugProvider)
		{
		}

		//-----------------------------------------------------------------------------
		bool PLUGIN_API ADelayTest::setup()
		{
			return true;
		}

		//-----------------------------------------------------------------------------
		bool PLUGIN_API ADelayTest::run(ITestResult* testResult)
		{
			ADelayController* controller = FCast<ADelayController>(plugProvider->getController());
			ADelayProcessor* processor = FCast<ADelayProcessor>(plugProvider->getComponent());
			if (controller)
				testResult->addMessage(String("Correct IEditController"));
			else
				testResult->addErrorMessage(String("Unknown IEditController"));
			if (processor)
				testResult->addMessage(String("Correct IComponent"));
			else
				testResult->addErrorMessage(String("Unknown IComponent"));
			plugProvider->releasePlugIn(processor, controller);
			return (controller && processor);
		}

		//-----------------------------------------------------------------------------
		bool PLUGIN_API ADelayTest::teardown()
		{
			return true;
		}

		//-----------------------------------------------------------------------------
		const tchar* PLUGIN_API ADelayTest::getDescription()
		{
			static String description("Example Test");
#ifdef UNICODE
			return description.text16();
#else
			return description.text8();
#endif
		}

	}
} // namespaces
}