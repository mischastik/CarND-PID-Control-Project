#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	sum_cte = 0;
	previous_cte = -1;
}

void PID::UpdateError(double cte) 
{
	if (previous_cte < 0)
	{
		previous_cte = cte;
	}
	double diff_cte = cte - previous_cte;
	sum_cte += cte;
	p_error = Kp * cte;
	d_error = Kd * diff_cte;
	i_error = Ki * sum_cte;
	previous_cte = cte;
}

double PID::TotalError() 
{
	return p_error + d_error + i_error;
}

