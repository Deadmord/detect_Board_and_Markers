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

const char* argvCreateMarker[] = {
        "program_name - create marker",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "markers/marker0.png",
        "-d=10",
        "-id=0",
        "-ms=200",
        "-bb=1",
        "-si=true",
        nullptr   // Важно завершить argv нулевым указателем
};

const char* argvCreateBoard[] = {
        "program_name - create board",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "boards/arUcoBoard0.png",
        "-w=5",
        "-h=7",
        "-l=100",
        "-s=10",
        "-d=10",
        "-m=10",
        "-bb=1",
        "-si=true",
        nullptr   // Важно завершить argv нулевым указателем
};

const char* argvCreateBoardCharuco[] = {
        "program_name - create chArUco board",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "boards/chArUcoBoard0.png",
        "-w=5",
        "-h=7",
        "-sl=200",
        "-ml=100",
        "-d=10",
        "-m=10",
        "-bb=1",
        "-si=true",
        nullptr   // Важно завершить argv нулевым указателем
};

const char* argvMarkers[] = {
        "program_name - detect markers",   // Здесь "program_name" может быть любой строкой, она обычно является именем исполняемого файла
        "-d=10",
        "-ci=0",
        "-c=camera_params/camera_paramsUSB01.yml",
        "-l=0.036",
        "-r=true",
        "-refine=1", 
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
        "-rs=true",
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
        "-rs=true",
        "-r=true",
        nullptr   // Важно завершить argv нулевым указателем
};
int createMarker(int argc, char* argv[]);
int createBoard(int argc, char* argv[]);
int createBoardCharuco(int argc, char* argv[]);
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
        std::cout << "createMarkers" << std::endl;
        argcIntern = sizeof(argvCreateMarker) / sizeof(argvCreateMarker[0]) - 1;  // Calculate argc for the mode;
        createMarker(argcIntern, const_cast<char**>(argvCreateMarker));
        break;
    case 2:
        std::cout << "CreateBoard" << std::endl;
        argcIntern = sizeof(argvCreateBoard) / sizeof(argvCreateBoard[0]) - 1;  // Calculate argc for the mode;
        createBoard(argcIntern, const_cast<char**>(argvCreateBoard));
        break;
    case 3:
        std::cout << "CreateBoardCharuco" << std::endl;
        argcIntern = sizeof(argvCreateBoardCharuco) / sizeof(argvCreateBoardCharuco[0]) - 1;  // Calculate argc for the mode;
        createBoardCharuco(argcIntern, const_cast<char**>(argvCreateBoardCharuco));
        break;
    case 5:
        std::cout << "markers" << std::endl;
        argcIntern = sizeof(argvMarkers) / sizeof(argvMarkers[0]) - 1;  // Calculate argc for the mode;
        detectMarkers(argcIntern, const_cast<char**>(argvMarkers));
        break;
    case 6:
        std::cout << "Board" << std::endl;
        argcIntern = sizeof(argvBoardArUco) / sizeof(argvBoardArUco[0]) - 1;  // Calculate argc for the mode;
        detectBoard(argcIntern, const_cast<char**>(argvBoardArUco));
        break;
    case 7:
        std::cout << "BoardCharuco" << std::endl;
        argcIntern = sizeof(argvBoardChArUco) / sizeof(argvBoardChArUco[0]) - 1;  // Calculate argc for the mode;
        detectBoardCharuco(argcIntern, const_cast<char**>(argvBoardChArUco));
        break;
    default:
        break;
    }
    return 0;
}
