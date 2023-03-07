#include <SDL.h>

#include "cod/time/timer.h"

Timer::Timer()
{
    this->start_ticks = 0;
    this->paused_ticks = 0;

    this->paused = false;
    this->started = false;
}

void Timer::start()
{
    this->started = true;
    this->paused = false;

    this->start_ticks = SDL_GetTicks();
    this->paused_ticks = 0;
}

void Timer::stop()
{
    this->started = false;
    this->paused = false;

    this->start_ticks = 0;
    this->paused_ticks = 0;
}

void Timer::pause()
{
    if (this->started && !this->paused)
    {
        this->paused = true;

        this->paused_ticks = SDL_GetTicks() - this->start_ticks;
        this->start_ticks = 0;
    }
}

void Timer::unpause()
{
    if (this->started && this->paused)
    {
        this->paused = true;

        this->start_ticks = SDL_GetTicks() - this->paused_ticks;
        this->paused_ticks = 0;
    }
}

uint32_t Timer::get_ticks()
{
    uint32_t time = 0;
    if (!this->started) return time;
    if (this->paused) return this->paused_ticks;
    else return SDL_GetTicks() - this->start_ticks;
}

bool Timer::is_started()
{
	//Timer is running and paused or unpaused
    return this->started;
}

bool Timer::is_paused()
{
	//Timer is running and paused
    return this->paused && this->started;
}