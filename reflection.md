# PID class

The PID class is rather straight forward, it's mostly identical to the sample code in the lessons.

# Usage of PID controlers

In this project I use two separate PID controllers: One for steering and one for throttle.

# Parameter tuning

Parameter tuning turned out to be rather tricky. The throttle PID is simple: In this case bias is not an issue and oscillation 
doesn't matter as inertia filters out the oscillations in throttle anyway.
The throttle PID tries to maintain a target speed. The target speed is dependent on the CTE. If the CTE is low, the car can drive 
faster bit it slows down with growing CTE so that the PID has more time to correct the steering for instance in sharp turns.

For the steering PID, I started with a small bias correction (Ki), left Kd at zero and optimized Kp so that I had the impression that 
it was able to react fast enough to cope with sharp corners. This of course gave me a lot of oscillation so I gradually increased the
Kd parameter until the oscillation was reduced sufficiently. This eventually lead to smooth ride around the whole lap.
