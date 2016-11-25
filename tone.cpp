#include <cmath>
#include "tone.hpp"

Tone::Tone(double sampleRate) : sampleRate(sampleRate), s(0), lastSample(0)
{
}

double Tone::getSample() const
{
      return this->lastSample;
}

double Tone::nextSample(double frequency, double amplitude)
{
      this->s += frequency / this->sampleRate;
          this->lastSample = amplitude * sin(2*M_PI * this->s);
              return this->lastSample;
}
