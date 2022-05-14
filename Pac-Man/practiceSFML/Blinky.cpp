#include "Blinky.h"
#include"ChaseAggressive.h"
#include"ChaseRandom.h"
#include"FrightenedWandering.h"
#include"FrightenedEaten.h"
#include"ScatterTopLeft.h"
#include"ScatterTopRight.h"
#include"ScatterDownLeft.h"
#include"ScatterDownRight.h"
#include<iostream>

Blinky::Blinky(int x,int y):Ghost(x,y)
{
	this->speed = 2;
	this->chaseBehaviour = new ChaseAggressive(this);
	this->frightenedBehaviour = NULL;
	this->scatterBehaviour = NULL;
	waiting = false;
	timeMode = clock();
}

Blinky::~Blinky()
{
	freePointer();
}

void Blinky::update()
{
	if (getTime(lastTime) > 8 && waiting)
		waiting = false;
	
	animate();
	Move();
}

void Blinky::Move()
{	
	
	if (getTime(timeMode) > 15 && chaseMode) {
		setScatterMode();
	}
	if (getTime(timeMode) > 8 && scatterMode) {
		setChaserMode();
	}
	if (getTime(timeMode) > 8 && frightenedMode) {
		setChaserMode();
	}
	for (int i = 0; i < speed; i++) {
		if (chaseMode)
			chaseBehaviour->chase();
		if (frightenedMode || eaten)
			frightenedBehaviour->frightened();
		if (scatterMode)
			scatterBehaviour->scatter();
	}
}

void Blinky::setChase()
{
	this->cur = 0;
	this->Tcur = 0;
	this->name = "chaser";
	this->chaseMode = true;
	this->frightenedMode = this->scatterMode = false;
}

void Blinky::setScatter()
{
	this->cur = 0;
	this->Tcur = 0;
	this->name = "scatter";
	this->scatterMode = true;
	this->frightenedMode = this->chaseMode = false;
}

void Blinky::setFrightenedMode()
{
	timeMode = clock();
	this->speed = 1;
	freePointer();
	this->frightenedBehaviour = new FrightenedWandering(this);
}

void Blinky::setScatterMode()
{
	eaten = false;
	timeMode = clock();
	this->speed = 2;
	freePointer();
	scatterBehaviour = new ScatterTopRight(this);
}

void Blinky::setChaserMode()
{
	eaten = false;
	this->speed = 2;
	timeMode = clock();
	freePointer();
	chaseBehaviour = new ChaseAggressive(this);
}

void Blinky::setEatenMode()
{
	this->name = "eaten";
	this->speed = 8;
	this->chaseMode = this->scatterMode = this->frightenedMode = false;
	eaten = true;
	freePointer();
	this->frightenedBehaviour = new FrightenedEaten(this);
}

double Blinky::getTime(time_t lastTime)
{
	clock_t now = clock();
	return (double)(now - lastTime) / CLOCKS_PER_SEC;
}

void Blinky::freePointer()
{
	if(this->chaseBehaviour!=NULL)
	delete this->chaseBehaviour;
	if (this->scatterBehaviour != NULL)
	delete this->scatterBehaviour;
	if (this->frightenedBehaviour != NULL)
	delete this->frightenedBehaviour;

	this->chaseBehaviour = NULL;
	this->scatterBehaviour = NULL;
	this->frightenedBehaviour = NULL;
}

