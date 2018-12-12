#define _CRT_SECURE_NO_WARNINGS

#ifndef ROBOT_LOCATOR_H_
#define ROBOT_LOCATOR_H_

#define STARTUP_INITIAL     0
#define BEFORE_DUNE         1
#define BEFORE_GRASSLAND    2

#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/features/normal_3d.h>
#include <Eigen/Dense>
#include "act_d435.h"

using namespace Eigen;

class RobotLocator
{
public:
    RobotLocator();
	RobotLocator(const RobotLocator&) = delete;
	RobotLocator& operator=(const RobotLocator&) = delete;
	~RobotLocator();

    pPointCloud setInputCloud(pPointCloud cloud);

    void preProcess();

    void locateBeforeDune();

    pPointCloud removeHorizontalPlanes(pPointCloud cloud);

    bool isStoped(void);

    inline pPointCloud getSrcCloud(void) { return srcCloud; }
    inline pPointCloud getFilteredCloud(void) { return filteredCloud; }

public:
    unsigned int status;

private:
    pPointCloud		 srcCloud;
	pPointCloud      backgroundCloud;
	pPointCloud      filteredCloud;
    pPointCloud      verticalCloud;
	pPointCloud      tmpCloud;
	pPointCloud      dstCloud;

    pcl::visualization::CloudViewer srcViewer;

    pcl::PointIndices::Ptr indices;
};

#endif
