//
// Created by ZhuangTianYi on 15/7/1.
//

#include "Visualizer.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void Visualizer::show(const std::vector<Rectangle> &rects) {
    cv::Mat picture(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

    for (const auto &rect : rects) {
        cv::Point pt1(rect.get_center_x() - 0.5 * rect.get_width(0), rect.get_center_y() + rect.get_height(0));
        cv::Point pt2(rect.get_center_x() + 0.5 * rect.get_width(0), rect.get_center_y() + rect.get_height(0));
        cv::Point pt3(rect.get_center_x() + 0.5 * rect.get_width(0), rect.get_center_y() - rect.get_height(0));
        cv::Point pt4(rect.get_center_x() - 0.5 * rect.get_width(0), rect.get_center_y() - rect.get_height(0));

        cv::line(picture, pt1, pt2, cv::Scalar(0, 0, 0));
        cv::line(picture, pt2, pt3, cv::Scalar(0, 0, 0));
        cv::line(picture, pt3, pt4, cv::Scalar(0, 0, 0));
        cv::line(picture, pt4, pt1, cv::Scalar(0, 0, 0));
    }

    cv::namedWindow("Corner Block List");
    imshow("Corner Block List", picture);
    cv::waitKey(0);

}