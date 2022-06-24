#include "atr_include.hpp"

class Reservoir
{
private:
    double _top_radius;
    double _bottom_radius;
    double _height;
    double _alpha;

    double _water_level = 0;
    double _flow_in = 0;
    double _flow_out = 0;

    double _delta_water_level = 0;
    double _prev_delta_water_level = 0;
    double _flush_coeficient = 1;

    uint32_t _time = 0;

    void set_alpha();
    void set_delta_water_level();
    void override_water_level(double);
public:
    Reservoir();
    Reservoir(double, double, double, double);
    ~Reservoir();

    const double& top_radius() {return _top_radius;};
    const double& bottom_radius() {return _bottom_radius;};
    const double& height() {return _height;};
    const double& aplha() {return _alpha;};
    void set_top_radius(double);
    void set_bottom_radius(double);
    void set_height(double);

    const double& water_level() {return _water_level;};
    const double& flow_in() {return _flow_in;};
    const double& flow_out() {return _flow_out;};
    void set_water_level(double);
    void set_flow_in(double);
    void set_flow_out(double);

    const uint32_t& time() {return _time;};

    void next_second();
    void prev_second();
};
