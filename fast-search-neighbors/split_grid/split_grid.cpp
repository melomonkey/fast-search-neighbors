#include "split_grid.h"

void split_grid::split_1D(vector<float> val, vector<vector<int>> & list, int split_bins = 8)
{
	float mx, mn;
	mx = val[0];
	mn = val[0];

	for (int i = 0; i < val.size(); ++i)
	{
		if (val[i] > mx) mx = val[i];
		if (val[i] < mn) mn = val[i];
	}

	float interval = (mx - mn) / split_bins;

	list.resize(split_bins);
	for (int i = 0; i < split_bins; ++i) list[i].reserve(val.size() / split_bins);

	for (int i = 0; i < val.size(); ++i)
	{
		int loc = (val[i] - mn) / (interval * 1.0);

		if (loc > split_bins - 1) loc = split_bins - 1;
		if (loc < 0) loc = 0;

		list[loc].push_back(i);
	}
}

void split_grid::split_1D_label(vector<float> val, vector<vector<int>> & list, vector<int> & label, int split_bins = 8)
{
	float mx, mn;
	mx = val[0];
	mn = val[0];

	for (int i = 0; i < val.size(); ++i)
	{
		if (val[i] > mx) mx = val[i];
		if (val[i] < mn) mn = val[i];
	}

	float interval = (mx - mn) / split_bins;

	list.resize(split_bins);
	for (int i = 0; i < split_bins; ++i) list[i].reserve(val.size() / split_bins);

	label.resize(val.size());

	for (int i = 0; i < val.size(); ++i)
	{
		int loc = (val[i] - mn) / (interval * 1.0);

		if (loc > split_bins - 1) loc = split_bins - 1;
		if (loc < 0) loc = 0;

		list[loc].push_back(i);

		label[i] = loc;
	}
}

void split_grid::split_grid_2D(vector<float> val_x, vector<float> val_y, vector<vector<vector<int>>> grid_list, int split_bins_x = 8, int split_bins_y = 8)
{
	float mx_X, mn_X;
	mx_X = val_x[0];
	mn_X = val_x[0];

	for (int i = 0; i < val_x.size(); ++i)
	{
		if (val_x[i] > mx_X) mx_X = val_x[i];
		if (val_x[i] < mn_X) mn_X = val_x[i];
	}

	float interval_X = (mx_X - mn_X) / split_bins_x;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	float mx_Y, mn_Y;
	mx_Y = val_y[0];
	mn_Y = val_y[0];

	for (int i = 0; i < val_y.size(); ++i)
	{
		if (val_y[i] > mx_Y) mx_Y = val_y[i];
		if (val_y[i] < mn_Y) mn_Y = val_y[i];
	}

	float interval_Y = (mx_Y - mn_Y) / split_bins_y;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	grid_list.resize(split_bins_x);
	for (int i = 0; i < split_bins_x; ++i) grid_list[i].resize(split_bins_y);
	for (int i = 0; i < split_bins_x; ++i)
	{
		for (int j = 0; j < split_bins_y; ++j) grid_list[i][j].reserve(val_x.size() / (split_bins_x * split_bins_y));
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	for (int i = 0; i < val_x.size(); ++i)
	{
		int loc_X = (val_x[i] - mn_X) / (interval_X * 1.0);

		if (loc_X > split_bins_x - 1) loc_X = split_bins_x - 1;
		if (loc_X < 0) loc_X = 0;

		/* * * * * * * * * * * * * * * * * */

		int loc_Y = (val_y[i] - mn_Y) / (interval_Y * 1.0);

		if (loc_Y > split_bins_y - 1) loc_Y = split_bins_y - 1;
		if (loc_Y < 0) loc_Y = 0;

		/* * * * * * * * * * * * * * * * * */

		grid_list[loc_X][loc_Y].push_back(i);
	}
}

void split_grid::split_grid_2D_label(vector<float> val_x, vector<float> val_y, vector<vector<vector<int>>> & grid_list, vector<vector<int>> & label, int split_bins_x = 8, int split_bins_y = 8)
{
	float mx_X, mn_X;
	mx_X = val_x[0];
	mn_X = val_x[0];

	for (int i = 0; i < val_x.size(); ++i)
	{
		if (val_x[i] > mx_X) mx_X = val_x[i];
		if (val_x[i] < mn_X) mn_X = val_x[i];
	}

	float interval_X = (mx_X - mn_X) / split_bins_x;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	float mx_Y, mn_Y;
	mx_Y = val_y[0];
	mn_Y = val_y[0];

	for (int i = 0; i < val_y.size(); ++i)
	{
		if (val_y[i] > mx_Y) mx_Y = val_y[i];
		if (val_y[i] < mn_Y) mn_Y = val_y[i];
	}

	float interval_Y = (mx_Y - mn_Y) / split_bins_y;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	grid_list.resize(split_bins_x);
	for (int i = 0; i < split_bins_x; ++i) grid_list[i].resize(split_bins_y);
	for (int i = 0; i < split_bins_x; ++i)
	{
		for (int j = 0; j < split_bins_y; ++j) grid_list[i][j].reserve(val_x.size() / (split_bins_x * split_bins_y));
	}

	label.resize(val_x.size());
	for (int i = 0; i < label.size(); ++i)
	{
		vector<int> tmp; tmp.resize(2);
		label[i] = tmp;
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	for (int i = 0; i < val_x.size(); ++i)
	{
		int loc_X = (val_x[i] - mn_X) / (interval_X * 1.0);

		if (loc_X > split_bins_x - 1) loc_X = split_bins_x - 1;
		if (loc_X < 0) loc_X = 0;

		/* * * * * * * * * * * * * * * * * */

		int loc_Y = (val_y[i] - mn_Y) / (interval_Y * 1.0);

		if (loc_Y > split_bins_y - 1) loc_Y = split_bins_y - 1;
		if (loc_Y < 0) loc_Y = 0;

		/* * * * * * * * * * * * * * * * * */

		grid_list[loc_X][loc_Y].push_back(i);

		label[i][0] = loc_X; label[i][1] = loc_Y;
	}
}

void split_grid::split_grid_3D(vector<float> val_x, vector<float> val_y, vector<float> val_z, vector<vector<vector<vector<int>>>> & grid_list, int split_bins_x = 8, int split_bins_y = 8, int split_bins_z = 8)
{
	float mx_X, mn_X;
	mx_X = val_x[0];
	mn_X = val_x[0];

	for (int i = 0; i < val_x.size(); ++i)
	{
		if (val_x[i] > mx_X) mx_X = val_x[i];
		if (val_x[i] < mn_X) mn_X = val_x[i];
	}

	float interval_X = (mx_X - mn_X) / split_bins_x;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	float mx_Y, mn_Y;
	mx_Y = val_y[0];
	mn_Y = val_y[0];

	for (int i = 0; i < val_y.size(); ++i)
	{
		if (val_y[i] > mx_Y) mx_Y = val_y[i];
		if (val_y[i] < mn_Y) mn_Y = val_y[i];
	}

	float interval_Y = (mx_Y - mn_Y) / split_bins_y;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	float mx_Z, mn_Z;
	mx_Z = val_z[0];
	mn_Z = val_z[0];

	for (int i = 0; i < val_z.size(); ++i)
	{
		if (val_z[i] > mx_Z) mx_Z = val_z[i];
		if (val_z[i] < mn_Z) mn_Z = val_z[i];
	}

	float interval_Z = (mx_Z - mn_Z) / split_bins_z;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	grid_list.resize(split_bins_x);
	for (int i = 0; i < split_bins_x; ++i) grid_list[i].resize(split_bins_y);

	for (int i = 0; i < split_bins_x; ++i)
	{
		for (int j = 0; j < split_bins_y; ++j) grid_list[i][j].resize(split_bins_z);
	}

	for (int i = 0; i < split_bins_x; ++i)
	{
		for (int j = 0; j < split_bins_y; ++j)
		{
			for (int k = 0; k < split_bins_z; ++k)
			{
				grid_list[i][j][k].reserve(val_x.size() / (split_bins_x * split_bins_y * split_bins_z));
			}
		}
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	for (int i = 0; i < val_x.size(); ++i)
	{
		int loc_X = (val_x[i] - mn_X) / (interval_X * 1.0);

		if (loc_X > split_bins_x - 1) loc_X = split_bins_x - 1;
		if (loc_X < 0) loc_X = 0;

		/* * * * * * * * * * * * * * * * * */

		int loc_Y = (val_y[i] - mn_Y) / (interval_Y * 1.0);

		if (loc_Y > split_bins_y - 1) loc_Y = split_bins_y - 1;
		if (loc_Y < 0) loc_Y = 0;

		/* * * * * * * * * * * * * * * * * */

		int loc_Z = (val_z[i] - mn_Z) / (interval_Z * 1.0);

		if (loc_Z > split_bins_z - 1) loc_Z = split_bins_z - 1;
		if (loc_Z < 0) loc_Z = 0;

		/* * * * * * * * * * * * * * * * * */

		grid_list[loc_X][loc_Y][loc_Z].push_back(i);
	}
}

void split_grid::split_grid_3D_label(vector<float> val_x, vector<float> val_y, vector<float> val_z, vector<vector<vector<vector<int>>>> & grid_list, vector<vector<int>> & label, int split_bins_x = 8, int split_bins_y = 8, int split_bins_z = 8)
{
	float mx_X, mn_X;
	mx_X = val_x[0];
	mn_X = val_x[0];

	for (int i = 0; i < val_x.size(); ++i)
	{
		if (val_x[i] > mx_X) mx_X = val_x[i];
		if (val_x[i] < mn_X) mn_X = val_x[i];
	}

	float interval_X = (mx_X - mn_X) / split_bins_x;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	float mx_Y, mn_Y;
	mx_Y = val_y[0];
	mn_Y = val_y[0];

	for (int i = 0; i < val_y.size(); ++i)
	{
		if (val_y[i] > mx_Y) mx_Y = val_y[i];
		if (val_y[i] < mn_Y) mn_Y = val_y[i];
	}

	float interval_Y = (mx_Y - mn_Y) / split_bins_y;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	float mx_Z, mn_Z;
	mx_Z = val_z[0];
	mn_Z = val_z[0];

	for (int i = 0; i < val_z.size(); ++i)
	{
		if (val_z[i] > mx_Z) mx_Z = val_z[i];
		if (val_z[i] < mn_Z) mn_Z = val_z[i];
	}

	float interval_Z = (mx_Z - mn_Z) / split_bins_z;

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	grid_list.resize(split_bins_x);
	for (int i = 0; i < split_bins_x; ++i) grid_list[i].resize(split_bins_y);

	for (int i = 0; i < split_bins_x; ++i)
	{
		for (int j = 0; j < split_bins_y; ++j) grid_list[i][j].resize(split_bins_z);
	}

	for (int i = 0; i < split_bins_x; ++i)
	{
		for (int j = 0; j < split_bins_y; ++j)
		{
			for (int k = 0; k < split_bins_z; ++k)
			{
				grid_list[i][j][k].reserve(val_x.size() / (split_bins_x * split_bins_y * split_bins_z));
			}
		}
	}

	label.resize(val_x.size());
	for (int i = 0; i < label.size(); ++i)
	{
		vector<int> tmp; tmp.resize(3);
		label[i] = tmp;
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	for (int i = 0; i < val_x.size(); ++i)
	{
		int loc_X = (val_x[i] - mn_X) / (interval_X * 1.0);

		if (loc_X > split_bins_x - 1) loc_X = split_bins_x - 1;
		if (loc_X < 0) loc_X = 0;

		/* * * * * * * * * * * * * * * * * */

		int loc_Y = (val_y[i] - mn_Y) / (interval_Y * 1.0);

		if (loc_Y > split_bins_y - 1) loc_Y = split_bins_y - 1;
		if (loc_Y < 0) loc_Y = 0;

		/* * * * * * * * * * * * * * * * * */

		int loc_Z = (val_z[i] - mn_Z) / (interval_Z * 1.0);

		if (loc_Z > split_bins_z - 1) loc_Z = split_bins_z - 1;
		if (loc_Z < 0) loc_Z = 0;

		/* * * * * * * * * * * * * * * * * */

		grid_list[loc_X][loc_Y][loc_Z].push_back(i);

		label[i][0] = loc_X; label[i][1] = loc_Y; label[i][2] = loc_Z;
	}
}