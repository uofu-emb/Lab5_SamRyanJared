# Lab5_SamRyanJared

Activity-1: Determining Time Drift
    Jitter = -43.939 Hz (we took the smaller diff, that is the max jitter)
        min freq = 455.787 Hz
        max freq = 456.061 Hz
        expected = 500 Hz (1ms toggle on and off)
        Freq diff = min: 43.939 Hz  max: 44.213 Hz
        T(Periood): Tmin - 2.192ms  Tmax - 2.194ms  Tmean - 2.193ms

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


