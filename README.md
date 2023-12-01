ECE-5960: Lab-5 : Realtime Systems (Jared, Sam, Ryan)

Section-1: Jitter & Time Drift
--------------------------------------------
	-Jitter: Deviation from an ideal signal whether its slower of faster on the edge crossings.
	-Caused by: 
		-System Phenomena (on physcial board)
		-Data-dependent phenomena (ex-duty cycle distortion)
		-Random noise (thermal, shot, "pink" frequency)
	-Period on cycle-cycle jitter

	Codespaces
	--------------
	-sleep.c
		-no additional delay added:
				ideal:		measured:
		Period:		2 ms		2.193 ms
		Frequency:	500 Hz		456.1 Hz
		Pulse-Width:			1.096 ms

		Jitter: +0.193ms, -3.9Hz		


		-1200µs delay added(using k_busy_wait):
				ideal:		measured:
		Period:		4.40 ms		4.582 ms
		Frequency:	227.27 Hz	218.2 Hz
		Pulse-Width:			2.290 ms

		Jitter: +0.183ms, -9.07Hz


		-2500µs delay added(using k_busy_wait):
				ideal:		measured:
		Period:		7.00 ms		7.172 ms
		Frequency:	142.86 Hz	139.4 Hz
		Pulse-Width:			3.586 ms

		Jitter: +0.172ms, -3.46Hz

	Formula for drift:
            drift (s) = Measured - Ideal
            Measured(time lapse) = (# oscillations / hour) * Tmean

            3600s / 2ms = 1,800,000 oscillations per hour (based on oscialltion period of 2ms)
            Measured(Time Lapse) = 1,800,000 * 2.193ms
            Measured(Time Lapse) = 3947.40 seconds

            drift = (3947.40 - 3600) s
            drift = 347.4 s
                   = 5.79 min
            drift = +5.79 min for 1-hour period of time.


	-kernel.c
		-no additional delay added:
				ideal:		measured:
		Period:		2 ms		1.994 ms
		Frequency:	500 Hz		501.5 Hz
		Pulse-Width:			997 µs
		
		Jitter: -0.006ms, +1.50Hz

		-1200µs delay added(using k_busy_wait before timer start):
				ideal:		measured:
		Period:		4.40 ms		4.384 ms
		Frequency:	227.27 Hz	228.2 Hz
		Pulse-Width:			2.191 ms
		
		Jitter: -0.016ms, +0.93Hz

		-2500µs delay added(using k_busy_wait before timeer start):
				ideal:		measured:
		Period:		7.00 ms		6.972 ms
		Frequency:	142.86 Hz	143.4 Hz
		Pulse-Width:			3.487 ms

		Jitter: -0.028ms, +0.54Hz

		-500µs delay added(using k_busy_wait after timer start):
				measured:
		Period:		1.995 ms	Notes: waveform did not change much from 1ms timer usage
		Frequency:	501.3 Hz
		Pulse-Width:	998   µs

		Jitter: -0.005ms, +1.30Hz

		-6500µs delay added(using k_busy_wait after timer start):
				measured:
		Period:		7.035 ms	Notes: waveform changed significantly with increase past timer of 
		Frequency:	142.2 Hz	       1ms intervals.
		Pulse-Width:	3.515 ms

	Formula for drift:
            drift (s) = Measured - Ideal
            Measured(time lapse) = (# oscillations / hour) * Tmean

            3600s / 2ms = 1,800,000 oscillations per hour (based on oscialltion period of 2ms)
            Measured(Time Lapse) = 1,800,000 * 1.994ms
            Measured(Time Lapse) = 3589.20 seconds

            drift = (3589.20 - 3600) s
            drift = -10.80 s
            drift = -10.80 s for 1-hour period of time.



	-rtc.c (realtime clock)
		-uses interrupt handler with realtime clock provided by zephyr

		-no additional delay added:
				ideal:		measured:
		Period:		2 ms		3.074 ms
		Frequency:	500 Hz		325.2 Hz
		Pulse-Width:			1.537 ms

		Jitter: +1.074ms, -174.80Hz

		-500µs delay added(using k_busy_wait after toggle in interrupt handler):
				ideal:		measured:
		Period:		2 ms		3.078 ms
		Frequency:	500.0 Hz	325.0 Hz
		Pulse-Width:			1.538 ms

		Jitter: +1.078ms, -175.0Hz
		
		-1000µs delay added(using k_busy_wait after toggle in interrupt handler):
			-Above 1000 using home scope flatlines the signal (due to scope compensation)


	Formula for drift:
            drift (s) = Measured - Ideal
            Measured(time lapse) = (# oscillations / hour) * Tmean

            3600s / 2ms = 1,800,000 oscillations per hour (based on oscialltion period of 2ms)
            Measured(Time Lapse) = 1,800,000 * 3.074ms
            Measured(Time Lapse) = 5533.20 seconds

            drift = (5533.20 - 3600) s
            drift = 1933.20 s
                   = 32.22 min
            drift = +32.22 min for 1-hour period of time.

	-busy.c
		-could not perform upload, used sleep env
		-Similar to sleep with change of using k_busy_wait instead of sleep.

		-1000µs delay used:
				ideal:		measured:
		Period:		2 ms		1.999 ms
		Frequency:	500 Hz		500.3 Hz
		Pulse-Width:			999.7 µs

		Jitter: -0.001ms, +0.03Hz

		-1500µs delay used:
				ideal:		measured:
		Period:		3 ms		2.997 ms
		Frequency:	333.33 Hz	333.6 Hz
		Pulse-Width:			1.498 ms

		Jitter: -0.003ms, +0.27Hz
		
		-2500µs delay used:
				ideal:		measured:
		Period:		5 ms		4.988 ms
		Frequency:	200.0 Hz	200.3 Hz
		Pulse-Width:			2.492 ms

		Jitter: -0.012ms, +0.03Hz

	Formula for drift:
            drift (s) = Measured - Ideal
            Measured(time lapse) = (# oscillations / hour) * Tmean

            3600s / 2ms = 1,800,000 oscillations per hour (based on oscialltion period of 2ms)
            Measured(Time Lapse) = 1,800,000 * 1.999ms
            Measured(Time Lapse) = 3947.40 seconds

            drift = (3598.20 - 3600) s
            drift = -1.80 s
            drift = -1.80 s for 1-hour period of time.


Section-2: Measuring Latency of interrupt handler
--------------------------------------------
	-gpio_interrupt.c
		-Using signal generator to drive the board using Pin A1 with measure from pin A0
		-Unmodified code:
			-Delay between sync signal(1kHz) and output from board:
				Delay: -8.712 µs
		-Increaese delay in code using busy_wait loop before toggle
			-k_busy_wait(500) increase by 500µs for toggle delay
				-Delay: +498.834µs
			-k_busy_wait(900) increase by 900µs for toggle delay
				-Delay: +927.36µs
			-k_busy_wait(1000) increase by 1000µs for toggle delay
				-Delay: imeasurable, signal no jumps around too much for delay capture/measurement


Section-3: Modify interrupt handler by adding in message queue
--------------------------------------------
	-gpio_interrupt.c
		-Adding message queue to send message with toggle
			-Delay between sync signal(500 Hz)
				-Delay: -27.144 µs --3 times larger compared to interrupt without message queue
		-Increaese delay in code using busy_wait loop before toggle
			-k_busy_wait(500) increase by 500µs for toggle delay
				-Delay: -528.426 µs




	
