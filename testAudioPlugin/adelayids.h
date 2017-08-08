// Woooo here we go! 
// For here on out all Steinberg comments will be marked like this [Stein]. Cool? Cool.
#pragma once

namespace TofuPop
{
namespace Vst
{
	//parameter tags [Stein]
	enum {
		kDelayId = 100, // I think this will make up for like 90 percent of my woes in adelaycontroller.h and adelaycontroller.cpp.
		kBypassId = 101,// Same with this.
	};
	
	//unique class ids [Stein]
	static const Steinberg::FUID ADelayProcessorUID (0x0CDBB669, 0x85D548A9, 0xBFD83719, 0x09D24BB3); 
	static const Steinberg::FUID ADelayControllerUID(0x038E7FA9, 0x629A4EAA, 0x8541B889, 0x18E8952C);
	// okiedoke so here's the deal on this stuff ^. FUID are basically just Unique IDs, the F is specific for steinberg. I've read that the normal MSVC (Windows) utility can create
	//useable ones. However, the FUID class ought to have a generate method in it somewhere. Just checked it does.

	//We will need to worry about FUID later.
}
}
