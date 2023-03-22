#include "IIRBase.h"

IIRBase::IIRBase()
{
	sampleRate = 0;
	a = nullptr;
	b = nullptr;
}

void IIRBase::init(double samplerate, std::vector<double>* a, std::vector<double>* b)
{
	sampleRate = samplerate;

	memory = std::vector<double>(std::max(a->size(), b->size()) - 1, 0.0f);

	this->a = a;
	this->b = b;
}

void IIRBase::process(float& sample)
{
	double inAcc, out;

	inAcc = sample * a->at(0);

	for (int i = 1; i < a->size(); i++)
	{
		inAcc -= a->at(i) * memory[i - 1];
	}

	out = inAcc * b->at(0);

	for (int i = 1; i < b->size(); i++)
	{
		out += b->at(i) * memory[i - 1];
	}
	sample = out;

	for (int i = memory.size() - 1; i >= 1; i--)
	{
		memory[i] = memory[i - 1];
	}

	memory[0] = inAcc;

}

