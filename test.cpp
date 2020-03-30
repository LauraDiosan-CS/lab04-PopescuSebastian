#include "repo.h"
#include "entity.h"
#include "controller.h"
#include <iostream>
#include <assert.h>
#include <string.h>

void testRepo() {
	Repo entities;
	char* name1 = new char[15];
	char* name2 = new char[15];
	char* name3 = new char[15];
	char* name4 = new char[15];
	char* name5 = new char[15];
	date d1(1, 2, 3);
	date d2(2, 3, 4);
	date d3(3, 4, 5);
	date d4(4, 5, 6);
	date d5(5, 6, 7);
	date d6(0, 0, 0);

	strcpy_s(name1, sizeof "aaa", "aaa");
	strcpy_s(name2, sizeof "bbb", "bbb");
	strcpy_s(name3, sizeof "ccc", "ccc");
	strcpy_s(name4, sizeof "aaa", "aaa");
	strcpy_s(name5, sizeof "bbb", "bbb");

	Product e1(name1, d1, 5), e2(name2, d2, 6), e3(name3, d3, 7), e4(name4, d4, 8), e5(name5, d5, 9);
	Product a1, a2, a3, a4, a5;
	entities.addEntity(e1);
	entities.addEntity(e2);
	entities.addEntity(e3);
	entities.addEntity(e4);
	entities.addEntity(e5);

	assert(entities.getSize() == 5);
	a1 = entities.getElem(0);
	assert(a1 == e1);

	///////////////////////////////////////////////
	
	Product e6(name1, d2, 8), e7(name1, d6, 0), e8(name3, d4, 9);
	entities.updateEntity(e6);
	a1 = entities.getElem(0);
	assert(e6 == a1);
	entities.deleteEntity(e7);
	assert(entities.getSize() == 3);
	assert(entities.getElem(0) == e2);
	assert(entities.getElem(1) == e3);
	assert(entities.getElem(2) == e5);
	entities.updateEntity(e8);
	a3 = entities.getElem(1);
	assert(e8 == a3);
	
}

void testEntity() {
	Product();
	char* name1 = new char[15];
	char* name2 = new char[15];
	char* name3 = new char[15];
	char* name4 = new char[15];
	char* name5 = new char[15];

	strcpy_s(name1, sizeof "aaa", "aaa");
	strcpy_s(name2, sizeof "bbb", "bbb");
	strcpy_s(name3, sizeof "ccc", "ccc");
	strcpy_s(name4, sizeof "aaa", "aaa");
	strcpy_s(name5, sizeof "bbb", "bbb");

	date d1(1, 2, 3);
	date d2(2, 3, 4);
	date d3(3, 4, 5);
	date d4(4, 5, 6);
	date d5(5, 6, 7);

	Product e1(name1, d1, 5), e2(name2, d2, 6), e3(name3, d3, 7), e4(name4, d1, 5), e5(name5, d2, 6);

	assert(e1 == e4);
	assert(e2 == e5);
	e3 = e4;
	assert(e3 == e4);
	e3.setName(name5);
	e3.setStock_refill(d2);
	e3.setPrice(6);
	assert(e3 == e5);
}

void testController() {
	Repo entities;
	char* name1 = new char[15];
	char* name2 = new char[15];
	char* name3 = new char[15];
	char* name4 = new char[15];
	char* name5 = new char[15];
	date d1(1, 2, 3);
	date d2(2, 3, 4);
	date d3(3, 4, 5);
	date d4(4, 5, 6);
	date d5(5, 6, 7);
	date d6(0, 0, 0);

	strcpy_s(name1, sizeof "aaa", "aaa");
	strcpy_s(name2, sizeof "bbb", "bbb");
	strcpy_s(name3, sizeof "ccc", "ccc");
	strcpy_s(name4, sizeof "aaa", "aaa");
	strcpy_s(name5, sizeof "bbb", "bbb");

	Product e1(name1, d1, 5), e2(name2, d2, 6), e3(name3, d3, 7), e4(name4, d4, 8), e5(name5, d5, 9);
	Product a1(name3, d4, 10), a2(name4, d4, 8);
	entities.addEntity(e1);
	entities.addEntity(e2);
	entities.addEntity(e3);
	entities.addEntity(e4);
	entities.addEntity(e5);
	Controller ctrl;
	ctrl.addProduct(name1, d1, 5);
	ctrl.addProduct(name2, d2, 6);
	ctrl.addProduct(name3, d3, 7);
	ctrl.addProduct(name4, d4, 8);
	ctrl.addProduct(name5, d5, 9);
	assert(ctrl.getSize() == 5);
	ctrl.updateProduct(name3, d4, 10);
	assert(ctrl.getElem(2) == a1);
	ctrl.deleteProduct(name3);
	assert(ctrl.getSize() == 4);
	assert(ctrl.getElem(2) == a2);
}

void runTests() {
	testRepo();
	std::cout << "Repo tests passed!\n";
	testEntity();
	std::cout << "Entity tests passed!\n";
	testController();
	std::cout << "Controller tests passed\n All tests have passed!\n";
}