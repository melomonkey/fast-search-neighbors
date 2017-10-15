#pragma once

#ifndef SPLIT_GRID_H_
#define SPLIT_GRID_H_

#include <fstream>
#include <string>
#include <vector>
using namespace std;

class split_grid
{
public:
	void split_1D(vector<float> val, vector<vector<int>> & list, int split_bins);
	void split_1D_label(vector<float> val, vector<vector<int>> & list, vector<int> & label, int split_bins);
	void split_grid_2D(vector<float> val_x, vector<float> val_y, vector<vector<vector<int>>> grid_list, int split_bins_x, int split_bins_y);
	void split_grid_2D_label(vector<float> val_x, vector<float> val_y, vector<vector<vector<int>>> & grid_list, vector<vector<int>> & label, int split_bins_x, int split_bins_y);
	void split_grid_3D(vector<float> val_x, vector<float> val_y, vector<float> val_z, vector<vector<vector<vector<int>>>> & grid_list, int split_bins_x, int split_bins_y, int split_bins_z);
	void split_grid_3D_label(vector<float> val_x, vector<float> val_y, vector<float> val_z, vector<vector<vector<vector<int>>>> & grid_list, vector<vector<int>> & label, int split_bins_x, int split_bins_y, int split_bins_z);
}; 


#endif