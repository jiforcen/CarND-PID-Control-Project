#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	PID::p_error = 0;
	PID::i_error = 0;
	PID::d_error = 0;
  
    first_cycle = true;
}

void PID::UpdateError(double cte) {

    if (first_cycle) 
    {
        p_error = cte;
        first_cycle = false;
    }

    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    
}

double PID::TotalError() {
    return (-(PID::Kp * PID::p_error) - (PID::Kd * PID::d_error) - (PID::Ki * PID::i_error));
}

