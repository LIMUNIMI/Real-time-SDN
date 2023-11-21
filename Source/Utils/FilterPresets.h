#pragma once

namespace FilterPresets 
{
	constexpr int NUM_PRESETS = 12;
	constexpr char* PRESETS_NAMES[NUM_PRESETS] = 
	{
		"Marble floor",
		"Concrete, tough",
		"Steel",
		"Glass, ordinary window",
		"Hairy carpet on 3 mm felt",
		"Hardwood, mahogany",
		"Clinker concrete (no surface finish)",
		"Cotton carpet",
		"Studio curtains, 22 cm from wall",
		"Acoustic timber wall panelling",
		"Fiberglass board (25mm thick)",
		"Snow, freshly fallen, 4 in thick"
	};
	constexpr float PRESETS_VALUES[NUM_PRESETS][8] =
	{
		{0.01, 0.01, 0.01, 0.02, 0.02, 0.02, 0.02, 0.02},
		{0.01, 0.02, 0.04, 0.06, 0.08, 0.1,  0.1,  0.1},
		{0.05, 0.1, 0.1, 0.1, 0.07, 0.02, 0.02, 0.02},
		{0.35, 0.25, 0.18, 0.12,  0.07, 0.04, 0.04, 0.04},
		{0.11, 0.14, 0.37, 0.43, 0.27, 0.25, 0.25, 0.25},
		{0.19, 0.23, 0.25, 0.3, 0.37, 0.42, 0.42, 0.42},
		{0.1, 0.2, 0.4, 0.6, 0.5, 0.6, 0.6, 0.6},
		{0.07, 0.31, 0.49, 0.81, 0.66, 0.54, 0.54, 0.54},
		{0.36, 0.26, 0.51, 0.45, 0.62, 0.76, 0.76, 0.76},
		{0.18, 0.34, 0.42, 0.59, 0.83, 0.68, 0.68, 0.68},
		{0.06, 0.2, 0.65, 0.9, 0.95, 0.98, 0.98, 0.98},
		{0.45, 0.75, 0.9, 0.95, 0.95, 0.95, 0.95, 0.95}
	};
}