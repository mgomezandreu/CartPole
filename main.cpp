#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "Cartpole.cpp"
#include "Controller.cpp"
#include "Visualisation.cpp"

#define USE_CONTROLLER true // select between using and not using controller with preprocessor macros


int main()
{   
    // Setup Dynamics Simulator and Visualisation
    Visualisation vis(1000,800, 20, 10, 2);
    Cartpole sim(10,10, 1);

    // Setup PID Controller for stabilization around upright position (theta = PI)
    Vector2d s_des(0, M_PI);
    Vector2d ds_des(0,0);

    MatrixXd Kp{
        {10, 1000},
        {0, 0}
    };

    MatrixXd Kd{
        {30, 50},
        {0, 0}
    };

    MatrixXd Ki{
        {0,3},
        {0,0}
    };
    
    Controller control(Kp, Kd, Ki,s_des, ds_des);

    double t = 0;
    double dt = 0.001;

    while (vis.is_running())
    {
        
        Vector2d u(0,0);
        if(USE_CONTROLLER) // If controller is activated, query controller to get control signal
            u = control.get_u(sim.get_s(), sim.get_ds());
        sim.simulation_step(u(0),dt);
        sleep(dt);
        t += dt;

        // Update Visualisation
        vis.update(sim.get_s());
        vis.check_close();
    }

    return 0;
}
