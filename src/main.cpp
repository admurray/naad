#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include "tone.hpp"

void write_sample(std::ostream &stream, double sample);



int main()
{
    constexpr double SAMPLE_RATE = 44100;
    std::vector<Tone> tones;

    // Each of these represents a final octave difference from A4
    const double major_notes[] = {16.35, 18.35, 20.60, 21.83, 24.50, 27.50, 30.87};
    const double octaves[] = { -2, 0, 4./12, 7./12, 1, 16./12, 19./12 };
    const size_t count = sizeof(octaves) / sizeof(*octaves);



    std::ofstream outfile("out", std::ofstream::binary);

    // Create a tone generator for each
    for (size_t i = 0; i < count; i++)
    {
        tones.push_back(Tone(SAMPLE_RATE));
    }

    // Set parameters for the output sound
    double duration = 1.0;
    double attack = 1.0;
    double decay = 2.5;
    double amplitude = 1.0;

    // Generate the required samples
    double totalSample = 0;
    for(int j = 0; j < sizeof(major_notes)/sizeof(double); j++){
    	for (double t = 0; t < duration; t += 1 / SAMPLE_RATE)
    	{
			// Interpolate with sinusoidal easing up to the attack time, then constant
			double interp = 1;//t >= attack ? 1 : sin(M_PI/2 * t);

			// Constant until the decay time, then interpolate linearly out
			double strength = 1;// t < (duration - decay) ? 1
			  //  : 1 - (t - (duration - decay)) / decay;

			// Superimpose the samples from each tone generator
			for (size_t i = 0; i < count; i++)
			{
				//double octave = interp * octaves[i];
				double frequency = major_notes[j] * pow(2, 3);
				//printf("%f ", frequency);
				//double frequency = 440 * pow(2, octave);
				double sample = tones[i].nextSample(frequency, strength * amplitude);
				totalSample += sample;
			}
			totalSample /= count;
			if (outfile.good())
			{
				write_sample(outfile, totalSample);
			}
			else
			{
				return 1;
			}
    	}
    }

    return 0;
}

// Writes a sample to the given output stream as a 16-bit signed integer.
void write_sample(std::ostream &stream, double sample)
{
    int16_t output = (int16_t) (0x7FFF * sample);
    stream.write((char *) &output, sizeof(int16_t) / sizeof(char));
}
