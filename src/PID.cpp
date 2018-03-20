#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	sum_cte = 0;
	previous_cte = 0;
	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte) 
{

	double diff_cte = cte - previous_cte;
	sum_cte += cte;

	p_error = cte;
	d_error = diff_cte;
	i_error = sum_cte;

	previous_cte = cte;
}

double PID::TotalError() 
{
	return Kp * p_error + Kd * d_error + Ki * i_error;
}

