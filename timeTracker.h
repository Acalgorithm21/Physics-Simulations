#pragma once

#include <chrono>
#include <vector>
#include "SimulationReport.h"
#include "ball.h"
#include <thread>
#include <atomic>

class timeTracker {
private:

    std::vector<Ball>& balls;//thread safety
    SimulationReport& report;

    std::atomic<bool> running;

    int startTime = 0;
    int endTime;

    int interval;

    std::thread thread;

public:
    timeTracker(int n, std::vector<Ball>& ballsRef, SimulationReport& reportRef)
        : startTime(0), endTime(0), report(reportRef), balls(ballsRef),running(false) ,interval(n) {};

    ~timeTracker() {
        stop();
    }

    //This method starts the clock an takes a snapshot of the ball every n seconds, n that is passed in to the
    //constructor.
    void start() {
        if (running) {
            return;
        }

        running = true;

        thread = std::thread([this](){

            int seconds = 0;
            while (running) {

                std::this_thread::sleep_for(std::chrono::seconds(1));
                seconds++;

                if ((seconds % interval) == 0) {
                    report.snapShot(balls, seconds);
                }

            }
            endTime = seconds;
        });
    }

    //This method stops the clock.
    void stop() {

        running = false;

        if (thread.joinable()) {
            thread.join();
        }

    };

    //This method resets the clock starting point to 0.
    void reset() {

        endTime = 0;

    };

};