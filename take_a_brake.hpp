#ifndef TAKE_A_BRAKE_H
#define TAKE_A_BRAKE_H



#include <iostream>



    struct SpeedUpdate {
        double veloctiy_mps;
    };

    struct CarDetected {
        double distance_m;
        double velocity_mps;
    };

    struct BrakeCommand {
        double time_to_collision_s;
    };

    /* Publish Method*/

    struct ServiceBus {
        void publish(const BrakeCommand&);
    };

    template <typename T>
    struct AutoBrake {
        AutoBrake(const T& publish);
        void observe(const SpeedUpdate&);
        void observe(const CarDetected&);
    private:
        const T& publish;

    };

    


#endif