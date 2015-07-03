//
// Created by ZhuangTianYi on 15/7/1.
//

#include "Visualizer.h"
#include "common.h"
#include "Rectangle.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void Visualizer::show(const std::vector<Rectangle>& rectangles, State* state) const {
    double screen_width = 0;
    double screen_height = 0;
    for (int i = 0;i < RECTANGLE_NUM;i++) {
        screen_width = std::max(screen_width, rectangles[i].get_center_x() + 0.5 * rectangles[i].get_width(state->ifrotate[i]));
        screen_height = std::max(screen_height,
                                 rectangles[i].get_center_y() + 0.5 * rectangles[i].get_height(state->ifrotate[i]));
    }
    double propotion = SCREEN_WIDTH / screen_width;
    screen_width *= propotion;
    screen_height *= propotion;
    cv::Mat picture(screen_height * 1.05, screen_width * 1.05, CV_8UC3, cv::Scalar(255, 255, 255));
    for (int i = 0;i < RECTANGLE_NUM;i++) {
        double center_x = rectangles[i].get_center_x() * propotion;
        double center_y = rectangles[i].get_center_y() * propotion;
        double half_width = 0.5 * rectangles[i].get_width(state -> ifrotate[i]) * propotion;
        double half_height = 0.5 * rectangles[i].get_height(state -> ifrotate[i]) * propotion;

        cv::Point pt1(center_x - half_width, center_y + half_height);
        cv::Point pt2(center_x + half_width, center_y + half_height);
        cv::Point pt3(center_x + half_width, center_y - half_height);
        cv::Point pt4(center_x - half_width, center_y - half_height);

        cv::line(picture, pt1, pt2, cv::Scalar(0, 0, 0));
        cv::line(picture, pt2, pt3, cv::Scalar(0, 0, 0));
        cv::line(picture, pt3, pt4, cv::Scalar(0, 0, 0));
        cv::line(picture, pt4, pt1, cv::Scalar(0, 0, 0));

    }

    cv::namedWindow("Corner Block List");
    imshow("Corner Block List", picture);
    cv::waitKey(0);

}