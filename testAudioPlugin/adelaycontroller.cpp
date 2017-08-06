///
///	I'm building this based on the adelay controller available in the adelay sample code for vst3.
///

//in project
#include "adelaycontroller.h"
#include "adelayids.h"

//external (To get these to work you need to right click the project, go to properties then c++. In general find the additional header files stuff and add the directory.)
//		   (For actual libraries it's similar, but you do it in linker. Also you need to go to input and link the actual files!)
//		   (More detailed information can be found at https://stackoverflow.com/questions/4445418/how-do-i-add-additional-libraries-in-c
//																																								Good luck..
#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/ibstream.h"

//Likely un-necesary, but this is precompiler stuff. Basically it's a switch to turn on at compile time. In this case it adds a new library for IOS devices.
#if TARGET_OS_IPHONE
#include "interappaudio/iosEditor.h"
#endif

namespace TofuPop{
namespace Vst {

//Currently I don't understand this tresult. It must be a type of some library/header that I haven't written yet. 
//I imagine ADelayController is a type defined in the adelaycontroller.h file.
tresult PLUGIN_API ADelayController::initialize(FUnknown* context)
{
	tresult result = EditController::initialize(context);
	if (result == kResultTrue)
	{
		//oddly enough none of this is erroring out, however I'm not really sure what any of this is. I imagine STR16 is a 16 bit string. That's all I got for now. (never mind it errored.)
		//needs more exploration! I imagine as I keep coding this I will find some answers!
		parameters.addParameter(STR16("Bypass"), 0, 1, 0, ParameterInfo::kCanAutomate | ParameterInfo::kIsBypass, kBypassId);

		parameters.addParameter(STR16("Delay"), STR16("sec"), 0, 1, ParameterInfo::kCanAutomate, kDelayID); //I imagine the kDelayID stuff comes from adelayids.h
	}
	return kResultTrue; //idk...
}

//I'll likely cut this code out. I don't have any intention of writing code for IOS on TofuPop.
#if Target_OS_IPHONE
IPlugView* Plugin_API ADelayController::createView(FIDString name)
{
	if (strcmp(name, ViewType::kEditor) == 0)
	{
		return new ADelayEditorForIOS(this);
	}
	return 0;
}

#endif

//IOS code end

//

}

}

