#include	<memory>
#include	<stdio.h>
#include	"ray_tracer.h"

int main()
{
	Camera camera(glm::vec3(0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0), 60, 1920, 1080);

	std::unique_ptr<Scene> scene = std::make_unique<Scene>();

	Sphere* s1 = new Sphere(glm::vec3(0, 1, 8), 1.5f);
	Sphere* s2 = new Sphere(glm::vec3(-3, 0, 8), 1.0f);
	Sphere* s3 = new Sphere(glm::vec3(4, 1, 10), 2.0f);
	Sphere* s4 = new Sphere(glm::vec3(-4, 3, 15), 4.0f);
	Plane* p1 = new Plane(glm::vec3(0, 1, 0), 1);
	PointLight* l1 = new PointLight(glm::vec3(-3, 8, -10), glm::vec3(1));

	s1->defSurface.ka = 0.2;
	s1->defSurface.kd = 0.5;
	s1->defSurface.ks = 0.6;
	s1->defSurface.kt = 0;
	s1->defSurface.p = 100;
	s1->defSurface.kr = 0.3;
	s1->defSurface.color = glm::vec3(0.7, 0.3, 0.2);
	s1->defSurface.medium = glass;

	s2->defSurface = s1->defSurface;
	s2->defSurface.p = 60;
	s2->defSurface.color = glm::vec3(0.7, 0.5, 0.1);
	s2->defSurface.kr = 0.3;

	s3->defSurface = s1->defSurface;
	s3->defSurface.p = 90;
	s3->defSurface.color = glm::vec3(0.5, 0.2, 0.8);
	s3->defSurface.kr = 0.5;

	s4->defSurface = s1->defSurface;
	s4->defSurface.p = 50;
	s1->defSurface.ka = 0.7;
	s4->defSurface.color = glm::vec3(0.6, 0.4, 0.3);
	s4->defSurface.kr = 0.6;

	p1->defSurface = s1->defSurface;
	p1->defSurface.ka = 0.1;
	p1->defSurface.ks = 0.4;
	p1->defSurface.kd = 0.5;
	p1->defSurface.kr = 0.4;
	p1->defSurface.color = glm::vec3(0.1, 0.2, 0.7);

	scene->addObject(s1);
	scene->addObject(s2);
	scene->addObject(s3);
	scene->addObject(s4);
	scene->addObject(p1);
	scene->addLight(l1);

	camera.traceFrame("test-1.tga");

	return 0;
}
