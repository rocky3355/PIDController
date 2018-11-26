# PID Controller

The task of this project was to drive a car through a race track, only knowing the cross track error (meaning the lateral deviation of the car with repsect to the track's center line). The PID controller is a very simple type of controller, the implementation is straight forward. The more interesting part is the parameter tuning, which can be a bit tricky. I tried to use the Twiddle algorithm, but it actually expects that you can test a scenario by yourself to see the "new" output with changed parameters. But for this project, I only can use the data provided by the simulator, I can't tell him to replay i.e. the last action or something like this. Thus I decided to tune the parameters manually. The car stays on the track with these parameters, but it drives a bit jerky, especially in sharp curves. I tried to lower P and increase I for a more smooth driving. But the integral part was either to slow or it became too dominating. I think the main problem is that for sharp curves, the cross track error suddenly changes dramtically, thus a high P is required to be able to react fast to it and the integral part would not be able to catch up.
