
#ifndef __exampletest__
#define __exampletest__

#include "base/source/fobject.h"
#include "pluginterfaces/test/itest.h"

using namespace Steinberg;

namespace TofuPop
{
namespace Vst
{
	class IPlugProvider;

	//-----------------------------------------------------------------------------
	class ADelayTest : public ITest, public FObject
	{
	public:
		ADelayTest(IPlugProvider* plugProvider);

		//--ITest
		virtual bool PLUGIN_API setup() SMTG_OVERRIDE;
		virtual bool PLUGIN_API run(ITestResult* testResult) SMTG_OVERRIDE;
		virtual bool PLUGIN_API teardown() SMTG_OVERRIDE;
		virtual const tchar* PLUGIN_API getDescription() SMTG_OVERRIDE;

		OBJ_METHODS(ADelayTest, FObject)
			DEF_INTERFACES_1(ITest, FObject)
			REFCOUNT_METHODS(FObject)
	protected:
		IPlugProvider* plugProvider;
	};

	//-----------------------------------------------------------------------------
	class ADelayTestFactory : public ITestFactory, public FObject
	{
	public:
		//--ITestFactory
		tresult PLUGIN_API createTests(FUnknown* context, ITestSuite* parentSuite) SMTG_OVERRIDE;

		static FUnknown* createInstance(void*) { return (ITestFactory*)new ADelayTestFactory(); }

		static FUID cid;

		OBJ_METHODS(ADelayTestFactory, FObject)
			DEF_INTERFACES_1(ITestFactory, FObject)
			REFCOUNT_METHODS(FObject)
	};
}
}
#endif