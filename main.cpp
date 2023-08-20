#include <opencv2/aruco/charuco.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const double FRAME_WIDTH = 1280.0f;
const double FRAME_HEIGHT = 720.0f;

namespace {
    const char* about = "A tutorial code on detection of markers, ArUco board and chArUco board";
    const char* keys = "{c        |       | Put value of c=1 to detect Markers;\nc=2 to detect Board;\nc=3 to detect charuco board}";
}

const char* argvMarkers[] = {
        "program_name - detect markers",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "-d=10",
        "-ci=0",
        "-c=camera_params/camera_paramsUSB01.yml",
        "-l=0.036",
        "-r=true",
        "-refine=0", 
        nullptr   // Важно завершить argv нулевым указателем
};

const char* argvBoardArUco[] = {
        "program_name - detect arUco board",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "-w=5",
        "-h=7",
        "-l=100",
        "-s=10",
        "-d=10",
        "-ci=0",
        "-c=camera_params/camera_paramsUSB01.yml",
        "-l=0.036",
        "-r=true",
        nullptr   // Важно завершить argv нулевым указателем
};

const char* argvBoardChArUco[] = {
        "program_name - detect chArUco board",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "-w=5",
        "-h=7",
        "-sl=0.04",
        "-ml=0.02",
        "-d=10",
        "-ci=0",
        "-c=camera_params/camera_paramsUSB01.yml",
        "-l=0.036",
        "-r=true",
        nullptr   // Важно завершить argv нулевым указателем
};

int detectMarkers(int argc, char* argv[]);
int detectBoard(int argc, char* argv[]);
int detectBoardCharuco(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about(about);
    if (argc < 2) {
        parser.printMessage();
        return 0;
    }
    int choose = parser.get<int>("c");
    int argcIntern;
    switch (choose) {
    case 1:
        argcIntern = sizeof(argvMarkers) / sizeof(argvMarkers[0]) - 1;  // Calculate argc for the mode;
        detectMarkers(argcIntern, const_cast<char**>(argvMarkers));
        std::cout << "markers" << std::endl;
        break;
    case 2:
        argcIntern = sizeof(argvBoardArUco) / sizeof(argvBoardArUco[0]) - 1;  // Calculate argc for the mode;
        detectBoard(argcIntern, const_cast<char**>(argvBoardArUco));
        std::cout << "Board" << std::endl;
        break;
    case 3:
        argcIntern = sizeof(argvBoardChArUco) / sizeof(argvBoardChArUco[0]) - 1;  // Calculate argc for the mode;
        detectBoardCharuco(argcIntern, const_cast<char**>(argvBoardChArUco));
        std::cout << "BoardCharuco" << std::endl;
        break;
    default:
        break;
    }
    return 0;
}
