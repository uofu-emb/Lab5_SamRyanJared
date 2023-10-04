# Lab-5: Real Time ECE-5960/6960

    Activity-1: Determining Time Drift

        Jitter = 2.19 ms (we took the smaller diff, that is the max jitter)
            min freq = 455.787 Hz
            max freq = 456.061 Hz
            expected = 500 Hz (1ms toggle on and off)
            Freq diff = min: 43.939 Hz  max: 44.213 Hz
            T(Periood): Tmin - 2.192ms  Tmax - 2.194ms  Tmean - 2.193ms

        Jitter @ different delays
            1 s delay:
                F_mean = 358.608 Hz
                F_ideal = 400 Hz
                Jitter = -41.392 Hz
            500ms delay:
                F_mean = 313.812 Hz
                F_ideal = 333.333 Hz
                Jitter = 19.521 Hz
        Jitter of Agilent Function Generator
            @ 2ms period, 500 Hz, 2.9v peak to peak, duty cycle 58.8%
            F_mean = 499.992 Hz
            F_ideal = 500 Hz
            Jitter = 0.008 Hz = 8mHz

            @ 2.50ms period, 400 Hz, 2.9v peak to peak, duty cycle 58.8%
            F_mean = 399.992 Hz
            F_ideal = 400 Hz
            Jitter = 0.008 Hz = 8mHz

            @ 3ms period, 333.333 Hz, 2.9v peak to peak, duty cycle 58.8%
            F_mean =  333.326 Hz
            F_ideal = 333.333 Hz
            Jitter =  0.007 Hz = 7mHz


        Formula for drift
            drift (s) = Measured - Ideal
            Measured(time lapse) = (# oscillations / hour) * Tmean

            3600s / 2ms = 1,800,000 oscillations per hour (based on oscialltion period of 2ms)
            Measured(Time Lapse) = 1,800,000 * 2.193ms
            Measured(Time Lapse) = 3947.40 seconds

            drift = (3947.40 - 3600) s
            drift = 347.4 s
                = 5.79 min
            drift = 5.79 min for 1-hour period of time.


    ------------------------------------------------------------------------------------
        Activity-2: Determining Latency of Interrupt Handler

        Delay between sync signal and board ouput:
        Latency using message queue:


