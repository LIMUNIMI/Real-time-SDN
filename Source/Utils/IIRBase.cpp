#include "IIRBase.h"

IIRBase::IIRBase()
{
	//b0 = 0; 
	//b1 = 0; 
	//b2 = 0;
	//a1 = 0; 
	//a2 = 0;

	//buffer1 = 0;
	//buffer2 = 0;

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
	//inAcc -= a1 * buffer1;
	//inAcc -= a2 * buffer2;

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

	//sample = inAcc * b0;
	//sample += b1 * buffer1;
	//sample += b2 * buffer2;

	/*buffer2 = buffer1;
	buffer1 = inAcc;*/


}

