#include <fstream>
#include <algorithm>
#include "system.h"
#include "disk.h"

System::System(int N, double displacement,double radius, double boxSize, int seed) {

        this->boxSize= boxSize;
        this->  dist = std::uniform_real_distribution<double>(0, 1);
        this->displacement=displacement;
        gen = std::mt19937(seed);
        
        int nSide = static_cast<int>(boxSize/ (2*radius));
        disks.reserve(N);

        for (int i = 0; i < nSide && disks.size() < N; ++i) {
            for (int j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(i * 2*radius, j * 2*radius, radius));
            }
        }
    }   

bool System::overlap(int i){
    Disk & d1 = disks[i];
    return std::any_of(disks.begin(), disks.end(), [&](Disk & d2) {
        return &d1 != &d2 && d1.distance(d2) < (d1.radius + d2.radius);
    }
    );
}

void System::step() {
    for (int i=0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].x;
        double oldy = disks[selected_disk].y;
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].x = oldx;
            disks[selected_disk].y = oldy;
        }
       
    }
}
void System::enforceBoundaries(Disk & disk) {
        disk.x = std::clamp(disk.x, 0.0, boxSize);
        disk.y = std::clamp(disk.y, 0.0, boxSize);
    }

    double System::uniform (double min,double max){
        std::uniform_real_distribution<double> distribution(min, max);
        return distribution(gen);
    }

void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    outFile << disks.size() << "\nComment\n";
    for (const Disk& disk : disks) {
        outFile << "A " << disk.x << " " << disk.y << " " << disk.radius << "\n";
    }
}
