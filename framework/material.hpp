#ifndef BUW_MATERIAL_HPP
#define BUW_MATERISL_HPP
#include <iostream>
#include <string>


struct Material{

	std::string name_;
	Color ka_;
	Color kd_;
	Color ks_;
	float m_;


	Material():
	name_{"Default"},
	ka_{0.0f, 0.0f, 0.0f},
	kd_{0.0f, 0.0f, 0.0f},
	ks_{0.0f, 0.0f, 0.0f},
	m_{0.0f}{}

	Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m):
	name_{name},
	ka_{ka},
	kd_{kd},
	ks_{ks},
	m_{m}{}

	
	friend std::ostream& operator<<(std::ostream& os, Material const& m){

		os << "name: " << m.name_ << std::endl
		<< "ka: " <<m.ka_ << std::endl
		<< "kd: " <<m.kd_ << std::endl
		<< "ks: " <<m.ks_ << std::endl
		<< "m " <<m.m_ << std::endl;

		return os;
	}

};


#endif