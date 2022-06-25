#include <reservoir.hpp>

Reservoir::Reservoir()
{
	_top_radius = TOP_RADIUS;
	_bottom_radius = BOTTOM_RADIUS;
	_height = HEIGHT;
	_water_level = 5;
	set_alpha();
}

Reservoir::Reservoir(double top_radius, double bottom_radius, double height, double water_level = -1)
{
	_top_radius = top_radius > 0 ? top_radius : TOP_RADIUS;
	_bottom_radius = bottom_radius > 0 ? bottom_radius : BOTTOM_RADIUS;
	_height = height > 0 ? height : HEIGHT;
	_water_level = water_level > 0 ? (water_level > height ? height : water_level) : height * 0.5;
	set_alpha();
}

Reservoir::~Reservoir() {}

void Reservoir::set_alpha()
{
	_alpha = (_top_radius - _bottom_radius) / _height;
	set_delta_water_level();
}

void Reservoir::override_water_level(double water_level) { _water_level = water_level < 0 ? 0 : water_level; }

void Reservoir::set_delta_water_level()
{
	_delta_water_level = -(_flush_coeficient * sqrt(_height));
	_delta_water_level += _flow_in;
	_delta_water_level /= M_PI * pow(_bottom_radius + _alpha * _water_level, 2);
}

void Reservoir::set_top_radius(double top_radius)
{
	_top_radius = top_radius > 0 ? top_radius : TOP_RADIUS;
	set_alpha();
}

void Reservoir::set_bottom_radius(double bottom_radius)
{
	_bottom_radius = bottom_radius > 0 ? bottom_radius : BOTTOM_RADIUS;
	set_alpha();
}

void Reservoir::set_height(double height)
{
	_height = height > 0 ? height : HEIGHT;
	set_alpha();
}

void Reservoir::set_water_level(double water_level)
{
	_water_level = water_level > 0 ? (water_level > _height ? _height : water_level) : _height * 0.5;
}

void Reservoir::set_flow_in(double flow_in) { _flow_in = flow_in < 0 ? 0 : flow_in; }

void Reservoir::set_flow_out(double flow_out) { _flow_out = flow_out < 0 ? 0 : flow_out; }

void Reservoir::next_second()
{
	_time++;

	_prev_delta_water_level = _delta_water_level;

	override_water_level(_water_level + _delta_water_level);

	set_delta_water_level();
}

void Reservoir::prev_second()
{
	if (_time == 0)
		return;
	_time--;

	_delta_water_level = _prev_delta_water_level;

	override_water_level(_water_level - _delta_water_level);

	set_delta_water_level();
}