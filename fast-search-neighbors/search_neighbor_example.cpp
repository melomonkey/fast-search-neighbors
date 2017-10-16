#include <vector>
#include <random>
#include "fast_search_neighbors\fast_search_neighbors.h"
using namespace std;

void main()
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<float> unif(0.0, 1.0);

	vector<float> val_x, val_y, val_z;
	vector<int> index;

	int sample_cnt = 500000;

	// X
	for (int i = 0; i < sample_cnt; ++i)
	{
		float tmp = unif(e);

		if (val_x.size() > 0)
		{
			while (tmp == val_x.back()) tmp = unif(e);
		}

		val_x.push_back(tmp);
		index.push_back(i);
	}

	// Y
	for (int i = 0; i < sample_cnt; ++i)
	{
		float tmp = unif(e);

		if (val_y.size() > 0)
		{
			while (tmp == val_y.back()) tmp = unif(e);
		}

		val_y.push_back(tmp);
	}

	// Z
	for (int i = 0; i < sample_cnt; ++i)
	{
		float tmp = unif(e);

		if (val_z.size() > 0)
		{
			while (tmp == val_z.back()) tmp = unif(e);
		}

		val_z.push_back(tmp);
	}

	fast_search_neighbors FTS; // using the 'fast_search_neighbors' class

	// 1D example
	vector<vector<int>> list_1D;
	vector<int> label_1D;
	vector<vector<int>> neigh_list_1D;
	vector<vector<int>> neigh_list_1D_another;

	FTS.split_grid_1D_label(val_x, list_1D, label_1D, 200);

	FTS.search_neighbor_1D(list_1D, label_1D, neigh_list_1D, 1);
	FTS.search_neighbor_1D_multi_threads(list_1D, label_1D, neigh_list_1D_another, 1, 5);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


	// 2D example
	vector<vector<vector<int>>> list_2D;
	vector<vector<int>> label_2D;
	vector<vector<int>> neigh_list_2D;
	vector<vector<int>> neigh_list_2D_another;

	FTS.split_grid_2D_label(val_x, val_y, list_2D, label_2D, 20, 20);

	FTS.search_neighbor_2D(list_2D, label_2D, neigh_list_2D, 1);
	FTS.search_neighbor_2D_multi_threads(list_2D, label_2D, neigh_list_2D_another, 1, 5);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


	// 3D example
	vector<vector<vector<vector<int>>>> list_3D;
	vector<vector<int>> label_3D;
	vector<vector<int>> neigh_list_3D;
	vector<vector<int>> neigh_list_3D_another;

	FTS.split_grid_3D_label(val_x, val_y, val_z, list_3D, label_3D, 20, 20, 20);

	FTS.search_neighbor_3D(list_3D, label_3D, neigh_list_3D, 1);
	FTS.search_neighbor_3D_multi_threads(list_3D, label_3D, neigh_list_3D_another, 1, 5);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


	system("pause");
}
