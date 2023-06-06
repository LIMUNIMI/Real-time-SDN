# Real-time-SDN
Scattering Delay Networks reverb plugin considering walls absorption.

## Exposed parameters
The plugin exposes the following parameters:
* Source level (dB)
* Source position (3 x 0-1 normalized values)
* Listener position (3 x 0-1 normalized values)
* Listener rotation (3 x 0-360 degrees)
* Output mode (mono, stereo, ACN Ambisonics 1st-5th order)
* Room dimensions (3 x 1-100 meters)
* Wall absorption coefficients (8 x 0-1 absorption coefficients per wall)
* Line-of-sight component (on/off)

## Main classes
* ```Room```: The main class representing the simulation 
* ```Node```: Parent class for all the moving objects in the simulation
* ```Source```: Implements the sound origin 
* ```Receiver```: Models the listener and communicates with the Microphone class
* ```Microphone```: virtual class used as a parent for all the classes implementing the supported output types
* ```ScatteringNode```: Characterizes the first-order reflection’s point of contact with the room walls. Also manages the filtering of the signal
* ```WaveGuide```: Controls the sound propagation in the system. It should be noted that the single instance of this class is mono-directional

## Other tech-specs
Some other info about the plugin:
* Y-up left-handed coordinates system
* Shoebox geometry
* Only one omnidirectional source and one listener
* Multi-channel inputs are treated as mono (input channels are summed up)

## Dependencies
* [JUCE](https://juce.com/)
* [Eigen](https://eigen.tuxfamily.org/)
* [Armadillo](https://arma.sourceforge.net/)

## References
This work is based on the following publications:
> Fontana, M. (2023). Scattering delay networks for real time audio in augmented reality. Master thesis. Università degli Studi di Milano. Milan.

> De Sena, E., Hacihabiboglu, H., & Cvetkovic, Z. (2011, February). Scattering delay network: An interactive reverberator for computer games. In Audio Engineering Society Conference: 41st International Conference: Audio for Games. Audio Engineering Society.

> De Sena, E., Hacιhabiboğlu, H., Cvetković, Z., & Smith, J. O. (2015). Efficient synthesis of room acoustics via scattering delay networks. IEEE/ACM Transactions on Audio, Speech, and Language Processing, 23(9), 1478-1492.

