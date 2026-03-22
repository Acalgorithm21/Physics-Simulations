#include <fstream>
#include "ball.h"

class Report {
public:
    std::ofstream reportFile;

    Report() : reportFile("positionReport.csv"){
        if (!reportFile.is_open()) {
            throw std::runtime_error("Could not open report file");
        }
    }

    ~Report() {
        if (reportFile.is_open()) {
            reportFile.close();
        }
    }

    //This function takes the current input
    void snapShot(const std::vector<Ball>& balls, const int time) {

        for (int i = 0; i < balls.size(); i++) {

            Ball ball = balls.at(i);
            sf::Vector2f pos = ball.ball.getPosition();

            writeData(ball, pos, time);
        }

    };

private:
    //This function writes the data to the csv file. A helper function of snapshot.
    void writeData(const Ball& ball, sf::Vector2f pos, const int time) {

        if (!reportFile.is_open()) {
            throw std::runtime_error("Error, file is not open.");
        }

        reportFile << time << " ," << "ball " << " ," << pos.x << " ," << pos.y << std::endl;

    };

};